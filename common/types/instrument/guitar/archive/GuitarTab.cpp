package com.ariasproj.common.types.instrument.guitar;

import java.util.ArrayList;

import com.ariasproj.common.exceptions.MeasureBeatsExceededException;
import com.ariasproj.common.types.note.NoteValue;
import com.ariasproj.common.types.note.NoteValueType;

public class GuitarTab {

	private ArrayList<GuitarTabMeasure> tab;
	private int beats_per_measure;	
	@SuppressWarnings("unused")
  private float beats_left;
	private NoteValue beat_note;
	private byte guitar_strings;
	private int measure_index;
	
	/**
	 * Constructor
	 * 
	 * @param beats_per_measure number of beats in the measure, only whole beats are supported.
	 * @param beat_note which note gets the beat
	 * @param guitar_strings number of guitar strings in the tabs
	 */
	public GuitarTab(int beats_per_measure, NoteValue beat_note, byte guitar_strings){

	  this.beats_per_measure = beats_per_measure;
		this.tab = new ArrayList<GuitarTabMeasure>();
	  this.beats_left = (float) beats_per_measure;
	  this.beat_note = beat_note;
	  this.guitar_strings = guitar_strings;
	  this.measure_index = 0;
	}
	
	/**
	 * Constructor
	 * 
	 * @param num_measures number of measures to initialize the tabs to.
	 * @param beats_per_measure number of beats in the measure, only whole beats are supported.
	 * @param beat_note which note gets the beat
	 * @param guitar_strings number of guitar strings in the tabs
	 */
	public GuitarTab(int num_measures, int beats_per_measure, NoteValue beat_note, byte guitar_strings){

	  this.beats_per_measure = beats_per_measure;
		this.tab = new ArrayList<GuitarTabMeasure>(num_measures);
	  this.beats_left = (float) beats_per_measure;
	  this.beat_note = beat_note;
	  this.guitar_strings = guitar_strings;
	  this.measure_index = 0;
	}
  
  /**
   * Gets the number of tab strings in the intialized guitar tab object
   * @return <Class>Byte</Class> object which represents the number of strings 
   * for the initialized <Class>Guitar</Class> object
   */
	public byte getNumTabStrings(){
		return this.guitar_strings;
	}

	/**
	 * Returns the portion of the time signature that represents which note gets 
	 * the beat.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return what note gets the beat
	 */
  public NoteValue getBeatNote(){ return this.beat_note; }

	/**
	 * Returns the portion of the time signature that represents how many beats 
	 * per measure.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return how many beats per measure
	 */
  public int getBeatsPerMeasure(){ return this.beats_per_measure; }


	/**
	 * Returns the portion of the time signature that represents how many beats 
	 * per measure.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return how many beats per measure
	 */
  public ArrayList<GuitarTabMeasure> getMeasures(){ return this.tab; }


	/**
	 * Returns the portion of the time signature that represents how many beats 
	 * per measure.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return how many beats per measure
	 */
  public ArrayList<GuitarNote> getNotes(){ 
    boolean list_changed = false;
    
  	ArrayList<GuitarNote> notes = new ArrayList<GuitarNote>();
  	for (GuitarTabMeasure measure : this.tab){
  		list_changed = notes.addAll(measure.getNotes());
  		if (!list_changed){
  			System.err.println("Error - list has changed since this call");
  		}
  	}
  	return notes; 
  	
  }
	
	/**
	 * Adds a <Class>GuitarNote</Class> to the tab set
	 * <p>
	 * Creates a new measure if the note exceeds the remaining beats in the measure
	 * @param note note to add
	 * @throws MeasureBeatsExceededException
	 */
	public void addNote(GuitarNote note) throws MeasureBeatsExceededException{
		
		if (this.tab.size() < (this.measure_index + 1)){
			this.tab.add(new GuitarTabMeasure(this.beats_per_measure,this.beat_note,this.guitar_strings));
		}
		
		try{
			tab.get(this.measure_index).addNote(note);
		}
		catch (MeasureBeatsExceededException e){
			@SuppressWarnings("unused")
      float exceeded_beats = e.getExceededBeats();

			//split the note in two, add remaining to current measure and rest to the next measure.???

			// if the note has exceeded, create a new index with the remaining number of beats.
			throw new MeasureBeatsExceededException();
		}
	}
	
	public void incrementTabIndex()
	{
	  this.measure_index += 1;
	}
	
	/**
	 * Gets a string representation of the class
	 * @return string representation of the class
	 */
	public String toString(){
		String tabString = "";
  	
    for(int string_index = this.guitar_strings - 1; 
    		string_index >= 0; 
    		string_index --){
		  for (GuitarTabMeasure t : tab){
			  tabString += t.guitarStringToString(string_index);
		  }
    }
		return tabString;
	}
	
}
