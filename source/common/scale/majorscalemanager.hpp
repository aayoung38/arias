/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "noteletter.hpp"
#include "notelettertype.hpp"
#include "scalemanager.hpp"

using namespace arias::common::types;
using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace scale{

class MajorScaleManager : ScaleManager {

  public:

		/**
		 * Constructor for the Major_Scale_Manager class
		 *
		 * @param  scale root note for the scale to initialize the class in
		 * <p>
		 * By default the class uses sharps unless the root note specified is a
		 * flat note.
		 */
		MajorScaleManager(NoteLetterType scale);

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
		MajorScaleManager(NoteLetter scale, bool use_flats);

		/**
		 * Gets the relative minor note of the initialized the root note.
		 * <p>
		 * The relative minor is assumed to be the 5th interval of the major scale
		 *
		 * @return a number in half steps from the root.
		 */
		Chord getRelativeScale() const;

		/**
		 * Gets a new random scale in any major key 
		 *
		 * @return a new <class>MajorScaleManager</class> object initialized to 
		 *         the random scale.
		 */
			MajorScaleManager getRandomScale();

		/**
		 * Converts the <Class>ScaleManager</Class> object to string
		 * 
		 * @return String representation of the Scale_Manager object.
		 * @see ScaleManager
		 */

		friend std::ostream & operator << (std::ostream &, const MajorScaleManager& scale);

	protected:
    static const int RELATIVE_MINOR_INTERVAL = 6;

};

}
}
}
