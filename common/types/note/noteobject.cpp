/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "noteobject.hpp"
#include "invalidnoteexception.hpp"
#include <stdlib.h>
#include <iostream>
using namespace arias::common::types::note;
using namespace arias::common::exceptions;
	
/**
 * Default constructor
 */
NoteObject::NoteObject()
{
  value = NoteValue(NoteValueType::WHOLE);
  letter = NoteLetter(NoteLetterType::NULL_NOTE);
  
  octave = NULL_OCTAVE;
  
  frequency = 0.0;
  
  // by default treat every new note as a non-rest note.
  note_is_rest = false;
}  

/**
 * Constructor 
 * 
 * @param note note letter to initialize the note to
 * @param octave octave to initialize the note to
 * @throws InvalidNoteException 
 */
NoteObject::NoteObject(NoteLetterType note, int octave)
{
  value = NoteValue(NoteValueType::WHOLE);
  letter = NoteLetter(note);
  
  octave = octave;
  computeFrequency();
  
  // by default treat every new note as a non-rest note.
  note_is_rest = false; 
}
  
/**
 * Constructor 
 * 
 * @param note note letter to initialize the note to
 * @param octave octave to initialize the note to
 * @throws InvalidNoteException 
 */
NoteObject::NoteObject(NoteLetterType note, int octave, bool isRest)
{
  value = NoteValue(NoteValueType::WHOLE);
  letter = NoteLetter(note);
  
  this->octave = octave;
  computeFrequency();
  
  // by default treat every new note as a non-rest note.
  note_is_rest = isRest; 
}
  
/**
 * Constructor 
 * 
 * @param note note letter to initialize the note to
 * @param octave octave to initialize the note to
 * @param note_value note value to initialize the note to, see NoteValue enum
 * @throws InvalidNoteException 
 */
NoteObject::NoteObject(NoteLetterType letter, int octave, NoteValueType value)
{
  this->value = NoteValue(value);
  this->letter = NoteLetter(letter);
  
  this->octave = octave;

  computeFrequency();
  
  // by default treat every new note as a non-rest note.
  note_is_rest = false; 
}

/**
 * Gets the octave of the note.
 * @return octave of the note
 */
int NoteObject::getOctave() const{ return octave;}

/**
 * Gets the letter value of the note
 * 
 * @return letter value of the note
 */
const NoteLetter & NoteObject::getLetter() const{ return letter; }
  
/**
 * Sets the note instance's beat to a random beat value based off of how many
 * beats are left over in the measure. 
 * <p>
 * Only beat values that fit in the amount of beats left are candidates for 
 * random selection
 * @param beats_left how many beats are left in a given measure of music
 */
void NoteObject::setRandomBeat(float beats_left){value.setRandomValue(beats_left);}

/**
 * Gets the letter type value of the note
 * 
 * @return letter value of the note
 */
NoteLetterType NoteObject::getNoteType() const{ return letter.getNote(); }
/**
 * Gets the letter type value of the note
 * 
 * @return letter value of the note
 */
double NoteObject::getFrequency() const{ return frequency; }
  
/**
 * Gets the rest value of the note
 * 
 * @return rest value of the note
 */
std::string NoteObject::getRestValue() const{ return "/"; }

/**
 * Gets the letter value of a null note
 * 
 * @return letter value of a null note
 */
NoteObject NoteObject::getNullNote() 
{
  return NoteObject(NoteLetterType::NULL_NOTE, NULL_OCTAVE,true); 
}
  
/**
 * Sets the note information to null.
 */
void NoteObject::setNull() 
{ 
  letter = NoteLetter(NoteLetterType::NULL_NOTE); 
  value = NoteValue(NoteValueType::NONE);
  octave = NULL_OCTAVE;
}

/**
 * Determines if the note is null
 * 
 * @return True if the note is null and False otherwise
 */
bool NoteObject::isNull() const { return letter.isNull(); }

/**
 * Determines if the note is a rest
 * @return True if the note is a rest and False otherwise
 */
bool NoteObject::isRest() const { return note_is_rest; }
  
/**
 * Gets the type of the note 
 *<p>
 * See NoteType enum
 */
NoteValue NoteObject::getValue() const{ return value;}
  
/**
 * Sets the note instance as a note or a rest. 
 * <p>
 * There is a 25% chance of the note being a rest.
 */
void NoteObject::selectRestOrNote()
{
  note_is_rest = (rand() % 100) <= 25;
}

/**
 * Sets the note type to a random value.
 * <p>
 * See NoteType for types
 */
void NoteObject::setRandomBeatVal()
{

  int beat_val = rand() % 4;
  
  switch (beat_val){
    case 0:
      value = NoteValue(NoteValueType::WHOLE);
    case 1:
      value = NoteValue(NoteValueType::HALF);
    case 2:
      value = NoteValue(NoteValueType::QUARTER);
    case 3:
      value = NoteValue(NoteValueType::EIGHTH);
    case 4:
      value = NoteValue(NoteValueType::SIXTEENTH);
    default:
      value = NoteValue(NoteValueType::QUARTER);
  }
}
  
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
void NoteObject::computeFrequency()
{
  
  try
  {
    NoteLetter reference_note = NoteLetter (REFERENCE_NOTE_LETTER);
    NoteLetter instance_note = NoteLetter (letter.getNote());
  
    /* reference note is assumed (at this point to be the first note of the scale, 
      * so just find the distance away from the instance note and subtract from the
      * octaves.
      */
    double half_steps = ((octave - REFERENCE_NOTE_OCTAVE)*12) + 
                          (reference_note.getDistance(instance_note));
    frequency = (REFERENCE_NOTE_FREQUENCY * pow(SEMITONE_HZ_CONSTANT,half_steps));
    
  }
  catch(InvalidNoteException e){
    
    std::cerr <<
      "Error - Invalid note detected. "<<
        "Cannot compute frequency, setting to "<<NULL_FREQUENCY;
    
    frequency = NULL_FREQUENCY;
    
  }
}


namespace arias{
namespace common{
namespace types{
namespace note{
/**
 * Converts the class to string
 * @return string representation of the class
 */
std::ostream & operator << (std::ostream & os, const NoteObject & note)
{ 
  os << "Value = [" << note.value <<"]"
     << ", Letter = [" << note.letter <<"]"
     << ", Is Rest = " << note.note_is_rest
     << ", Beat Octave = "<< note.octave
     << ", Freq = " << note.frequency;

  return os;
  
}
}
}
}
}
