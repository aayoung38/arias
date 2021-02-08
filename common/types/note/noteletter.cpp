/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#include "noteletter.hpp"
#include "invalidnoteexception.hpp"
#include <array>
using namespace arias::common::types::note;
using namespace arias::common::exceptions;
	 
/**
 * [C,  C#,  D,  D#,  E,  F,  F#,  G,  G#, A,  A#, B]
 * <p>
 * [1,  2,   3,  4,   5,  6,  7,   8,  9,  10, 11, 12]
 */
const std::array<std::string, NoteLetter::NUM_AVAILABLE_NOTES> NoteLetter::AVAILABLE_NOTES_SHARP = 
	{ "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#","A", "A#", "B" };

/**
 * <p>
 * [C, Db, D, Eb, E, F, Fb, G, Ab, A, Bb, B]
 * <p>
 * [1, 2,  3, 4,  5, 6, 7,  8, 9,  10,11, 12]
 */
const std::array<std::string, NoteLetter::NUM_AVAILABLE_NOTES> NoteLetter::AVAILABLE_NOTES_FLAT = 
	{ "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab","A", "Bb", "B" };

const std::string NoteLetter::NULL_VAL = "-";

/**
 * Constructor for the <Class>Note_Utilities</Class> class.
 * <p>
 * By default it is assumed that the note is in terms of sharps.
 * 
 * @param reference_note
 *          note to initialize the class to.
 * @throws InvalidNoteException 
 */
NoteLetter::NoteLetter(NoteLetterType note)
{
  reference_note_type = note;
  reference_note = typeToNote(reference_note_type);
  use_flats = noteIsFlat(reference_note);
  
  working_notes = 
    std::make_shared<std::array<std::string,NUM_AVAILABLE_NOTES>>
    ( use_flats ? AVAILABLE_NOTES_FLAT : AVAILABLE_NOTES_SHARP);
  try{
    reference_note_number = noteToNumber(reference_note);
  }
  catch (InvalidNoteException e){
    reference_note_number = -1;
  }
  
}


NoteLetter::NoteLetter(const NoteLetter& note) : reference_note_type(note.reference_note_type), 
                                                 reference_note(note.reference_note), 
                                                 use_flats(note.use_flats), 
                                                 reference_note_number(note.reference_note_number),
                                                 working_notes(note.working_notes){}

NoteLetter::NoteLetter(bool useFlats) : use_flats(useFlats)
{
}

NoteLetter NoteLetter::getNoteLetter(bool useFlats) {return NoteLetter(useFlats);}

/**
 * Constructor for the <Class>Note_Utilities</Class> class.
 * 
 * @param reference_note
 *          note to initialize the class to. The note is represented as a
 *          number.
 */
NoteLetter::NoteLetter(int note) 
{
    reference_note_type = NoteLetterType::NULL_NOTE;
    reference_note = typeToNote(reference_note_type);
  use_flats = false;
  
  // this can be ultimately determined....
  working_notes = 
    std::make_unique<std::array<std::string,NUM_AVAILABLE_NOTES>>
    (AVAILABLE_NOTES_FLAT);
  
  reference_note_number = note;
}

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
NoteLetter::NoteLetter(NoteLetterType note, bool use_flats) : 
    reference_note_type(note),
    use_flats(use_flats)
{
  reference_note = typeToNote(reference_note_type);
  
  working_notes = 
    std::make_unique<std::array<std::string,NUM_AVAILABLE_NOTES>>
    ( use_flats ? AVAILABLE_NOTES_FLAT : AVAILABLE_NOTES_SHARP);

  try
  {
    reference_note_number = noteToNumber(reference_note);
  }
  catch (InvalidNoteException e)
  {
    reference_note_number = -1;
  }
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
std::string NoteLetter::typeToNote(NoteLetterType note) const
{
  switch (note)
  {
    case C:         return "C";
    case C_SHARP:   return "C#";
    case D_FLAT:    return "Db";
    case D:         return "D";
    case D_SHARP:   return "D#";
    case E_FLAT:    return "Eb";
    case E:         return "E";
    case F:         return "F";
    case F_SHARP:   return "F#";
    case G_FLAT:    return "Gb";
    case G:         return "G";
    case G_SHARP:   return "G#";
    case A_FLAT:    return "Ab";
    case A:         return "A";
    case A_SHARP:   return "A#";
    case B_FLAT:    return "Bb";
    case B:         return "B";
    case NULL_NOTE: return NULL_VAL;
    default:        return NULL_VAL;
  }
}
  
NoteLetterType NoteLetter::noteToType(const std::string & note) const
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
 * Determines if the given note is in terms of flats or sharps
 * <p>
 * By default it is assumed that the note is in terms of sharps.
 * 
 * @param note
 *          note to determine is in sharps or flats.
 */
bool NoteLetter::noteIsFlat(const std::string & note) const 
{
  return note.length() > 1 && note.at(1) == 'b';
}

/**
 * Computes the given note to its equivalent representive number.
 * 
 * @param note
 *          valid note between A-G to convert to its internal number
 * @return note representation of the given number.
 */
int NoteLetter::noteToNumber(const std::string & note) const
{

  //std::shared_ptr<std::array<std::string,NUM_AVAILABLE_NOTES>> working_scale = 
  //  std::make_shared<std::array<std::string,NUM_AVAILABLE_NOTES>>
  //  ( noteIsFlat(note) ? AVAILABLE_NOTES_FLAT : AVAILABLE_NOTES_SHARP);

  int tmp_scale_number = 0;

  for (; tmp_scale_number < NUM_AVAILABLE_NOTES
      && (*working_scale)[tmp_scale_number] != note; tmp_scale_number++)
    ;

  if (tmp_scale_number >= NUM_AVAILABLE_NOTES )
  {
    throw InvalidNoteException();
  }
  return tmp_scale_number;
}

/**
 * Computes the given number to its equivalent representive note.
 * 
 * @param number
 *          number (1-12) to convert to a note
 * @return note representation of the given number.
 */
std::string NoteLetter::numberToNote(int number) const
{
  return numberToNote(number,use_flats);
}

/**
 * Computes the given number to its equivalent representive note.
 * 
 * @param number
 *          number (1-12) to convert to a note
 * @return note representation of the given number.
 */
std::string NoteLetter::numberToNote(int number, bool useFlats) 
{
  std::shared_ptr<std::array<std::string,NUM_AVAILABLE_NOTES>> scale = 
    std::make_shared<std::array<std::string,NUM_AVAILABLE_NOTES>>
    ( useFlats ? AVAILABLE_NOTES_FLAT : AVAILABLE_NOTES_SHARP);

  int available_notes_num = number % NUM_AVAILABLE_NOTES;

  return (*scale)[available_notes_num];
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
  int tmp_note = noteToNumber(note.reference_note);
  
  if (tmp_note >= reference_note_number) 
  {
    return tmp_note - reference_note_number;
  }
  else 
  {
    return (NUM_AVAILABLE_NOTES - reference_note_number) + tmp_note;
  }
}

/**
 * Gets the initialized note
 * 
 * @return initialized note
 */
NoteLetterType NoteLetter::getNote() const{ return reference_note_type; }

/**
 * Gets the initialized note as a string
 * 
 * @return initialized note
 */
//const std::string & NoteLetter::getStringNote() const{ return reference_note; }
	
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
  
  if (reference_note_number < 0){
    throw InvalidNoteException();
  }
  
  //int octave = distance / working_notes.length;
  int local_distance = distance % NUM_AVAILABLE_NOTES;
  
  int total_half_note_distance = reference_note_number + local_distance;
  
  if (total_half_note_distance >= NUM_AVAILABLE_NOTES)
    return noteToType
              (numberToNote
                  (total_half_note_distance % NUM_AVAILABLE_NOTES));
  
  else
    return noteToType
              (numberToNote(total_half_note_distance));

}
	
/**
 * Determines if the note letter is null.
 * @return True if the note is null and False otherwise
 */
bool NoteLetter::isNull() const
{
  return reference_note_type == NoteLetterType::NULL_NOTE;
}
	
NoteLetter& NoteLetter::operator=(const NoteLetter& note){
  reference_note_type = note.reference_note_type;
  reference_note = note.reference_note;
  use_flats = note.use_flats;
  reference_note_number = note.reference_note_number;
  working_notes = note.working_notes;
  return *this;
}

namespace arias{
namespace common{
namespace types{
namespace note{
std::ostream& operator <<(std::ostream & os, const NoteLetter & note) 
{
  os << "Type: " << note.reference_note_type 
     << ", Value: " << note.reference_note
     << ", Number: " << note.reference_note_number
     << ", Use Flats: " << note.use_flats
     << ", Is Null: " << note.isNull();

  return os;
}
}
}
}
}