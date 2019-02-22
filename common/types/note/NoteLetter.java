/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common.types.note;

import com.ariasproj.common.exceptions.InvalidIntervalException;
import com.ariasproj.common.exceptions.InvalidNoteException;

public class NoteLetter {
	 
	/**
	 * [C,  C#,  D,  D#,  E,  F,  F#,  G,  G#, A,  A#, B]
	 * <p>
	 * [1,  2,   3,  4,   5,  6,  7,   8,  9,  10, 11, 12]
	 */
	private static final String[] AVAILABLE_NOTES_SHARP = 
	  { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#","A", "A#", "B" };

	/**
	 * <p>
	 * [C, Db, D, Eb, E, F, Fb, G, Ab, A, Bb, B]
	 * <p>
	 * [1, 2,  3, 4,  5, 6, 7,  8, 9,  10,11, 12]
	 */
	private static final String[] AVAILABLE_NOTES_FLAT = 
	  { "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab","A", "Bb", "B" };

  protected static final String NULL_VAL = "-";
  
	private boolean use_flats;
	private String[] working_notes;
	private int reference_note_number;
	private String reference_note;
	private NoteLetterType reference_note_type;
	/**
	 * Constructor for the <Class>Note_Utilities</Class> class.
	 * <p>
	 * By default it is assumed that the note is in terms of sharps.
	 * 
	 * @param reference_note
	 *          note to initialize the class to.
	 * @throws InvalidNoteException 
	 */
	public NoteLetter(NoteLetterType note){
		this.reference_note_type = note;
	  this.reference_note = this.typeToNote(this.reference_note_type);
		this.use_flats = noteIsFlat(this.reference_note);
		
		this.working_notes = this.use_flats ? AVAILABLE_NOTES_FLAT
		    : AVAILABLE_NOTES_SHARP;
		try{
			this.reference_note_number = noteToNumber(reference_note);
		}
	  catch (InvalidNoteException e){
			this.reference_note_number = -1;
	  }
	  
	}
	private NoteLetter(boolean useFlats)
	{
		this.use_flats = useFlats;
	}

	public static NoteLetter getNoteLetter(boolean useFlats) {return new NoteLetter(useFlats);}
	/**
	 * Constructor for the <Class>Note_Utilities</Class> class.
	 * 
	 * @param reference_note
	 *          note to initialize the class to. The note is represented as a
	 *          number.
	 */
	public NoteLetter(int note) {
    this.reference_note_type = NoteLetterType.NULL_NOTE;
    this.reference_note = this.typeToNote(this.reference_note_type);
		this.use_flats = false;
		
		// this can be ultimately determined....
		this.working_notes = AVAILABLE_NOTES_FLAT;
		
		this.reference_note_number = note;
	}

	/**
	 * Constructor for the <Class>Note_Utilities</Class> class.
	 * 
	 * @param reference_note
	 *          note to determine is in sharps or flats.
	 * @param use_flats
	 *          boolean to indicate desire to represents applicable notes in terms
	 *          of flats rather than sharps.
	 * @throws InvalidNoteException 
	 */
	public NoteLetter(NoteLetterType note, boolean use_flats) {
    this.reference_note_type = note;
    this.reference_note = this.typeToNote(this.reference_note_type);
    
		this.use_flats = use_flats;
		this.working_notes = this.use_flats ? AVAILABLE_NOTES_FLAT
		    : AVAILABLE_NOTES_SHARP;
		try{
			this.reference_note_number = this.noteToNumber(this.reference_note);
		}
	  catch (InvalidNoteException e){
			this.reference_note_number = -1;
	  }
	}

  /**
   * Returns the number of notes supported by the application
   * 
   * @return number of supported notes
   */
  public static int getNumberNotes(){ return NoteLetterType.values().length;}
  
  /**
   * Converts the given <Enum>NoteLetterType</Enum> to letter
   * 
   * @param type letter to convert to string
   * 
   * @return string representation of the given type
   */
  public String typeToNote(NoteLetterType note){
    
    switch (note){
      case C:         return "C";
      case C_SHARP:   return "C#";
      case D_FLAT:    return "Db";
      case D:         return "D";
      case D_SHARP:   return "D#";
      case E_FLAT:    return "Eb";
      case E:         return "E";
      case F:         return "F";
      case F_SHARP:   return "F#";
      case G_FLAT:    return "Gb";
      case G:         return "G";
      case G_SHARP:   return "G#";
      case A_FLAT:    return "Ab";
      case A:         return "A";
      case A_SHARP:   return "A#";
      case B_FLAT:    return "Bb";
      case B:         return "B";
      case NULL_NOTE: return NULL_VAL;
      default:        return NULL_VAL;
    }
  }
  
  public NoteLetterType noteToType(String note){
    switch (note){
    case "C"  : return NoteLetterType.C;
    case "C#" : return NoteLetterType.C_SHARP;
    case "Db" : return NoteLetterType.D_FLAT;
    case "D"  : return NoteLetterType.D;
    case "D#" : return NoteLetterType.D_SHARP;
    case "Eb" : return NoteLetterType.E_FLAT;
    case "E"  : return NoteLetterType.E;
    case "F"  : return NoteLetterType.F;
    case "F#" : return NoteLetterType.F_SHARP;
    case "Gb" : return NoteLetterType.G_FLAT;
    case "G"  : return NoteLetterType.G;
    case "G#" : return NoteLetterType.G_SHARP;
    case "Ab" : return NoteLetterType.A_FLAT;
    case "A"  : return NoteLetterType.A;
    case "A#" : return NoteLetterType.A_SHARP;
    case "B"  : return NoteLetterType.B;
    default   : return NoteLetterType.NULL_NOTE;
    
    }
  }
  
	/**
	 * Determines if the given note is in terms of flats or sharps
	 * <p>
	 * By default it is assumed that the note is in terms of sharps.
	 * 
	 * @param note
	 *          note to determine is in sharps or flats.
	 */
	public boolean noteIsFlat(String note) {

		return note.length() > 1 && note.charAt(1) == 'b';
	}

	/**
	 * Computes the given note to its equivalent representive number.
	 * 
	 * @param note
	 *          valid note between A-G to convert to its internal number
	 * @return note representation of the given number.
	 */
	public int noteToNumber(String note) throws InvalidNoteException {

		String[] working_scale = noteIsFlat(note) ? AVAILABLE_NOTES_FLAT
		    : AVAILABLE_NOTES_SHARP;
		int tmp_scale_number = 0;

		for (; tmp_scale_number < working_scale.length
		    && !working_scale[tmp_scale_number].equals(note); tmp_scale_number++)
			;

		if (tmp_scale_number >= working_scale.length ){
			throw new InvalidNoteException(note);
		}
		return tmp_scale_number;
	}

	/**
	 * Computes the given number to its equivalent representive note.
	 * 
	 * @param number
	 *          number (1-12) to convert to a note
	 * @return note representation of the given number.
	 */
	public String numberToNote(int number) throws InvalidNoteException {

		return numberToNote(number,use_flats);
	}


	/**
	 * Computes the given number to its equivalent representive note.
	 * 
	 * @param number
	 *          number (1-12) to convert to a note
	 * @return note representation of the given number.
	 */
	public static String numberToNote(int number, boolean useFlats) throws InvalidNoteException {

		String[] working_scale = useFlats ? AVAILABLE_NOTES_FLAT
		    : AVAILABLE_NOTES_SHARP;
		int available_notes_num = number % working_scale.length;

		return working_scale[available_notes_num];
	}
	/**
	 * Gets the note distance from the reference note in terms of half steps.
	 * <p>
	 * Treats the reference note as the lower note.
	 * 
	 * @param note
	 *          note to get the distance from the reference note for
	 * @return integer distance from the reference note in half steps.
	 * @throws InvalidNoteException 
	 */
	public int getDistance(NoteLetter note) throws InvalidNoteException {

		int tmp_note = this.noteToNumber(note.getStringNote());
		
		if (tmp_note >= this.reference_note_number) 
		{
			return tmp_note - this.reference_note_number;
		}
		else 
		{
			return (NoteLetter.getNumberNotes() - this.reference_note_number) + tmp_note;
		}
	}

	/**
	 * Gets the initialized note
	 * 
	 * @return initialized note
	 */
	public NoteLetterType getNote(){ return this.reference_note_type; }

  /**
   * Gets the initialized note as a string
   * 
   * @return initialized note
   */
  public String getStringNote(){ return this.reference_note; }
	
	/**
	 * Gets the note which is the given distance from the initialized reference note
	 * @param distance distance from the reference note in half steps
	 * @return string note
	 * @throws InvalidNoteException
	 * @throws InvalidIntervalException 
	 */
	public NoteLetterType getNote(int distance)
			throws InvalidNoteException, InvalidIntervalException 
	{
	  
		if (distance < 0){
	  	throw new InvalidIntervalException();
	  }
	  
		if (this.reference_note_number < 0){
			throw new InvalidNoteException();
		}
		
    //int octave = distance / working_notes.length;
    int local_distance = distance % working_notes.length;
    
    int total_half_note_distance = this.reference_note_number + local_distance;
    
    if (total_half_note_distance >= working_notes.length)
		  return this.noteToType
		           (this.numberToNote
		               (total_half_note_distance % working_notes.length));
    
    else
      return this.noteToType
               (this.numberToNote(total_half_note_distance));

	}
	
	/**
	 * Determines if the note letter is null.
	 * @return True if the note is null and False otherwise
	 */
	public boolean isNull()
	{
		return this.reference_note_type == NoteLetterType.NULL_NOTE;
	}
	

}
