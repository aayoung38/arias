/**
 * @author      Adam Young <aayoung38@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

namespace ariasproj{
namespace common{
namespace types{
namespace note{

#include <map>
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
	
  private:
	 std::map<NoteValueType, float> noteMapInfo;
     NoteValueType type;
     void initializeNoteMap(){
		 
  public:
    NoteValue(NoteValueType value){
    	this.type = value;

    	this.initializeNoteMap();
    }

  /**
   * Initializes the note value map by mapping the note type to the number of
   * beats the value has. 
   */
	private void initializeNoteMap(){
		this.noteMapInfo = new HashMap<NoteValueType,Float>();
		this.noteMapInfo.put(NoteValueType.WHOLE, WHOLE_NOTE_VALUE);
		this.noteMapInfo.put(NoteValueType.HALF, HALF_NOTE_VALUE);
		this.noteMapInfo.put(NoteValueType.QUARTER, QUARTER_NOTE_VALUE);
		this.noteMapInfo.put(NoteValueType.EIGHTH, EIGHTH_NOTE_VALUE);
		this.noteMapInfo.put(NoteValueType.SIXTEENTH, SIXTEENTH_NOTE_VALUE);
		this.noteMapInfo.put(NoteValueType.NULL, NULL_NOTE_VALUE);
	}
	
  public NoteValueType getType(){ return this.type; }
	
  public float getBeats(){ return this.noteMapInfo.get(this.type); }
  
	/**
	 * Sets the note instance's beat to a random beat value based off of how many
	 * beats are left over in the measure. 
	 * <p>
	 * Only beat values that fit in the amount of beats left are candidates for 
	 * random selection
	 * @param beats_left how many beats are left in a given measure of music
	 */
	public void setRandomValue(float beats_left){
  	ArrayList<NoteValueType> beat_list = new ArrayList<NoteValueType>();
  	
  	if (this.noteMapInfo.get(NoteValueType.WHOLE) <= beats_left) 
  		beat_list.add(NoteValueType.WHOLE);
  	if (this.noteMapInfo.get(NoteValueType.HALF) <= beats_left)
  		beat_list.add(NoteValueType.HALF);
  	if (this.noteMapInfo.get(NoteValueType.QUARTER) <= beats_left)
  		beat_list.add(NoteValueType.QUARTER);
  	if (this.noteMapInfo.get(NoteValueType.EIGHTH) <= beats_left)
  		beat_list.add(NoteValueType.EIGHTH);
  	if (this.noteMapInfo.get(NoteValueType.SIXTEENTH) <= beats_left)
  		beat_list.add(NoteValueType.SIXTEENTH);
  	
    Random generator = new Random();
    
    this.type = beat_list.get(generator.nextInt(beat_list.size()));
 
  }
	
  std::string output(){
  	return "Type: "+this.type+", Value: "+this.getBeats();
  }
  
}
