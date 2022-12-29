/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

// project includes
#include "invalidnoteexception.hpp"
#include "invalidintervalexception.hpp"
#include "notelettertype.hpp"

// std library includes
#include <iostream>
#include <memory>
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
    NoteLetter(const NoteLetter& note);
	
    static NoteLetter getNoteLetter();

    static void useFlats(bool use_flats);

    /**
     * Returns the number of notes supported by the application
     * 
     * @return number of supported notes
     */
    static int getNumberNotes();
    
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
    int getDistance(const NoteLetter & note);

    /**
     * Gets the initialized note
     * 
     * @return initialized note
     */
    NoteLetterType getNote() const;

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
    bool isNull() const;
	
    NoteLetter& operator=(const NoteLetter & note);

    /**
     * Converts the given <Enum>NoteLetterType</Enum> to letter
     * 
     * @param type letter to convert to string
     * 
     * @return string representation of the given type
     */
    std::string getStringNote() const;

    /**
     * Outputs the object to standard output
     */
	  friend std::ostream & operator << (std::ostream &, const NoteLetter & note);

  protected:
    static const std::string NULL_VAL;
    
    
    
    static NoteLetterType getNoteLetter(const std::string & note);

  private:

	  NoteLetterType reference_note;
      
    static bool use_flats;
	  static constexpr int NUM_AVAILABLE_NOTES = 12;

};

}
}
}
}