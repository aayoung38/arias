/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common;

import java.util.ArrayList;
import java.util.Random;

import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.exceptions.MeasureBeatsExceededException;
import com.ariasproj.common.exceptions.NoteNotInScaleException;
import com.ariasproj.common.types.instrument.guitar.GuitarNote;
import com.ariasproj.common.types.instrument.guitar.GuitarScale;
import com.ariasproj.common.types.instrument.guitar.GuitarTab;
import com.ariasproj.common.types.note.NoteValue;

public class GuitarTabGenerator {

	private static final int octave_threshold = 1;
  private static final int max_reference_note_fret = 17;
	
  private int beats_per_measure;
  private NoteValue beat_note;
	private int num_random_measures;
	
  private GuitarNote lowest_note;
  private GuitarNote reference_note;
  
  private GuitarScale guitar;
  
  // List of strings tabs which has an array of measures
  //private ArrayList<ArrayList<ArrayList<String>>> tab_notes;
  
  private ArrayList<GuitarNote> unique_notes;
  private GuitarTab measure_notes;
  //private LinkedList<GuitarNote> notes;
  
  /**
	 * Constructor for the <Class>Guitar_Tab_Generator</Class> class.
	 * 
	 * @param manager
	 *          scale manager containing the key to initialize the \
	 *          <Class>Scale_Guitar</Class> in.
	 * @param beats_per_measure
	 * 					how many beats per measure to initialize the time signature in.
	 * @param beat_note
	 * 					what note gets the beats to initialize the time signature in.
	 * 
	 */
  public GuitarTabGenerator(GuitarScale guitar, int beats_per_measure, NoteValue beat_note){
    this.beats_per_measure = beats_per_measure;
    this.beat_note = beat_note;
    this.guitar = guitar;
  	this.num_random_measures = 0;
  	this.reference_note = new GuitarNote();
    
    this.measure_notes = new GuitarTab(beats_per_measure, beat_note, guitar.getNumStrings());
    this.unique_notes = new ArrayList<GuitarNote>();
 
  }
 
  /**
   * Determines if the two given notes have acceptable intervals between eachother
   * <p>
   * An acceptable interval between two notes is one that is not dissonent and 
   * will typically sound good if played consecutively. 
   * @param note_1 first note to compare
   * @param note_2 second note to compare
   * @return True if the notes are acceptable to play one right after another or
   * False otherwise.
   */
  private boolean notesHaveAllowableIntervals(GuitarNote note_1, GuitarNote note_2){
  	try{
  		byte note_1_interval;
  		byte note_2_interval;
		try {
			note_1_interval = this.guitar.getInterval(note_1);
	  		note_2_interval = this.guitar.getInterval(note_2);
		} catch (InvalidNoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			note_1_interval =0;
	  		note_2_interval = 0;
		}
  		
  	  return !((note_1_interval == 4 && note_2_interval == 7) ||
  			  		 (note_1_interval == 7 && note_2_interval == 4) ||
  			  		 (note_1_interval == 1 && note_2_interval == 7) ||
  			  		 (note_1_interval == 7 && note_2_interval == 1));
  			
  		
  	}catch (NoteNotInScaleException e){
  		System.err.println("Error - One of the notes not in the initialized interval:\n"+note_1+"\n"+note_2);
  		return false;
  	}
  }
  
	/**
	 * Discriminator for a generated note.
	 * 
	 * @param random_note
	 * @return True if the note is considered acceptable for the tabs generated 
	 * and False otherwise.
	 */
	private boolean noteAcceptable(GuitarNote random_note){
		
		boolean octave_difference_acceptable = 
			this.guitar.getNumberOctaves(this.reference_note, random_note) <= 
      octave_threshold;
      
    boolean initial_reference_note_acceptable =
    	this.unique_notes.size() != 0 || 
      (this.reference_note.getFretNumber() <= max_reference_note_fret);
		
    boolean notes_in_allowable_interval_difference =
      notesHaveAllowableIntervals(random_note, this.reference_note);
    
    boolean notes_have_allowable_fret_difference = 
    	Math.abs(this.reference_note.getFretNumber() - random_note.getFretNumber()) <= 5 ||
    	this.reference_note.getFretNumber() == 0;
    
		return octave_difference_acceptable && 
					 initial_reference_note_acceptable && 
					 notes_in_allowable_interval_difference && 
					 notes_have_allowable_fret_difference;
	}
	
  /**
   * Gets a random tab note in the initialized key. 
   * <p>
   * This routine runs a discrimination algorithm to determine the initialized
   * note for the generated tabs.
   * @return <Class>GuitarNote</Class> in the initialized key. 
   */
  private GuitarNote getRandomTabNote(float beats_left){

  	GuitarNote random_note = new GuitarNote();
  	
    random_note.selectRestOrNote();
    
    // if the note generated is a rest the do not bother processing it.
    if (!random_note.isRest()){
    	
    	/* keep generating random notes until one is found within 2 octaves of the 
  	   lowest note and that the reference note is within the maximum reference 
  	   note fret. */
    	
    	do{
    		random_note = this.guitar.getRandomNote();
    		if (this.unique_notes.size() == 0){
    			this.lowest_note = random_note;
    			this.reference_note = random_note;
    		}
    	}
    	// While note is not acceptable
    	while(!noteAcceptable(random_note));
  	
    	random_note = this.guitar.getClosestNote(this.reference_note, random_note);
    
    	// set the reference note to the last generated note.
    	this.reference_note = random_note;
  	
    	if (this.guitar.referenceIsLower(this.lowest_note, this.reference_note))
    		this.lowest_note = this.reference_note;
  	
    	// note was not found. Add to list of unique notes.
    	this.unique_notes.add(random_note);
    }

    //System.out.println(random_note);
    random_note.setRandomBeat(beats_left);
  	return random_note;
  
  }

	/**
	 * Generates a tab report for one measure in human readable format for one measure.
	 * <p>
	 * Each line in the tab report represents a string. The lowest line represents
	 * the low E, and the highest represent the high E.
	 */
  private void generateRandomTabMeasure(int measure_index){
  	GuitarNote note;
  	
  	// Generate the tabs for each beat in the measure.
  	for (int beats = 0; beats < beats_per_measure; beats += note.getValue().getBeats())
  	{
  		
    	note = getRandomTabNote(beats_per_measure - beats);
    	
    	if (note.isRest())
    	{
    		
    		if (reference_note.getStringNumber() == 
    				reference_note.getNullStringNumber())
    		  
    			note.setStringNumber(0);
    	
    		else
    		  
    			note.setStringNumber(reference_note.getStringNumber());
    	}

	    try{
	    	
	      measure_notes.addNote(note);
	      
	    }catch (MeasureBeatsExceededException e){
	    	
	      System.err.println("Measure values exceeded max!");
	    }
  	}
  	//measure_notes.incrementTabIndex();
  }

	/**
	 * Generates a tab report in human readable format.ets the number of octaves
	 * in the given distance.
	 * <p>
	 * Each line in the tab report represents a string. The lowest line represents
	 * the low E, and the highest represent the high E.
	 */
  public void generateRandomTabReport(){
  	Random generator = new Random();
  
  	// *** This is incorrect - this should be between 1 - N depending on how 
  	// long the riff is desired to be 
  	
  	num_random_measures = generator.nextInt(4)+1;
  	
  	measure_notes = 
  		new GuitarTab(num_random_measures,
  								  beats_per_measure,
  								  beat_note,
  								  guitar.getNumStrings());
  	
  	for(int i=0; i < num_random_measures; i++)
  	{
  		generateRandomTabMeasure(i);
  	}
  }

	/**
	 * Generates a tab report in human readable format.
	 * <p>
	 * Each line in the tab report represents a string. The lowest line represents
	 * the low E, and the highest represent the high E.
	 */
  public void generateRandomTabReport(int num_measures){
  	num_random_measures = num_measures;  	
  	
  	measure_notes = 
    		new GuitarTab(num_random_measures,
					  beats_per_measure,
					  beat_note,
					  guitar.getNumStrings());
  	
  	for(int i=0; i < num_random_measures; i++)
  	{  	
  		generateRandomTabMeasure(i);
  	}

  }

  /**
   * 
   * @param measure_index
   * @return
   */
  public GuitarTab getTabs(){ return this.measure_notes; }
  
  /**
   * Gets the number of tab measured generated.
   * <p>
   * Note that if generateRandomTabReport has been called then this function
   * will return the default value.
   * 
   * @return number of random measures
   * 
   */
  public int getNumberMeasures(){ return this.num_random_measures;}
  
	/**
	 * Generates a tab report in human readable format.
	 * <p>
	 * Each line in the tab report represents a string. The lowest line represents
	 * the low E, and the highest represent the high E.
	 */
  public String toString()
  {
    return this.measure_notes.toString();   
  }
  
  
  
}
