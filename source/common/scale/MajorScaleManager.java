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
public class MajorScaleManager extends ScaleManager {

	protected static final int RELATIVE_MINOR_INTERVAL = 6;

	/**
	 * Constructor for the Major_Scale_Manager class
	 *
	 * @param  scale root note for the scale to initialize the class in
	 * <p>
	 * By default the class uses sharps unless the root note specified is a
	 * flat note.
	 */
	public MajorScaleManager(NoteLetterType scale)
	{ 
		super(scale); 
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
	public MajorScaleManager(NoteLetter scale, boolean use_flats) throws InvalidNoteException
	{ 
		super(scale, use_flats); 
		
	}



	/**
	 * Gets the relative minor note of the initialized the root note.
	 * <p>
	 * The relative minor is assumed to be the 5th interval of the major scale
	 *
	 * @return a number in half steps from the root.
	 */
	@Override
	public String getRelativeScale(){ 
		try {
		return getNote(RELATIVE_MINOR_INTERVAL);
	} catch (InvalidNoteException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		return "";
	} 
		}

	/**
	 * Gets a new random scale in any major key 
	 *
	 * @return a new <class>MajorScaleManager</class> object initialized to 
	 *         the random scale.
	 */
	public static MajorScaleManager getRandomScale(){

		Random generator = new Random();

		try {
			return new MajorScaleManager(new NoteLetter(generator.nextInt(8) + 1),false);
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

		return super.toString() + " (relative minor = " + 
				this.getRelativeScale() +")\n";

	}


}
