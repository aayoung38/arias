/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common.types.note;

import java.util.Random;
import com.ariasproj.common.exceptions.InvalidNoteException;

public class NoteObject {

  protected final int NUMBER_NOTES = NoteLetter.getNumberNotes();
  
  private static final double FREQUENCY_CONSTANT = Math.pow(2.0,1.0/12.0);
  
  // Frequency based on C0 note
  private static final double REFERENCE_NOTE_FREQUENCY = 16.35; 
  private static final NoteLetterType REFERENCE_NOTE_LETTER = NoteLetterType.C;
  private static final int    REFERENCE_NOTE_OCTAVE = 0;
	
	private static final double NULL_FREQUENCY = -1.0;
	protected static final int  NULL_OCTAVE = -1000;

	protected NoteValue note_value;
	protected NoteLetter note_letter;
	protected int octave;

	protected double frequency;
	
	// boolean to indicate whether a note is a rest or not.
	protected boolean note_is_rest;
	
	/**
	 * Default constructor
	 */
  public NoteObject(){
  	
    this.note_value = new NoteValue(NoteValueType.WHOLE);
	  this.note_letter = new NoteLetter(NoteLetterType.NULL_NOTE);
	  
	  this.octave = NULL_OCTAVE;
	  
	  this.frequency = 0.0;
	  
    // by default treat every new note as a non-rest note.
	  this.note_is_rest = false;
	  
  }  

  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @throws InvalidNoteException 
   */
  public NoteObject(NoteLetterType note, int octave){
    
    this.note_value = new NoteValue(NoteValueType.WHOLE);
    this.note_letter = new NoteLetter(note);
    
    this.octave = octave;
    this.computeFrequency();
    
    // by default treat every new note as a non-rest note.
    this.note_is_rest = false; 
  }
  
  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @throws InvalidNoteException 
   */
  public NoteObject(NoteLetterType note, int octave, boolean isRest){
  	
    this.note_value = new NoteValue(NoteValueType.WHOLE);
    this.note_letter = new NoteLetter(note);
    
    this.octave = octave;
    this.computeFrequency();
    
    // by default treat every new note as a non-rest note.
    this.note_is_rest = isRest; 
  }
  
  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @param note_value note value to initialize the note to, see NoteValue enum
   * @throws InvalidNoteException 
   */
  public NoteObject(NoteLetterType note, int octave, NoteValueType note_value){
  	
    this.note_value = new NoteValue(note_value);
    this.note_letter = new NoteLetter(note);
    
    this.octave = octave;

    this.computeFrequency();
    
    // by default treat every new note as a non-rest note.
    this.note_is_rest = false; 
  }

  
  /**
   * Gets the octave of the note.
   * @return octave of the note
   */
  public int getOctave(){ return this.octave;}

  /**
   * Gets the letter value of the note
   * 
   * @return letter value of the note
   */
  public NoteLetter getNoteLetter(){ return this.note_letter; }
	
	/**
	 * Gets a description of the value of the note currently set.
	 * <p>
	 * See NoteValue
	 *   
	 * @return string description of the note value
	 */
	public String getBeatName(){ return this.note_value.toString(); }
  
	/**
	 * Sets the note instance's beat to a random beat value based off of how many
	 * beats are left over in the measure. 
	 * <p>
	 * Only beat values that fit in the amount of beats left are candidates for 
	 * random selection
	 * @param beats_left how many beats are left in a given measure of music
	 */
	public void setRandomBeat(float beats_left){this.note_value.setRandomValue(beats_left);}
	
  /**
   * Gets the letter type value of the note
   * 
   * @return letter value of the note
   */
  public NoteLetterType getNoteType(){ return this.note_letter.getNote(); }
  /**
   * Gets the letter type value of the note
   * 
   * @return letter value of the note
   */
  public double getFrequency(){ return this.frequency; }
  
	/**
	 * Gets the rest value of the note
	 * 
	 * @return rest value of the note
	 */
	public String getRestValue(){ return "/"; }
	
	/**
	 * Gets the letter value of a null note
	 * 
	 * @return letter value of a null note
	 */
  public static NoteObject getNullNote() {
  	
  	return new NoteObject(NoteLetterType.NULL_NOTE, NULL_OCTAVE,true); 
  	
  }
  
  /**
   * Sets the note information to null.
   */
  public void setNull() { 
  	this.note_letter = new NoteLetter(NoteLetterType.NULL_NOTE); 
    this.note_value = new NoteValue(NoteValueType.NULL);
  	this.octave = NULL_OCTAVE;
  }
  
  /**
   * Determines if the note is null
   * 
   * @return True if the note is null and False otherwise
   */
  public boolean isNull() { return this.note_letter.isNull(); }

  
  /**
   * Determines if the note is a rest
   * @return True if the note is a rest and False otherwise
   */
  public boolean isRest() { return this.note_is_rest; }
  
  
  /**
   * Gets the type of the note 
   *<p>
   * See NoteType enum
   */
	public NoteValue getValue(){ return this.note_value;}
  
	/**
	 * Sets the note instance as a note or a rest. 
	 * <p>
	 * There is a 25% chance of the note being a rest.
	 */
  public void selectRestOrNote(){

    Random generator = new Random();
    int random_note = generator.nextInt(100);
    
    if (random_note <= 25)
    	this.note_is_rest = true;
      
    else 
    	this.note_is_rest = false;
    
  }

  /**
   * Sets the note type to a random value.
   * <p>
   * See NoteType for types
   */
  private void setRandomBeatVal(){

    Random generator = new Random();
    int beat_val = generator.nextInt(4);
    
    switch (beat_val){
    	case 0:
        this.note_value = new NoteValue(NoteValueType.WHOLE);
    	case 1:
        this.note_value = new NoteValue(NoteValueType.HALF);
    	case 2:
        this.note_value = new NoteValue(NoteValueType.QUARTER);
    	case 3:
        this.note_value = new NoteValue(NoteValueType.EIGHTH);
    	case 4:
        this.note_value = new NoteValue(NoteValueType.SIXTEENTH);
      default:
        this.note_value = new NoteValue(NoteValueType.QUARTER);
    }
    
  }
  
  /**
   * The basic formula for the frequencies of the notes of the equal tempered 
   * scale is given by:
   *   fn = f0 * (a)n 
   * 
   * where: 
   *   f0 = the frequency of one fixed note which must be defined. A common 
   *        choice is setting the A above middle C (A4) at f0 = 440 Hz.
   *        
   *   n = the number of half steps away from the fixed note you are. If you
   *       are at a higher note, n is positive. If you are on a lower note, 
   *       n is negative.
   *       
   *   fn = the frequency of the note n half steps away.
   *   
   *    a = (2)1/12 = the twelth root of 2 = the number which when multiplied 
   *        by itself 12 times equals 2 = 1.059463094359... 
   * @throws InvalidNoteException 
   *   
   */
  private void computeFrequency(){
    
  	try
  	{
  		NoteLetter reference_note = new NoteLetter (REFERENCE_NOTE_LETTER);
  		NoteLetter instance_note = new NoteLetter (this.note_letter.getNote());
    
  		/* reference note is assumed (at this point to be the first note of the scale, 
  		 * so just find the distance away from the instance note and subtract from the
  		 * octaves.
  		 */
  		double half_steps = ((this.octave - REFERENCE_NOTE_OCTAVE)*12) + 
  												 (reference_note.getDistance(instance_note));
  		this.frequency = (REFERENCE_NOTE_FREQUENCY * Math.pow(FREQUENCY_CONSTANT,half_steps));
  	 
  	}
    catch(InvalidNoteException e){
      
      System.err.println
        ("Error - Invalid note detected. "+
         "Cannot compute frequency, setting to "+NULL_FREQUENCY);
      
      this.frequency = NULL_FREQUENCY;
    	
    }
  }
  
	/**
	 * Converts the class to string
	 * @return string representation of the class
	 */
	public String toString(){
		
		return this.note_value+", Is Rest = "+this.note_is_rest+", Beat Octave = "+this.octave+", Freq = "+this.frequency;
		
	}
	
}
