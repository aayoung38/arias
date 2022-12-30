/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "majorscalemanager.hpp"
#include "invalidnoteexception.hpp"
using namespace arias::common::scale;
using namespace arias::common::exceptions;
using namespace arias::common::types::note;

/**
* Constructor for the Major_Scale_Manager class
*
* @param  scale root note for the scale to initialize the class in
* <p>
* By default the class uses sharps unless the root note specified is a
* flat note.
*/
MajorScaleManager::MajorScaleManager(NoteLetterType scale) : ScaleManager(scale)
{ 
  halfStepsMap[0] = 0;
	halfStepsMap[1] = 2;
	halfStepsMap[2] = 4;
	halfStepsMap[3] = 5;
	halfStepsMap[4] = 7;
	halfStepsMap[5] = 9;
	halfStepsMap[6] = 11;
	halfStepsMap[7] = 12;
}

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
MajorScaleManager::MajorScaleManager(NoteLetter scale, bool use_flats) : ScaleManager(scale, use_flats) 
{ 
}

/**
 * Gets the relative minor note of the initialized the root note.
 * <p>
 * The relative minor is assumed to be the 5th interval of the major scale
 *
 * @return a number in half steps from the root.
 */
Chord MajorScaleManager::getRelativeScale() const
{ 
	try {
		return Chord(getNote(RELATIVE_MINOR_INTERVAL), Minor);
	} catch (InvalidNoteException e) {
		std::cerr << "Error getting relative scale";
        return Chord(NULL_NOTE, NULL_CHORD);;
	} 
}

/**
 * Gets a new random scale in any major key 
 *
 * @return a new <class>MajorScaleManager</class> object initialized to 
 *         the random scale.
 */
MajorScaleManager MajorScaleManager::getRandomScale()
{
	try {
		return MajorScaleManager(NoteLetter(getNote(rand.getInterval())), false);
	} catch (InvalidNoteException e) {			
		std::cerr << "Error getting relative scale";
		return MajorScaleManager(NULL_NOTE);
	}

}

namespace arias{
namespace common{
namespace scale{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const MajorScaleManager& scale)
{
  for (InstrumentOctave interval_index = 1; interval_index <=8; interval_index++)
  {
    try {
	  	os << scale.getChord(interval_index) << ", ";
	  } catch (exceptions::InvalidNoteException &e) {
	  	// TODO Auto-generated catch block
	  	os << "Invalid note exception error\n";
	  }
  }
  os << + " (relative minor = " << scale.getRelativeScale() << ")\n";
  return os;
}

}}}