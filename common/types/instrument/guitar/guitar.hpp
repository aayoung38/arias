/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include "noteletter.hpp"
#include "guitarnote.hpp"
#include "guitarstring.hpp"

using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace types{
namespace instrument{
namespace guitar{

class Guitar {

  
  /**
   * Constructor for the <class>Guitar</class>
   */
  public:
    Guitar();
  
  /**
   * Gets the guitar note data for the given string and fret number.
   * 
   * @param string_num string number of the guitar note to get
   * @param fret_number fret number of the guitar note to get
   * @return <class>GuitarNote</class> for the given string and fret number 
   */
   GuitarNote getNote(int string_num, int fret_number);
  
  /**
   * Gets a random string from the initialized guitar object
   * @return
   */
  std::uint8_t getRandomString();
  
  /**
   * Gets a random fret number between 0 and the number of supported guitar
   * frets.
   * @return integer between 0 and <code>GUITAR_FRETS</code>
   */
  std::uint8_t getRandomFret();
  
  
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
   int getNumberOctaves(GuitarNote note_1, GuitarNote note_2);
  
  /**
   * Determines if the second parameter i.e. the reference note, is a lower 
   * note on the guitar than the first parameter. 
   * @param lowest_note note to compare against the reference note
   * @param reference_note note to determine is the lower note of the two
   * @return true if the reference note is the lower note and false otherwise
   */
   bool referenceIsLower(GuitarNote lowest_note, GuitarNote reference_note);

  
	/**
	 * Returns true if the two given notes are the same notes and false otherwise.
	 * <p>
	 * Octaves are considered different notes.
	 *
   * @param  a first of two notes to compare
   * @param  b second of two notes to compare
	 */
   bool notesAreSame(GuitarNote a, GuitarNote b);
  
  
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
   GuitarNote getClosestNote(GuitarNote reference_note, GuitarNote generated_note);
  
  
  /**
   * Gets a random note supported by the guitar.
   * <p>
   * The random note is of any fret of any string
   * @return <Class>Guitar_Note</Class> of a the random note, its fret, and 
   * 				 string. 
   */
   GuitarNote getRandomNote();
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of strings supported by the class
   */
  std::uint8_t getNumStrings();
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of frets supported by the class
   */
  std::uint8_t getNumFrets();
  
  
  /**
   * Gets the string representation of the class.
   * @return string representation of the class.
   */
  std::string toString();
  
  protected:
    static constexpr std::uint8_t GUITAR_FRETS   = 22;
    static constexpr std::uint8_t GUITAR_STRINGS = 6;
    GuitarString strings[GUITAR_STRINGS];

  private:

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
    int getGlobalNoteNumber(GuitarNote note);

};

}
}
}
}
}
