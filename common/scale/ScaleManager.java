/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common;

import java.util.LinkedList;
import java.util.Random;

import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.types.note.NoteLetter;
import com.ariasproj.common.types.note.NoteLetterType;

public abstract class ScaleManager {
	
  protected NoteLetter scale;
  protected static final int SCALE_NOTES = 8;
  protected int [] halfStepsMap;
 
  /**
   * Constructor for the Scale_Manager class
   *
   * @param  scale root note for the scale to initialize the class in
   * <p>
   * By default the class uses sharps unless the root note specified is a
   * flat note.
   *
   */
  protected ScaleManager(NoteLetterType scale){ 
	  this.scale = new NoteLetter(scale); 
	  halfStepsMap = new int[SCALE_NOTES];
  }

  /**
   * Constructor for the Scale_Manager class
   *
   * @param  scale root note for the scale to initialize the class in
   * <p>
   * By default the class uses sharps unless the root note specified is a
   * flat note.
   * @param  use_flats boolean that when true uses represents notes in terms 
   *         of flats rather than sharps.
   * @throws InvalidNoteException 
   */
  protected ScaleManager(NoteLetter scale, boolean use_flats) throws InvalidNoteException
  {
  	
    //this.note_utilities = new NoteLetter(scale, use_flats);
	  this.scale = scale;
  }
  
  /**
   * Computes the number of half steps from the root given the interval from 
   * the root.
   *
   * @param  interval a number between (1-8) which represents the interval of 
   *         the root note. If the number is greater than 8 it is assumed to be
   *         in a higher octave.
   * @return a number in half steps from the root.
   */
  public int toHalfSteps(int interval) { 
		
      return interval < 9 && interval > 0 ? halfStepsMap[interval-1] : 0; }
  
  /**
   * Gets a chord in the key of the initialized root note using the interval as 
   * the distance from the root. 
   *
   * @param  interval a number between (1-8) which represents the interval of 
   *         the root note. If the number is greater than 8 it is assumed to be
   *         in a higher octave.
   * @return a chord from the given interval of the root in the scale of the 
   *         initialized root note as a string.
   * @throws InvalidNoteException 
   * @see    String
   */
  public String getChord(int interval) throws InvalidNoteException
  {
	
    int scale_interval = interval % SCALE_NOTES; 
    String chord = "";
    
    String computed_note = 
        this.scale.numberToNote( toHalfSteps(scale_interval));
	
    switch(interval){
	    case 2: case 3: case 6: 
	      chord = "min";
	      break;
	    case 7: 
	      chord = "dim";
	      break;
	    default:
	      break;
    }
    return computed_note + chord;
	
  }

  /**
   * Gets the relative scale of the root depending on the scale. If the scale 
   * is a major scale then the relative minor is computed. If the scale is
   * a minor scale the the relative major is computed.
   * 
   * @return relative scale of the initialized note.
   * 
   */
  public String getRelativeScale() { return ""; }
  
  /**
   * Gets the note in the interval of the initialized root note.
   * 
   * @param interval - range 1 .. 8
   * @return computed note in the scale of the initialized note as a string.
   * @throws InvalidNoteException 
   * 
   */
  public String getNote(int interval) throws InvalidNoteException
  {
	
    //int octave = interval / SCALE_NOTES;
    int scale_interval = interval % SCALE_NOTES; 
        
    return this.scale.numberToNote
            ( toHalfSteps(scale_interval));
	
  }
  
  /**
   * Gets a random interval between 1 - 8 inclusive from the root note
   * 
   * @return random interval
   */
  public int getRandomInterval()
  {

    Random generator = new Random();
    
    return generator.nextInt(SCALE_NOTES) + 1;
    
  }

  /**
   * Generates a list of random chords having the size of the given parameter.
   * 
   * @param num_random_chords number of random chords needed to be generated
   * @return list of random chords
   */
  public LinkedList<String> getRandomChords(int num_random_chords)
  {
	  
    LinkedList<String> random_chords = new LinkedList<String>();
    int random_interval;
    
  	System.out.println("random chords is : " +num_random_chords);
    for(int i =0; i< num_random_chords; i++){
    	System.out.println("random interval is : " +this.getRandomInterval());
    	do
    	  random_interval = this.getRandomInterval();
    	while (random_interval >= SCALE_NOTES - 1); // dont include 7th or 8th interval
    	
      try {
		random_chords.add(this.getChord(random_interval));
	} catch (InvalidNoteException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    }
    
    return random_chords;
    
  }
  
  /**
   * Determines if the given note is in the initialized scale
   * @param note note to be checked
   * @return true if the note is in the scale and false otherwise
   * @throws InvalidNoteException 
   */
  public boolean noteInScale(NoteLetterType note)
  {
  
    boolean note_in_scale = false;
    for (int interval_index = 1; interval_index <=8; interval_index++){
      
      try {
	      if (note == 
	      	  this.scale.noteToType(this.getNote(interval_index))){
	        note_in_scale = true;
	        break;
	      }
      } catch (InvalidNoteException e) {
	      return false;
      }
    }
    return note_in_scale;
    
  }
  
  /**
   * Gets the interval the given note is from the initialized scale root note
   * 
   * @param noteLetterType
   * @return number of intervals from the root note.
   * @throws InvalidNoteException 
   */
  public byte getInterval(NoteLetterType note) throws InvalidNoteException
  {
  
    byte interval_index = 1;
    for (; interval_index <=8; interval_index++){
      
      if (note == 
      		this.scale.noteToType(this.getNote(interval_index))){
        break;
      }
    }
    return interval_index;
    
  }
  
  /**
   * Converts the <Class>ScaleManager</Class> object to string
   * 
   * @return String representation of the Scale_Manager object.
   * @see ScaleManager
   */
  public String toString()
  {
	  
	  String string_obj = "";

	  for (int interval_index = 1; interval_index <=8; interval_index++)
		try {
			string_obj += this.getChord(interval_index) + ", ";
		} catch (InvalidNoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	  return string_obj;
	  
  }
  
}
