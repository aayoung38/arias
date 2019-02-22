/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common;

import java.util.Random;

import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.types.note.NoteLetter;
import com.ariasproj.common.types.note.NoteLetterType;

/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-04-04          
 */
public class MinorScaleManager extends ScaleManager {

	protected static final int RELATIVE_MAJOR_INTERVAL = 3;
	//protected static final int [] halfStepsMap = {0,0,2,3,5,7,8,10,12};

	/**
	 * Contructor for the Mijor_Scale_Manager class
	 *
	 * @param  scale root note for the scale to initialize the class in
	 * <p>
	 * By default the class uses sharps unless the root note specified is a
	 * flat note.
	 */
	public MinorScaleManager(NoteLetterType scale){
		super(scale);
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
	 * Contructor for the Mijor_Scale_Manager class
	 *
	 * @param  scale root note for the scale to initialize the class in
	 * <p>
	 * By default the class uses sharps unless the root note specified is a
	 * flat note.
	 */
	//protected MinorScaleManager(int scale){ super(scale); }

	/**
	 * Contructor for the Major_Scale_Manager class
	 *
	 * @param  scale root note for the scale to initialize the class in
	 * @param  use_flats boolean that when true uses represents notes in terms 
	 *         of flats rather than sharps.
	 * @throws InvalidNoteException 
	 * 
	 */  
	public MinorScaleManager(NoteLetter scale, boolean use_flats) throws InvalidNoteException{ super(scale, use_flats); }

	/**
	 * Gets a chord in the key of the initialized root note using the interval as 
	 * the distance from the root. 
	 *
	 * @param  interval a number between (1-8) which represents the interval of 
	 *         the root note. If the number is greater than 8 it is assumed to be
	 *         in a higher octave.
	 * @return a chord from the given interval of the root in the scale of the 
	 *         initialized root note as a string.
	 * @see    String
	 */
	@Override
	public String getChord(int interval){

		int scale_interval = interval % SCALE_NOTES; 
		String chord = "";

		String computed_note = "";
		try {
			computed_note = this.scale.numberToNote(toHalfSteps(scale_interval));
		} catch (InvalidNoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		switch(interval){
		case 1: case 2: case 4: case 5: 
			chord = "min";
			break;
		default:
			break;
		}

		return computed_note + chord;

	}

	/**
	 * Gets the relative minor note of the initialized the root note.
	 * <p>
	 * The relative minor is assumed to be the 5th interval of the major scale
	 *
	 * @return a number in half steps from the root.
	 */
	@Override
	public String getRelativeScale(){ try {
		return getNote(RELATIVE_MAJOR_INTERVAL);
	} catch (InvalidNoteException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		return "";
	} }

	/**
	 * Gets a new random scale in any minor key 
	 *
	 * @return a new <class>MinorScaleManager</class> object initialized to 
	 *         the random scale.
	 */
	public static MinorScaleManager getRandomScale(){

		Random generator = new Random();

		try {
			return new MinorScaleManager(new NoteLetter(generator.nextInt(SCALE_NOTES) + 1),false);
		} catch (InvalidNoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}

	}

	/**
	 * Converts the Scale_Manager object to string
	 * 
	 * @return String representation of the Scale_Manager object.
	 * @see Scale_Manager
	 */
	public String toString(){

		return super.toString() + " (relative major = " + 
				this.getRelativeScale() +")\n";

	}


}
