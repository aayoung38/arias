/**
 * @author      Adam Young <aayoung38@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include <map>
#include <string.h>
#include "notevaluetype.hpp"

namespace arias{
namespace common{
namespace types{
namespace note{

class NoteValue {

  public:

    NoteValue() = default;
    NoteValue(NoteValueType value);

    NoteValueType getType() const;
	
    float getBeats() const;
  
		/**
		 * Sets the note instance's beat to a random beat value based off of how many
		 * beats are left over in the measure. 
		 * <p>
		 * Only beat values that fit in the amount of beats left are candidates for 
		 * random selection
		 * @param beats_left how many beats are left in a given measure of music
		 */
		void setRandomValue(float beats_left);

		std::string toString() const;
  
  protected:

	  static constexpr float WHOLE_NOTE_VALUE     = 4.0;
	  static constexpr float HALF_NOTE_VALUE      = 2.0;
 	  static constexpr float QUARTER_NOTE_VALUE   = 1.0;
 	  static constexpr float EIGHTH_NOTE_VALUE    = 0.5;
	  static constexpr float SIXTEENTH_NOTE_VALUE = 0.25;
	  static constexpr float NULL_NOTE_VALUE      = -1.0;
	
  private:
	  std::map<NoteValueType, float> noteMapInfo;
    NoteValueType n_value;
	
	  /**
     * Initializes the note value map by mapping the note type to the number of
     * beats the value has. 
     */
    void initializeNoteMap();
};

} // note 
} // types
} // common
} // arias