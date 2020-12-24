/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once;

// project includes
#include "invalidnoteexception.hpp"
#include "invalidintervalexception.hpp"
#include "notelettertype.hpp"

// std library includes
#include <string>

namespace arias{
namespace common{
namespace types{
namespace note{


class NoteLetter {
	 

	/**
	 * Constructor for the <Class>Note_Utilities</Class> class.
	 * <p>
	 * By default it is assumed that the note is in terms of sharps.
	 * 
	 * @param reference_note
	 *          note to initialize the class to.
	 * @throws InvalidNoteException 
	 */
  public:

    NoteLetter() = default;
    NoteLetter(NoteLetterType note);
	
	static NoteLetter getNoteLetter(bool useFlats);

	/**
	 * Constructor for the <Class>Note_Utilities</Class> class.
	 * 
	 * @param reference_note
	 *          note to initialize the class to. The note is represented as a
	 *          number.
	 */
	NoteLetter(int note);

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
	NoteLetter(NoteLetterType note, bool use_flats);

  /**
   * Returns the number of notes supported by the application
   * 
   * @return number of supported notes
   */
    static int getNumberNotes();
  
  /**
   * Converts the given <Enum>NoteLetterType</Enum> to letter
   * 
   * @param type letter to convert to string
   * 
   * @return string representation of the given type
   */
   std::string typeToNote(NoteLetterType note) const;
  
   NoteLetterType noteToType(std::string note) const;
  
	/**
	 * Determines if the given note is in terms of flats or sharps
	 * <p>
	 * By default it is assumed that the note is in terms of sharps.
	 * 
	 * @param note
	 *          note to determine is in sharps or flats.
	 */
	bool noteIsFlat(std::string note) const;

	/**
	 * Computes the given note to its equivalent representive number.
	 * 
	 * @param note
	 *          valid note between A-G to convert to its internal number
	 * @return note representation of the given number.
	 */
	int noteToNumber(std::string note) const;

	/**
	 * Computes the given number to its equivalent representive note.
	 * 
	 * @param number
	 *          number (1-12) to convert to a note
	 * @return note representation of the given number.
	 */
	std::string numberToNote(int number) const;


	/**
	 * Computes the given number to its equivalent representive note.
	 * 
	 * @param number
	 *          number (1-12) to convert to a note
	 * @return note representation of the given number.
	 */
	static std::string numberToNote(int number, bool useFlats);

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
	int getDistance(NoteLetter note);

	/**
	 * Gets the initialized note
	 * 
	 * @return initialized note
	 */
	NoteLetterType getNote() const;

  /**
   * Gets the initialized note as a string
   * 
   * @return initialized note
   */
   std::string getStringNote() const;
	
	/**
	 * Gets the note which is the given distance from the initialized reference note
	 * @param distance distance from the reference note in half steps
	 * @return string note
	 * @throws InvalidNoteException
	 * @throws InvalidIntervalException 
	 */
	NoteLetterType getNote(int distance) const;
	
	/**
	 * Determines if the note letter is null.
	 * @return True if the note is null and False otherwise
	 */
	bool isNull();
	

  protected:
    static const std::string NULL_VAL;

    private:

      bool use_flats;
	  const std::string* working_notes;
	  int reference_note_number;
	  std::string reference_note;
	  NoteLetterType reference_note_type;
      
	static constexpr int NUM_AVAILABLE_NOTES = 12;
	/**
	 * [C,  C#,  D,  D#,  E,  F,  F#,  G,  G#, A,  A#, B]
	 * <p>
	 * [1,  2,   3,  4,   5,  6,  7,   8,  9,  10, 11, 12]
	 */
	 static const std::string AVAILABLE_NOTES_SHARP[];

	/**
	 * <p>
	 * [C, Db, D, Eb, E, F, Fb, G, Ab, A, Bb, B]
	 * <p>
	 * [1, 2,  3, 4,  5, 6, 7,  8, 9,  10,11, 12]
	 */
	 static const std::string AVAILABLE_NOTES_FLAT[];

    NoteLetter(bool useFlats);

};

}
}
}
}