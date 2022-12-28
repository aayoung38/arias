/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */


#pragma once

#include "guitarnote.hpp"
#include "notelettertype.hpp"
#include "note.hpp"
#include "notevaluetype.hpp"
#include "instrumenttypes.hpp"
#include <memory>
#include <vector>

using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace types{
namespace instrument{
namespace guitar{

class GuitarString {

  public:
    static constexpr int LOW_E_STRING = 0;
    static constexpr int A_STRING = 1;
    static constexpr int D_STRING = 2;
    static constexpr int G_STRING = 3;
    static constexpr int B_STRING = 4;
    static constexpr int HIGH_E_STRING = 5;

    static constexpr InstrumentFret GUITAR_FRETS   = 22;

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
   GuitarString(InstrumentString string_number);
  
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
   void determine_base_note_info(InstrumentString string_number);
    
  /**
   * Gets the <Class>GuitarNote</Class> mapped to the fret number on the string
   * @param fret_number fret number to get the note for 
   * @return guitar note mapped to the fret number on the string
   */
   const GuitarNote & getNoteElement(InstrumentFret fret_number) const;
   
  /**
   * Gets the value of the open note on the string
   * @return value of the open note on the string
   */
   NoteLetter getBaseStringLetter();

	 friend std::ostream & operator << (std::ostream &, const GuitarString & note);

	private:

      std::array< std::unique_ptr<GuitarNote>, GUITAR_FRETS> frets;
      std::unique_ptr<GuitarNote> base_note;
      static constexpr int OPEN_FRET_NUM = 0;
  
};
}
}
}
}
}
