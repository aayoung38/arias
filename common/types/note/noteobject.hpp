/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */
#pragma once

#include "invalidnoteexception.hpp"
#include "notelettertype.hpp"
#include "notevalue.hpp"
#include "noteletter.hpp"
#include <stdlib.h>
#include <math.h>

namespace arias{
namespace common{
namespace types{
namespace note{

class NoteObject {

	
	/**
	 * Default constructor
	 */

  public:
    NoteObject();

  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @throws InvalidNoteException 
   */
   NoteObject(NoteLetterType note, int octave);
  
  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @throws InvalidNoteException 
   */
  NoteObject(NoteLetterType note, int octave, bool isRest);
  
  /**
   * Constructor 
   * 
   * @param note note letter to initialize the note to
   * @param octave octave to initialize the note to
   * @param note_value note value to initialize the note to, see NoteValue enum
   * @throws InvalidNoteException 
   */
  NoteObject(NoteLetterType note, int octave, NoteValueType note_value);

  
  /**
   * Gets the octave of the note.
   * @return octave of the note
   */
  int getOctave() const;

  /**
   * Gets the letter value of the note
   * 
   * @return letter value of the note
   */
   NoteLetter getNoteLetter() const;
	
	/**
	 * Gets a description of the value of the note currently set.
	 * <p>
	 * See NoteValue
	 *   
	 * @return string description of the note value
	 */
	std::string getBeatName() const;
  
	/**
	 * Sets the note instance's beat to a random beat value based off of how many
	 * beats are left over in the measure. 
	 * <p>
	 * Only beat values that fit in the amount of beats left are candidates for 
	 * random selection
	 * @param beats_left how many beats are left in a given measure of music
	 */
	 void setRandomBeat(float beats_left);

  /**
   * Gets the letter type value of the note
   * 
   * @return letter value of the note
   */
   NoteLetterType getNoteType() const;
  /**
   * Gets the letter type value of the note
   * 
   * @return letter value of the note
   */
   double getFrequency() const;
  
	/**
	 * Gets the rest value of the note
	 * 
	 * @return rest value of the note
	 */
	std::string getRestValue() const;
	
	/**
	 * Gets the letter value of a null note
	 * 
	 * @return letter value of a null note
	 */
   static NoteObject getNullNote();
  
  
  /**
   * Sets the note information to null.
   */
  void setNull();
  
  /**
   * Determines if the note is null
   * 
   * @return True if the note is null and False otherwise
   */
   bool isNull();

  
  /**
   * Determines if the note is a rest
   * @return True if the note is a rest and False otherwise
   */
   bool isRest();
  
  
  /**
   * Gets the type of the note 
   *<p>
   * See NoteType enum
   */
	NoteValue getValue() const;
  
	/**
	 * Sets the note instance as a note or a rest. 
	 * <p>
	 * There is a 25% chance of the note being a rest.
	 */
    void selectRestOrNote();
  
	/**
	 * Converts the class to string
	 * @return string representation of the class
	 */
	std::string toString();
	

  protected:
    const int NUMBER_NOTES = NoteLetter::getNumberNotes();
    static constexpr int  NULL_OCTAVE = -1000;
    NoteValue note_value;
	NoteLetter note_letter;
	int octave;

	double frequency;
	
	// boolean to indicate whether a note is a rest or not.
	bool note_is_rest;

  private:

   // Semitone Frequency Intervals - 2 ^ 1/12
   //static constexpr double FREQUENCY_CONSTANT = pow(2.0,1.0/12.0);
   static constexpr double SEMITONE_HZ_CONSTANT = 1.05946309436;
  
   // Frequency based on C0 note
   static constexpr double REFERENCE_NOTE_FREQUENCY = 16.35; 
   static constexpr NoteLetterType REFERENCE_NOTE_LETTER = NoteLetterType::C;
   static constexpr int REFERENCE_NOTE_OCTAVE = 0;
   static constexpr double NULL_FREQUENCY = -1.0;

/**
   * The basic formula for the frequencies of the notes of the equal tempered 
   * scale is given by:
   *   fn = f0 * (a)n 
   * 
   * where: 
   *   f0 = the frequency of one fixed note which must be defined. A common 
   *        choice is setting the A above middle C (A4) at f0 = 440 Hz.
   *        
   *   n = the number of half steps away from the fixed note you are. If you
   *       are at a higher note, n is positive. If you are on a lower note, 
   *       n is negative.
   *       
   *   fn = the frequency of the note n half steps away.
   *   
   *    a = (2)1/12 = the twelth root of 2 = the number which when multiplied 
   *        by itself 12 times equals 2 = 1.059463094359... 
   * @throws InvalidNoteException 
   *   
   */
   void computeFrequency();

	
  /**
   * Sets the note type to a random value.
   * <p>
   * See NoteType for types
   */
   void setRandomBeatVal();
};

}
}
}
}
