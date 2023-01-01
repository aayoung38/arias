/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "minorscalemanager.h"
#include "invalidnoteexception.h"
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
MinorScaleManager::MinorScaleManager(NoteLetterType scale) : ScaleManager(scale)
{ 
	halfStepsMap[0] = 0;
	halfStepsMap[1] = 2;
	halfStepsMap[2] = 3;
	halfStepsMap[3] = 5;
	halfStepsMap[4] = 7;
	halfStepsMap[5] = 8;
	halfStepsMap[6] = 10;
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
MinorScaleManager::MinorScaleManager(NoteLetterType scale, bool use_flats) : ScaleManager(scale, use_flats) 
{ 
}

/**
 * Gets the relative minor note of the initialized the root note.
 * <p>
 * The relative minor is assumed to be the 5th interval of the major scale
 *
 * @return a number in half steps from the root.
 */
Chord MinorScaleManager::getRelativeScale() const
{ 
	try {
		return Chord(getNote(RELATIVE_MAJOR_INTERVAL), Major);
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
MinorScaleManager MinorScaleManager::getRandomScale()
{
	try {
		InstrumentOctave t = rand.getInterval();
		InstrumentOctave t2 = rand.getInterval();
		InstrumentOctave t3 = rand.getInterval();
		//std::cout << "************\n";
		//std::cout << "-> "<<t << " " << t2 << " "<< t3 << std::endl;
		//std::cout << "************\n";
		return MinorScaleManager(getNote(rand.getInterval()), use_flats);
	} catch (InvalidNoteException e) {			
		std::cerr << "Error getting relative scale\n";
		return MinorScaleManager(NULL_NOTE);
	}
}

/*
* Equality operator
*/
bool MinorScaleManager::operator==(const MinorScaleManager & mgr) const{
	return scale.getNote() == mgr.scale.getNote();
}

/*
* Inequality operator
*/
bool MinorScaleManager::operator!=(const MinorScaleManager & mgr) const{
	return scale.getNote() != mgr.scale.getNote();
}

namespace arias{
namespace common{
namespace scale{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const MinorScaleManager& scale)
{
  for (InstrumentOctave interval_index = 1; interval_index <=8; interval_index++)
  {
	  	os << scale.getChord(interval_index) << ", ";
  }
  os << + " (relative major = " << scale.getRelativeScale() << ")\n";
  return os;
}

}}}