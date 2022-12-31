/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "noteletter.h"
#include "invalidnoteexception.h"
#include <array>
using namespace arias::common::types::note;
using namespace arias::common::exceptions;
	 
bool NoteLetter::use_flats = false;

/**
 * Constructor for the <Class>Note_Utilities</Class> class.
 * <p>
 * By default it is assumed that the note is in terms of sharps.
 * 
 * @param reference_note
 *          note to initialize the class to.
 * @throws InvalidNoteException 
 */
NoteLetter::NoteLetter(const NoteLetter& note) : reference_note(note.reference_note){}

/**
 * Constructor for the <Class>Note_Utilities</Class> class.
 * 
 * @param reference_note
 *          note to determine is in sharps or flats.
 * @param use_flats
 *          boolean to indicate desire to represents applicable notes in terms
 *          of flats rather than sharps.
 * @throws InvalidNoteException 
 */
NoteLetter::NoteLetter(NoteLetterType note) : reference_note(note)
{  
}

NoteLetter NoteLetter::getNoteLetter() {return NoteLetter();}

void NoteLetter::useFlats(bool use_flats)
{
  NoteLetter::use_flats = use_flats;
}


/**
 * Returns the number of notes supported by the application
 * 
 * @return number of supported notes
 */
int NoteLetter::getNumberNotes(){ return NoteLetterType::NULL_NOTE;}
  
/**
 * Converts the given <Enum>NoteLetterType</Enum> to letter
 * 
 * @param type letter to convert to string
 * 
 * @return string representation of the given type
 */
std::string NoteLetter::getStringNote() const
{
  if (use_flats)
  {
    if (reference_note == D_FLAT) return "Db";
    if (reference_note == E_FLAT) return "Eb";
    if (reference_note == G_FLAT) return "Gb";
    if (reference_note == A_FLAT) return "Ab";
    if (reference_note == B_FLAT) return "Bb";

  }
  else
  {
    if (reference_note == C_SHARP) return "C#";
    if (reference_note == D_SHARP) return "D#";
    if (reference_note == F_SHARP) return "F#";
    if (reference_note == G_SHARP) return "G#";
    if (reference_note == A_SHARP) return "A#";
  }
  if (reference_note == C) return "C";
  if (reference_note == D) return "D";
  if (reference_note == E) return "E";
  if (reference_note == F) return "F";
  if (reference_note == G) return "G";
  if (reference_note == A) return "A";
  if (reference_note == B) return "B";

  return "-";
}
  
NoteLetterType NoteLetter::getNoteLetter(const std::string & note)
{
  if (note == "C") return NoteLetterType::C;
  if (note ==  "C#") return NoteLetterType::C_SHARP;
  if (note ==  "Db") return NoteLetterType::D_FLAT;
  if (note ==  "D") return NoteLetterType::D;
  if (note ==  "D#") return NoteLetterType::D_SHARP;
  if (note ==  "Eb") return NoteLetterType::E_FLAT;
  if (note ==  "E") return NoteLetterType::E;
  if (note ==  "F") return NoteLetterType::F;
  if (note ==  "F#") return NoteLetterType::F_SHARP;
  if (note ==  "Gb") return NoteLetterType::G_FLAT;
  if (note ==  "G") return NoteLetterType::G;
  if (note ==  "G#") return NoteLetterType::G_SHARP;
  if (note ==  "Ab") return NoteLetterType::A_FLAT;
  if (note ==  "A") return NoteLetterType::A;
  if (note ==  "A#") return NoteLetterType::A_SHARP;
  if (note ==  "B") return NoteLetterType::B;
  
  return NoteLetterType::NULL_NOTE;
  
}

/**
 * Gets the note distance from the reference note in terms of half steps.
 * <p>
 * Treats the reference note as the lower note.
 * 
 * @param note
 *          note to get the distance from the reference note for
 * @return integer distance from the reference note in half steps.
 * @throws InvalidNoteException 
 */
int NoteLetter::getDistance(const NoteLetter & note)
{
  
  if (note.reference_note >= reference_note) 
  {
    return note.reference_note - reference_note;
  }
  else 
  {
    return (NUM_AVAILABLE_NOTES - reference_note) + note.reference_note;
  }
}

/**
 * Gets the initialized note
 * 
 * @return initialized note
 */
NoteLetterType NoteLetter::getNote() const{ return reference_note; }

/**
 * Gets the note which is the given distance from the initialized reference note
 * @param distance distance from the reference note in half steps
 * @return string note
 * @throws InvalidNoteException
 * @throws InvalidIntervalException 
 */
NoteLetterType NoteLetter::getNote(int distance) const
{
  if (distance < 0){
    throw InvalidIntervalException();
  }
  
  
  //int octave = distance / working_notes.length;
  int local_distance = distance % NUM_AVAILABLE_NOTES;
  
  int total_half_note_distance = reference_note + local_distance;
  
  if (total_half_note_distance >= NUM_AVAILABLE_NOTES)
    return NoteLetterType(total_half_note_distance % NUM_AVAILABLE_NOTES);
  
  else
    return NoteLetterType(total_half_note_distance);

}
	
/**
 * Determines if the note letter is null.
 * @return True if the note is null and False otherwise
 */
bool NoteLetter::isNull() const
{
  return reference_note == NoteLetterType::NULL_NOTE;
}
	
NoteLetter& NoteLetter::operator=(const NoteLetter& note){
  reference_note = note.reference_note;
  return *this;
}

namespace arias{
namespace common{
namespace types{
namespace note{
std::ostream& operator <<(std::ostream & os, const NoteLetter & note) 
{
  os << "Type: " << note.reference_note 
     << ", Value: " << note.getStringNote()
     << ", Use Flats: " << NoteLetter::use_flats
     << ", Is Null: " << note.isNull();

  return os;
}
}
}
}
}