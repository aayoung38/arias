/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "guitarnote.h"
using namespace arias::common::types;
using namespace arias::common::types::instrument::guitar;

  /**
   * Constructor
   */
  GuitarNote::GuitarNote(){
  
  	string_number = NULL_STRING_NUMBER;
  	fret_number = NULL_FRET_NUMBER;
	 
  }
  
  InstrumentString GuitarNote::getNullStringNumber(){ return NULL_STRING_NUMBER; }

  /**
   * Constructor
   * @param noteLetterType guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
   GuitarNote::GuitarNote(note::NoteLetterType l, InstrumentOctave o, InstrumentFret f, InstrumentString s) : Note(l,o), fret_number(f), string_number(s)     
     
   {
    
   }
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
  GuitarNote::GuitarNote(NoteLetterType letter, 
  									InstrumentOctave o, 
  									InstrumentFret f, 
  									InstrumentString s, 
  									NoteValueType beat) : Note(letter,o,beat), fret_number(f), string_number(s)             
  {
  }
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   */
  GuitarNote::GuitarNote(const GuitarNote & note){
 
    letter = note.getLetter();
    value = note.getValue();
    octave = note.getOctave();
    fret_number = note.getFretNumber();
    string_number = note.getStringNumber();
    frequency = note.getFrequency();
  }
  
  /**
   * Obtains the fret number for the note instance
   * @return fret number
   */
  InstrumentFret GuitarNote::getFretNumber() const{ return fret_number; }
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
  InstrumentString GuitarNote::getStringNumber() const{ return string_number; }
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
  double GuitarNote::getFrequency() const{ return frequency; }
  
  /**
   * Assigns the guitar notes positional information on the guitar
   * <p>
   * The guitar note isn't modified and so the given positions should logically
   * produce the same note the guitar note was initialize with 
   * @param fret_number fret number to change the note position to
   * @param string_number string number to change the note position to
   */
  void GuitarNote::setNote(InstrumentFret fret_number, InstrumentString string_number, float frequency)
  { 
  	this->fret_number = fret_number; 
    this->string_number = string_number; 
    this->frequency = frequency;

  }

  /**
   * Assigns the guitar note's string number 
   * <p>
   * This method should only be called when setting string numbers of
   * rest notes.
   * 
   * @param string_number string number to change the note position to
   */
  void GuitarNote::setStringNumber(InstrumentString string_number)
  { 
    this->string_number = string_number; 
  }


namespace arias{
namespace common{
namespace types{
namespace instrument{
namespace guitar{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const GuitarNote & note)
{
     os << "String Number: " << unsigned(note.string_number) 
        << ", Fret Number: " << unsigned(note.fret_number)
        << ", Fret letter: " << note.letter
        << ", Object: " << Note(note);

        return os;
}

}}}}

}
  
