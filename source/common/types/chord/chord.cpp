#include "chord.h"
using namespace arias::common::types::chord;

Chord::Chord(NoteLetter note, ChordType chord) : _chordType(chord), _note(note)
{
}

bool Chord::operator==(const Chord & c) const
{
    return _chordType == c._chordType && _note.getNote() == c._note.getNote();
}

namespace arias{
namespace common{
namespace types{
namespace chord{
std::ostream & operator << (std::ostream & os, const Chord& chord)
{
    os << chord._note.getStringNote() << chord._chordType;
	return os;
}
}}}}