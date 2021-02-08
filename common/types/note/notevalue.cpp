/**
 * @author      Adam Young <aayoung38@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "notevalue.hpp"
#include "notevaluetype.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace arias::common::types::note;

NoteValue::NoteValue(NoteValueType value) : n_value(value)
{
	noteMapInfo[NoteValueType::WHOLE] = WHOLE_NOTE_VALUE;
	noteMapInfo[NoteValueType::HALF] = HALF_NOTE_VALUE;
	noteMapInfo[NoteValueType::QUARTER] = QUARTER_NOTE_VALUE;
	noteMapInfo[NoteValueType::EIGHTH] = EIGHTH_NOTE_VALUE;
	noteMapInfo[NoteValueType::SIXTEENTH] = SIXTEENTH_NOTE_VALUE;
	noteMapInfo[NoteValueType::NONE] = NULL_NOTE_VALUE;

	// initialize random number
	srand(time(NULL));
}

NoteValueType NoteValue::getType() const{ return n_value; }

float NoteValue::getBeats() const
{ 
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
void NoteValue::setRandomValue(float beats_left)
{
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

namespace arias{
namespace common{
namespace types{
namespace note{
std::ostream& operator <<(std::ostream & os, const NoteValue & note) 
{
	os << "Type: " << note.n_value 
     << ", Value: " << std::to_string(note.getBeats());

  return os;
}
}
}
}
}