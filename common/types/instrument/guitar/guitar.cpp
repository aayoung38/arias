/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "guitar.hpp"
//using namespace arias::common::types::note;
using namespace arias::common::types::instrument::guitar;
  
  /**
   * Constructor for the <class>Guitar</class>
   */
    Guitar::Guitar()
    {
        for (int i=0; i< GUITAR_STRINGS; i++)
        {
          strings[i] = std::make_unique<GuitarString>(GuitarString(i));
        }
    }
  
  /**
   * Gets the guitar note data for the given string and fret number.
   * 
   * @param string_num string number of the guitar note to get
   * @param fret_number fret number of the guitar note to get
   * @return <class>GuitarNote</class> for the given string and fret number 
   */
   const GuitarNote & Guitar::getNote(int string_num, int fret_number)
   { 
    return strings[string_num]->getNoteElement(fret_number);
   }
  
  /**
   * Gets a random string from the initialized guitar object
   * @return
   */
  std::uint8_t Guitar::getRandomString(){return 0;}
  
  /**
   * Gets a random fret number between 0 and the number of supported guitar
   * frets.
   * @return integer between 0 and <code>GUITAR_FRETS</code>
   */
  std::uint8_t Guitar::getRandomFret(){return 0;}
  
  
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
   int Guitar::getNumberOctaves(GuitarNote note_1, GuitarNote note_2){return 0;}
  
  /**
   * Determines if the second parameter i.e. the reference note, is a lower 
   * note on the guitar than the first parameter. 
   * @param lowest_note note to compare against the reference note
   * @param reference_note note to determine is the lower note of the two
   * @return true if the reference note is the lower note and false otherwise
   */
   bool Guitar::referenceIsLower(GuitarNote lowest_note, GuitarNote reference_note){return false;}

  
	/**
	 * Returns true if the two given notes are the same notes and false otherwise.
	 * <p>
	 * Octaves are considered different notes.
	 *
   * @param  a first of two notes to compare
   * @param  b second of two notes to compare
	 */
   bool Guitar::notesAreSame(GuitarNote a, GuitarNote b){return false;}
  
  
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
   GuitarNote Guitar::getClosestNote(GuitarNote reference_note, GuitarNote generated_note){ return GuitarNote();}
  
  
  /**
   * Gets a random note supported by the guitar.
   * <p>
   * The random note is of any fret of any string
   * @return <Class>Guitar_Note</Class> of a the random note, its fret, and 
   * 				 string. 
   */
   GuitarNote Guitar::getRandomNote(){return GuitarNote();}
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of strings supported by the class
   */
  std::uint8_t Guitar::getNumStrings(){ return 0;}
  
  
  /**
   * Gets the number of frets supported by the class.
   * @return number of frets supported by the class
   */
  std::uint8_t Guitar::getNumFrets(){ return 0;}
  
  
  /**
   * Gets the string representation of the class.
   * @return string representation of the class.
   */
  std::ostream& operator<< (std::ostream &os, const Guitar & g)
  {
    return os;
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
    int Guitar::getGlobalNoteNumber(GuitarNote note){ return 0; }


