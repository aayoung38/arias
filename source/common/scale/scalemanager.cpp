/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */


#include "scalemanager.h"
#include "invalidnoteexception.h"
#include "notenotinscaleexception.h"
#include "chordtype.h"
#include <vector>
#include <random>
using namespace arias::common::types;
using namespace arias::common::scale;
using namespace arias::common::exceptions;

/**
* Constructor for the Scale_Manager class
*
* @param  scale root note for the scale to initialize the class in
* <p>
* By default the class uses sharps unless the root note specified is a
* flat note.
*
*/
ScaleManager::ScaleManager(NoteLetterType _scale) :  scale(_scale), 
                                                     use_flats(false)
{ 
}

/**
 * Constructor for the Scale_Manager class
 *
 * @param  scale root note for the scale to initialize the class in
 * <p>
 * By default the class uses sharps unless the root note specified is a
 * flat note.
 * @param  use_flats boolean that when true uses represents notes in terms 
 *         of flats rather than sharps.
 * @throws InvalidNoteException 
 */
ScaleManager::ScaleManager(NoteLetter _scale, bool _use_flats) : scale(_scale), 
                                                                 use_flats(_use_flats)
{
}
  
/**
 * Computes the number of half steps from the root given the interval from 
 * the root.
 *
 * @param  interval a number between (1-8) which represents the interval of 
 *         the root note. If the number is greater than 8 it is assumed to be
 *         in a higher octave.
 * @return a number in half steps from the root.
 */
int ScaleManager::toHalfSteps(InstrumentOctave interval) const { 
  
    return interval < 9 && interval > 0 ? halfStepsMap[interval-1] : 0; }
  

//uint32_t ScaleManager::getRandomInterval()
//{ 
  
  // Lehmer32 method
  //nLehmer += 0xe120fc15;
  //uint64_t tmp;
  //tmp = (uint64_t)nLehmer * 0x4a39b70d;
  //uint32_t m1 = (tmp >> 32) ^ tmp;
  //tmp = (uint64_t)m1 * 0x12fad5c9;
  //uint32_t m2 = (tmp >> 32) ^ tmp;
  //std::cout << "rand = " << tmp << " " << (tmp % SCALE_NOTES);
//  return dist(mt); 
//}

/**
 * Gets the note in the interval of the initialized root note.
 * 
 * @param interval - range 1 .. 8
 * @return computed note in the scale of the initialized note as a string.
 * @throws InvalidNoteException 
 * 
 */
NoteLetterType ScaleManager::getNote(InstrumentOctave interval) const
{

  if (scale.getNote() == NULL_NOTE)
    throw InvalidNoteException();
  //int octave = interval / SCALE_NOTES;
  int scale_interval = interval % SCALE_NOTES; 
      
  return scale.getNote
          ( toHalfSteps(scale_interval));

}

/**
 * Generates a list of random chords having the size of the given parameter.
 * 
 * @param num_random_chords number of random chords needed to be generated
 * @return list of random chords
 */
std::vector<Chord> ScaleManager::getRandomChords(int num_random_chords)
{
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<uint32_t> dist(1,SCALE_NOTES);

  //nLehmer = time(NULL);
  std::vector<Chord> random_chords;
  InstrumentOctave random_interval;

  for(int i =0; i< num_random_chords; i++){
    do{
      random_interval = dist(mt);
    }
    while (random_interval == diminishedInterval()); // dont include 7th or 8th interval
    
    try {
      random_chords.push_back(getChord(random_interval));
    } catch (exceptions::InvalidNoteException & e) {
      std::cerr << "Error adding random chord\n";
    }
  }
  
  return random_chords;
  
}

/**
 * Determines if the given note is in the initialized scale
 * @param note note to be checked
 * @return true if the note is in the scale and false otherwise
 * @throws InvalidNoteException 
 */
bool ScaleManager::noteInScale(NoteLetterType note)
{

  bool note_in_scale = false;
  for (int interval_index = 1; interval_index <=8; interval_index++){
    
    try {
      if (note == 
          scale.getNote(this->getNote(interval_index))){
        note_in_scale = true;
        break;
      }
    } catch (exceptions::InvalidNoteException &e) {
      return false;
    }
  }
  return note_in_scale;
  
}

/**
 * Gets the interval the given note is from the initialized scale root note
 * 
 * @param noteLetterType
 * @return number of intervals from the root note.
 * @throws InvalidNoteException 
 */
InstrumentOctave ScaleManager::getInterval(NoteLetterType note)
{

  InstrumentOctave interval_index = -1;
  for (InstrumentOctave i=1; i <=8; i++){
    
    if (note == 
        scale.getNote(this->getNote(i))){
      interval_index = i;
      break;

    }
  }

  if (interval_index == -1)
  {
    throw NoteNotInScaleException();
  }
  return interval_index;
  
}
    
namespace arias{
namespace common{
namespace scale{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const ScaleManager& scale)
{
  if (scale.scale.getNote() == NULL_NOTE){
    os << "Rest Note";
  }
  else
  {
    for (InstrumentOctave interval_index = 1; interval_index <=8; interval_index++)
    {
	  	os << scale.getChord(interval_index) << ", ";
    }
  }

  return os;
}

}}}