/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include "invalidnoteexception.hpp"
#include "notelettertype.hpp"
#include "noteobject.hpp"
#include "notevaluetype.hpp"

using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace types{
namespace instrument{
namespace guitar{

class GuitarNote : public NoteObject{

	public:

  /**
   * Constructor
   */
  GuitarNote();
  
  int getNullStringNumber();

  /**
   * Constructor
   * @param noteLetterType guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
   GuitarNote(NoteLetterType noteLetterType, int octave, int fret_number, int string_number);

  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   * @throws InvalidNoteException 
   */
   GuitarNote(NoteLetterType note, 
  			int octave, 
  			int fret_number, 
  			int string_number, 
  			NoteValueType beat_number);
  
  /**
   * Constructor
   * @param note guitar note to initialize with
   * @param fret_number fret number between 0 - 21 to initialize the note with
   * @param string_number string number between 1 - 6 to initialize the note with
   */
   GuitarNote(const GuitarNote & note);
  
  /**
   * Obtains the fret number for the note instance
   * @return fret number
   */
   int getFretNumber() const;
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
   int getStringNumber() const;
  
  /**
   * Obtains the string number for the note instance
   * @return string number
   */
   double getFrequency() const;
  
  /**
   * Assigns the guitar notes positional information on the guitar
   * <p>
   * The guitar note isn't modified and so the given positions should logically
   * produce the same note the guitar note was initialize with 
   * @param fret_number fret number to change the note position to
   * @param string_number string number to change the note position to
   */
   void setNote(int fret_number, int string_number, float frequency);

  /**
   * Assigns the guitar note's string number 
   * <p>
   * This method should only be called when setting string numbers of
   * rest notes.
   * 
   * @param string_number string number to change the note position to
   */
   void setStringNumber(int string_number);

   std::string toString();

   private:

   int fret_number;
   int string_number;
  
   static constexpr int NULL_STRING_NUMBER = -1;  
   static constexpr int NULL_FRET_NUMBER = -1;
  
};
}
}
}
}
}
