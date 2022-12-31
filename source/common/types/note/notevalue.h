/**
 * @author      Adam Young <aayoung38@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include <iostream>
#include <map>
#include <string.h>
#include "notevaluetype.h"

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

    friend std::ostream& operator << (std::ostream& os, const NoteValue& g);
  
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
	
};

} // note 
} // types
} // common
} // arias