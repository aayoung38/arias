/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "noteletter.h"
#include "notelettertype.h"
#include "scalemanager.h"

using namespace arias::common::types;
using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace scale{

class MinorScaleManager : public ScaleManager {

  public:

		/**
	 	* Constructor for the Major_Scale_Manager class
	 	*
	 	* @param  scale root note for the scale to initialize the class in
	 	* <p>
	 	* By default the class uses sharps unless the root note specified is a
	 	* flat note.
	 	*/
		MinorScaleManager(NoteLetterType scale);

		/**
	 	* Constructor for the Major_Scale_Manager class
	 	*
	 	* @param  scale root note for the scale to initialize the class in
	 	* <p>
	 	* By default the class uses sharps unless the root note specified is a
	 	* flat note.
	 	*/
		//protected MajorScaleManager(int scale){ super(scale); }

		/**
	 	* Constructor for the Major_Scale_Manager class
	 	*
	 	* @param  scale root note for the scale to initialize the class in
	 	* @param  use_flats boolean that when true uses represents notes in terms 
	 	*         of flats rather than sharps.
	 	* @throws InvalidNoteException 
	 	* 
	 	*/  
		MinorScaleManager(NoteLetterType scale, bool use_flats);

		/**
	 	* Gets the relative minor note of the initialized the root note.
	 	* <p>
	 	* The relative minor is assumed to be the 5th interval of the major scale
	 	*
	 	* @return a number in half steps from the root.
	 	*/
		Chord getRelativeScale() const;
    InstrumentOctave diminishedInterval() const;

    Chord getChord(InstrumentOctave interval)const;
		/**
	 	* Gets a new random scale in any major key 
	 	*
	 	* @return a new <class>MajorScaleManager</class> object initialized to 
	 	*         the random scale.
	 	*/
    MinorScaleManager getRandomScale();

    bool operator==(const MinorScaleManager &) const;
    bool operator!=(const MinorScaleManager &) const;

  	/**
  	* Converts the <Class>ScaleManager</Class> object to string
   	* 
   	* @return String representation of the Scale_Manager object.
   	* @see ScaleManager
   	*/
		friend std::ostream & operator << (std::ostream &, const MinorScaleManager& scale);

	protected:
    static const int RELATIVE_MAJOR_INTERVAL = 3;
	

};

}
}
}
