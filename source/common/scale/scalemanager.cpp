/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */


#include "scalemanager.hpp"
#include "invalidnoteexception.hpp"
#include "chordtype.hpp"
using namespace arias::common;
#include <vector>

  /**
   * Constructor for the Scale_Manager class
   *
   * @param  scale root note for the scale to initialize the class in
   * <p>
   * By default the class uses sharps unless the root note specified is a
   * flat note.
   *
   */
  ScaleManager::ScaleManager(NoteLetterType scale){ 

    distribution = std::uniform_int_distribution<int> (1, SCALE_NOTES);
	  this->scale = NoteLetter(scale); 
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
  ScaleManager::ScaleManager(NoteLetter scale, bool use_flats)
  {
  	
    //this.note_utilities = new NoteLetter(scale, use_flats);
	  this->scale = scale;
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
  Chord ScaleManager::getChord(InstrumentOctave interval) const
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

  /**
   * Gets the relative scale of the root depending on the scale. If the scale 
   * is a major scale then the relative minor is computed. If the scale is
   * a minor scale the the relative major is computed.
   * 
   * @return relative scale of the initialized note.
   * 
   */
  Chord ScaleManager::getRelativeScale() { return Chord(); }
  
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
	
    //int octave = interval / SCALE_NOTES;
    int scale_interval = interval % SCALE_NOTES; 
        
    return scale.getNote
            ( toHalfSteps(scale_interval));
	
  }
  
  /**
   * Gets a random interval between 1 - 8 inclusive from the root note
   * 
   * @return random interval
   */
  InstrumentOctave ScaleManager::getRandomInterval()
  {
   
    return distribution(generator);
    
  }

  /**
   * Generates a list of random chords having the size of the given parameter.
   * 
   * @param num_random_chords number of random chords needed to be generated
   * @return list of random chords
   */
  std::vector<Chord> ScaleManager::getRandomChords(int num_random_chords)
  {
	  
    std::vector<Chord> random_chords;
    int random_interval;
    
  	std::cerr << "random chords is : " << num_random_chords << std::endl;
    for(int i =0; i< num_random_chords; i++){
    	std::cerr << "random interval is : " << getRandomInterval() << std::endl;
    	do
    	  random_interval = getRandomInterval();
    	while (random_interval >= SCALE_NOTES - 1); // dont include 7th or 8th interval
    	
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
  
    InstrumentOctave interval_index = 1;
    for (; interval_index <=8; interval_index++){
      
      if (note == 
      		scale.getNote(this->getNote(interval_index))){
        break;
      }
    }
    return interval_index;
    
  }
    
namespace arias{
namespace common{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const ScaleManager& scale)
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

  return os;
}

}}