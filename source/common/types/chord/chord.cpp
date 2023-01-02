#include "chord.h"
using namespace arias::common::types::chord;

Chord::Chord(NoteLetter note, ChordType chord) : _chordType(chord), _note(note)
{
}

bool Chord::operator==(const Chord & c) const
{
    return _chordType == c._chordType && _note.getNote() == c._note.getNote();
}
std::string Chord::chordType()const{
    if (_chordType == Major) return "Maj";
    else if (_chordType == Minor) return "Min";
    else if (_chordType == Major7) return "Maj7";
    else if (_chordType == Major7) return "Min";
    else if (_chordType == Diminished) return "Dim";
    else return "---";
    
}

namespace arias{
namespace common{
namespace types{
namespace chord{
std::ostream & operator << (std::ostream & os, const Chord& chord)
{
    os << chord._note.getStringNote();
    if (chord._note.getNote() != NULL_NOTE)
      os << chord.chordType();
	return os;
}
}}}}