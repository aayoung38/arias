/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "guitarnote.hpp"
//using namespace arias::common::types::note;
using namespace arias::common::types::instrument::guitar;

  /**
   * Constructor
   */
  GuitarNote::GuitarNote() {
  
  	string_number = NULL_STRING_NUMBER;
  	fret_number = NULL_FRET_NUMBER;
	 
  }
  
  int GuitarNote::getNullStringNumber(){ return NULL_STRING_NUMBER; }

  /**
   * Constructor
   * @param noteLetterType guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
   GuitarNote::GuitarNote(note::NoteLetterType noteLetterType, int octave, int fret_number, int string_number)
   {
  	note::NoteObject(noteLetterType, octave);
    fret_number = fret_number;
    string_number = string_number;
  }
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
  GuitarNote::GuitarNote(NoteLetterType note, 
  									int octave, 
  									int fret_number, 
  									int string_number, 
  									NoteValueType beat_number)                  
  {
  	
  	NoteObject(note, octave, beat_number);
    fret_number = fret_number;
    string_number = string_number;
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
  int GuitarNote::getFretNumber() const{ return fret_number; }
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
  int GuitarNote::getStringNumber() const{ return string_number; }
  
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
  void GuitarNote::setNote(int fret_number, int string_number, float frequency)
  { 
  	fret_number = fret_number; 
    string_number = string_number; 
    frequency = frequency;

  }

  /**
   * Assigns the guitar note's string number 
   * <p>
   * This method should only be called when setting string numbers of
   * rest notes.
   * 
   * @param string_number string number to change the note position to
   */
  void setStringNumber(int string_number)
  { 
    string_number = string_number; 
  }

  std::string GuitarNote::toString() 
  {
     return "String Number: "+std::to_string(string_number) + 
            ", Letter: "+std::to_string(letter.getNote())+
            ", Value: "+std::to_string(value.getBeats())+
            ", Fret Number: " +std::to_string(fret_number);
            
            // + "Object: "+note::.toString();  
  }
  
