/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common.types.instrument.guitar;

import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.types.note.NoteLetterType;
import com.ariasproj.common.types.note.NoteObject;
import com.ariasproj.common.types.note.NoteValueType;


public class GuitarNote extends NoteObject{
	
  private int fret_number;
  private int string_number;
  
  private int NULL_STRING_NUMBER = -1;  
  private int NULL_FRET_NUMBER = -1;

  /**
   * Constructor
   */
  public GuitarNote() {
  	super();
  	this.string_number = NULL_STRING_NUMBER;
  	this.fret_number = NULL_FRET_NUMBER;
	 
  }
  
  public int getNullStringNumber(){ return NULL_STRING_NUMBER; }

  /**
   * Constructor
   * @param noteLetterType guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
  public GuitarNote(NoteLetterType noteLetterType, int octave, int fret_number, int string_number){
  	super(noteLetterType, octave);
    this.fret_number = fret_number;
    this.string_number = string_number;
  }
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
  public GuitarNote(NoteLetterType note, 
  									int octave, 
  									int fret_number, 
  									int string_number, 
  									NoteValueType beat_number){
  	
  	super(note, octave, beat_number);
    this.fret_number = fret_number;
    this.string_number = string_number;
  }
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   */
  public GuitarNote(GuitarNote note){
    super();
    this.note_letter = note.getNoteLetter();
    this.note_value = note.getValue();
    this.octave = note.getOctave();
    this.fret_number = note.getFretNumber();
    this.string_number = note.getStringNumber();
    this.frequency = note.getFrequency();
  }
  
  /**
   * Obtains the fret number for the note instance
   * @return fret number
   */
  public int getFretNumber(){ return this.fret_number; }
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
  public int getStringNumber(){ return this.string_number; }
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
  public double getFrequency(){ return this.frequency; }
  
  /**
   * Assigns the guitar notes positional information on the guitar
   * <p>
   * The guitar note isn't modified and so the given positions should logically
   * produce the same note the guitar note was initialize with 
   * @param fret_number fret number to change the note position to
   * @param string_number string number to change the note position to
   */
  public void setNote(int fret_number, int string_number, float frequency)
  { 
  	this.fret_number = fret_number; 
    this.string_number = string_number; 
    this.frequency = frequency;

  }

  /**
   * Assigns the guitar note's string number 
   * <p>
   * This method should only be called when setting string numbers of
   * rest notes.
   * 
   * @param string_number string number to change the note position to
   */
  public void setStringNumber(int string_number)
  { 
    this.string_number = string_number; 
  }

  public String toString() 
  {
     return "String Number: "+this.string_number + 
            ", Letter: "+this.note_letter.getNote()+
            ", Fret Number: " +this.fret_number + "Object: "+super.toString();  
  }
  
}
