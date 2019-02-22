/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common.types.instrument.guitar;

import java.util.Random;

import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.types.note.NoteLetter;

public class Guitar {

  protected static final byte GUITAR_FRETS   = 22;
  protected static final byte GUITAR_STRINGS = 6;
  protected GuitarString [] strings;
  
  /**
   * Constructor for the <class>Guitar</class>
   */
  public Guitar() {
  	this.strings = new GuitarString[GUITAR_STRINGS];
    
  	// initialize each guitar string
    for (int string_index = 0; string_index < GUITAR_STRINGS; string_index++)
	    try {
	      this.strings[string_index] = new GuitarString(string_index, GUITAR_FRETS);
      } catch (InvalidNoteException e) {
	      
      	// We should never under any circumstances get here. Something has gone very wrong.
      	System.out.println("Error - severe error initializing guitar class.");
	      e.printStackTrace();
      }
    
  }
  
  /**
   * Gets the guitar note data for the given string and fret number.
   * 
   * @param string_num string number of the guitar note to get
   * @param fret_number fret number of the guitar note to get
   * @return <class>GuitarNote</class> for the given string and fret number 
   */
  public GuitarNote getNote(int string_num, int fret_number){
    
    return this.strings[string_num].getNoteElement(fret_number);
  }
  
  /**
   * Gets a random string from the initialized guitar object
   * @return
   */
  public byte getRandomString(){

    Random generator = new Random();
    
    return (byte) generator.nextInt(GUITAR_STRINGS);
    
  }
  
  /**
   * Gets a random fret number between 0 and the number of supported guitar
   * frets.
   * @return integer between 0 and <code>GUITAR_FRETS</code>
   */
  public byte getRandomFret(){

    Random generator = new Random();
    
    return (byte) generator.nextInt(GUITAR_FRETS);
    
  }
  
  /**
   * Returns the global number on the guitar for the given note.
   * <p>
   * The global number is defined as:
   * <p>
   * 		note's string number x
   * <p> 
   *    number notes between the string and the next highest it +
   * <p>
   *    note's fret number
   * <p>
   * Guitar notes can have the same global note as other notes if they are
   * considered the same note (e.g. A on Low E string, 5th fret A on A string 0th fret (open))
   * @param note
   * @return global number on the
   */
  private int getGlobalNoteNumber(GuitarNote note){
  	
  	final int notes_between_strings = 5;
  	final int notes_between_g_string = 4;
  	
  	int global_number = 0;
  	
  	if (note.getStringNumber() > GuitarString.G_STRING){
  		global_number = 
  			((note.getStringNumber() - 1) * notes_between_strings) + 
  			notes_between_g_string + note.getFretNumber();
  	}
  	else {
  		global_number = 
    		note.getStringNumber() * notes_between_strings + note.getFretNumber();
  	}
  	
  	return global_number;
  	
  }
  
  /**
   * Determines the number of octaves between the two given notes from the 
   * distance between the two notes
   * <p>
   * If the distance between the two notes is, for example, 13 half steps then
   * the number of octaves is 
   * @param note_1
   * @param note_2
   * @return
   */
  public int getNumberOctaves(GuitarNote note_1, GuitarNote note_2){
  	
  	return Math.abs(this.getGlobalNoteNumber(note_1) - 
  									this.getGlobalNoteNumber(note_2)) / NoteLetter.getNumberNotes();
  
  }
  
  /**
   * Determines if the second parameter i.e. the reference note, is a lower 
   * note on the guitar than the first parameter. 
   * @param lowest_note note to compare against the reference note
   * @param reference_note note to determine is the lower note of the two
   * @return true if the reference note is the lower note and false otherwise
   */
  public boolean referenceIsLower(GuitarNote lowest_note, GuitarNote reference_note){
  	return this.getGlobalNoteNumber(reference_note) < this.getGlobalNoteNumber(lowest_note); 
  }

  
	/**
	 * Returns true if the two given notes are the same notes and false otherwise.
	 * <p>
	 * Octaves are considered different notes.
	 *
   * @param  a first of two notes to compare
   * @param  b second of two notes to compare
	 */
  public boolean notesAreSame(GuitarNote a, GuitarNote b){
  	
  	boolean notes_are_same = false;
  	if(a.getNoteLetter() == b.getNoteLetter()){
  		notes_are_same = this.getGlobalNoteNumber(a) == this.getGlobalNoteNumber(b);
  	}
  	
  	return notes_are_same;
  }
  
  
	/**
	 * Gets the closest note on a fret and string to the reference note for a given note.
	 * <p>
	 * The closest note is considered to be within a four fret distance, from the 
	 * reference note, of the same note tonality.
	 *
   * @param  scale root note for the scale to initialize the class in
   * <p>
   * By default the class uses sharps unless the root note specified is a
   * flat note.
	 */
  public GuitarNote getClosestNote(GuitarNote reference_note, GuitarNote generated_note){

  	GuitarNote closest_note = new GuitarNote(generated_note);
  	
  	if (generated_note.getFretNumber() > reference_note.getFretNumber()){
  		while(Math.abs(closest_note.getFretNumber() - reference_note.getFretNumber()) >= 4 &&
  				  closest_note.getStringNumber() != GuitarString.HIGH_E_STRING){
  			int fret_difference = 5;
  			if (closest_note.getStringNumber() == GuitarString.G_STRING )
  				fret_difference = 4;
  
  			closest_note = this.getNote(closest_note.getStringNumber() + 1,
  																  closest_note.getFretNumber() - fret_difference);
  		}
  	}
  	
  	else {
  		while(Math.abs(closest_note.getFretNumber() - reference_note.getFretNumber()) >= 4 &&
  				  closest_note.getStringNumber() != GuitarString.LOW_E_STRING){
  			int fret_difference = 5;
  			if (closest_note.getStringNumber() == GuitarString.B_STRING )
  				fret_difference = 4;
  			  
          closest_note = this.getNote(closest_note.getStringNumber() -1,
          														closest_note.getFretNumber() + fret_difference);
  			
  		}
  	}
  	/*if(generated_note.getFretNumber() != closest_note.getFretNumber() || 
  		 generated_note.getStringNumber() != closest_note.getStringNumber())
  		
  	  System.out.println("Original: "+generated_note+", Closest: "+closest_note);
  	*/
  	return closest_note;
  }
  
  
  /**
   * Gets a random note supported by the guitar.
   * <p>
   * The random note is of any fret of any string
   * @return <Class>Guitar_Note</Class> of a the random note, its fret, and 
   * 				 string. 
   */
  public GuitarNote getRandomNote(){
    
    Random generator = new Random();
    
    return this.getNote(generator.nextInt(GUITAR_STRINGS),
                        generator.nextInt(GUITAR_FRETS));
  }
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of strings supported by the class
   */
  public byte getNumStrings(){ return (byte) this.strings.length; }
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of frets supported by the class
   */
  public byte getNumFrets(){ return (byte) this.strings[0].getNumberFrets(); }
  
  
  /**
   * Gets the string representation of the class.
   * @return string representation of the class.
   */
  public String toString(){
    String output = "";
    
    for (byte fret_number = 0; fret_number < GUITAR_FRETS ; fret_number++){
      output += String.format("%3d|", fret_number);
      
      for (byte string_number = 0; 
      		string_number < GUITAR_STRINGS; 
      		string_number++){
      	
        output += String.format("%3s", 
        	this.strings[string_number].getNoteElement(fret_number).getNoteLetter());  
      
      }
      
      output += String.format("\n");
    }
    
    return output;
  }
  
}
