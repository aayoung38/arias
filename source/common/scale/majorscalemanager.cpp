/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "majorscalemanager.h"
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
 * Gets a chord in the key of the initialized root note using the interval as 
 * the distance from the root. 
 *
 * @param  interval a number between (1-8) which represents the interval of 
 *         the root note. If the number is greater than 8 it is assumed to be
 *         in a higher octave.
 * @return a chord from the given interval of the root in the scale of the 
 *         initialized root note as a string.
 * @throws InvalidNoteException 
 * @see    String
 */
Chord MajorScaleManager::getChord(InstrumentOctave interval) const
{

  int scale_interval = interval % SCALE_NOTES; 
      
  NoteLetterType note = 
      scale.getNote( toHalfSteps(scale_interval));

  
  ChordType _chord; 
  switch(interval){
    case 2: case 3: case 6: 
      _chord = Minor;
      break;
    case 7: 
      _chord = Diminished;
      break;
    default:
      _chord = Major;
      break;
  }

  return Chord(note, _chord);

}

InstrumentOctave MajorScaleManager::diminishedInterval() const {return 7;};
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
		return MajorScaleManager(NoteLetter(getNote((InstrumentOctave) getRandomInterval())), false);
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