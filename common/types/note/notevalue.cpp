/**
 * @author      Adam Young <aayoung38@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "notevalue.hpp"
#include "notevaluetype.hpp"
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace arias::common::types::note;

/*import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

  private:
	 std::map<NoteValueType, float> noteMapInfo;
     NoteValueType type;
     void initializeNoteMap(){
*/		  

    NoteValue::NoteValue(NoteValueType value) : n_value(value){
    	
    	this->initializeNoteMap();

		// initialize random number
		srand(time(NULL));
    }

  /**
   * Initializes the note value map by mapping the note type to the number of
   * beats the value has. 
   */
	void NoteValue::initializeNoteMap(){
		this->noteMapInfo[NoteValueType::WHOLE] = WHOLE_NOTE_VALUE;
		this->noteMapInfo[NoteValueType::HALF] = HALF_NOTE_VALUE;
		this->noteMapInfo[NoteValueType::QUARTER] = QUARTER_NOTE_VALUE;
		this->noteMapInfo[NoteValueType::EIGHTH] = EIGHTH_NOTE_VALUE;
		this->noteMapInfo[NoteValueType::SIXTEENTH] = SIXTEENTH_NOTE_VALUE;
		this->noteMapInfo[NoteValueType::NONE] = NULL_NOTE_VALUE;
	}
	
  NoteValueType NoteValue::getType() const{ return n_value; }
	
  float NoteValue::getBeats() const{ 
	  return noteMapInfo.find(n_value)->second;
  }
  
	/**
	 * Sets the note instance's beat to a random beat value based off of how many
	 * beats are left over in the measure. 
	 * <p>
	 * Only beat values that fit in the amount of beats left are candidates for 
	 * random selection
	 * @param beats_left how many beats are left in a given measure of music
	 */
  void NoteValue::setRandomValue(float beats_left){
  	std::vector<NoteValueType> beat_list;
  	
  	if (noteMapInfo[NoteValueType::WHOLE] <= beats_left) 
  		beat_list.push_back(NoteValueType::WHOLE);
  	if (noteMapInfo[NoteValueType::HALF] <= beats_left)
  		beat_list.push_back(NoteValueType::HALF);
  	if (noteMapInfo[NoteValueType::QUARTER] <= beats_left)
  		beat_list.push_back(NoteValueType::QUARTER);
  	if (noteMapInfo[NoteValueType::EIGHTH] <= beats_left)
  		beat_list.push_back(NoteValueType::EIGHTH);
  	if (noteMapInfo[NoteValueType::SIXTEENTH] <= beats_left)
  		beat_list.push_back(NoteValueType::SIXTEENTH);
  
    n_value = beat_list.at(rand()% beat_list.size());
 
  }
	
  std::string NoteValue::toString() const{
  	return "Type: "+std::to_string(n_value)+", Value: "+std::to_string(getBeats());
  }
  