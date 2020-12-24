/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "guitarstring.hpp"

#include <iostream>

using namespace arias::common::types::instrument::guitar;

  /**
   * Constructor
   * 
   * @param string_number string index of the guitar string 
   * <p>
   * e.g.<p>
   * E = 1<p>
   * A = 2<p>
   * D = 3<p>
   * G = 4<p>
   * B = 5<p>
   * E = 6<p>
   * 
   * @param num_frets number of frets the guitar string has
   * @throws InvalidNoteException 
   */
  GuitarString::GuitarString(int string_number, int num_frets){
    
    num_frets = num_frets;
    determine_base_note_info(string_number);
    
    frets = new GuitarNote*[num_frets];
    
    int octave = base_note->getOctave();
    
    NoteLetter note_letter = NoteLetter(base_note->getNoteType());
    
    for (int fret_number = 0; fret_number < num_frets; fret_number++){
      
      NoteLetterType letter;
      
      try{
        letter = note_letter.getNote(fret_number);
      }catch (std::exception e){
        std::cerr << "Error: Fatal GuitarString initialization error";
        letter = NoteLetterType::NULL_NOTE;
      }
      /* if (fret_number != 0 && (fret_number % 12) == 0)
      octave ++;*/
   if (letter == NoteLetterType::C)
    octave ++;
      frets[fret_number] = 
         new GuitarNote
            (letter,
             octave,
             fret_number, 
             string_number);
      
   
    }
      
  }
  
  /**
   * Determines the open note information based on the given string number
   * <p>
   * The following assumptions are made on the string index:
   * <p>
   * String Index | Base String <p>
   * --------------------------- <p>
   *      1       |      E <p>
   *      2			  | 		 A <p>
   *      3				|			 D <p>
   *      4				|			 G <p>
   *      5				|			 B <p>
   *      6				|			 E <p>
   *      
   * @param string_number
   * @return
   */
  void GuitarString::determine_base_note_info(int string_number){
    switch(string_number){
      case LOW_E_STRING: 
        base_note = new GuitarNote(NoteLetterType::E,2,OPEN_FRET_NUM,LOW_E_STRING);
        break;
      case A_STRING: 
        base_note = new GuitarNote(NoteLetterType::A, 2, OPEN_FRET_NUM, A_STRING);
        break;
      case D_STRING: 
        base_note = new GuitarNote(NoteLetterType::D, 3, OPEN_FRET_NUM, D_STRING);
        break;
      case G_STRING: 
        base_note = new GuitarNote(NoteLetterType::G, 3, OPEN_FRET_NUM, G_STRING);
        break;
      case B_STRING: 
        base_note = new GuitarNote(NoteLetterType::B, 3, OPEN_FRET_NUM, B_STRING);
        break;
      case HIGH_E_STRING: 
        base_note = new GuitarNote(NoteLetterType::E, 3, OPEN_FRET_NUM, HIGH_E_STRING);
        break;
      default:

        base_note = new GuitarNote(NoteLetterType::NULL_NOTE,-1000,-1,-1);
        break;
    }
  }
    
  /**
   * Gets the <Class>GuitarNote</Class> mapped to the fret number on the string
   * @param fret_number fret number to get the note for 
   * @return guitar note mapped to the fret number on the string
   */
  const GuitarNote & GuitarString::getNoteElement(int fret_number) const{ return *(frets[fret_number]); }
  
  /**
   * Gets the number of frets mapped to the string
   * @return number of frets mapped to the string
   */
  int GuitarString::getNumberFrets() const{ return num_frets; }
 
  /**
   * Gets the value of the open note on the string
   * @return value of the open note on the string
   */
  NoteLetter GuitarString::getBaseStringLetter(){ return base_note->getNoteLetter(); }
  
