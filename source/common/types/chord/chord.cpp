#include "chord.h"
using namespace arias::common::types::chord;

Chord::Chord(){
    chordType = Major;
    note = C;
}

Chord::Chord(NoteLetter note, ChordType chord)
{
    chordType = chord;
    this->note = note;
}

bool Chord::operator==(const Chord & c) const
{
    return this->chordType == c.chordType && this->note.getNote() == c.note.getNote();
}

namespace arias{
namespace common{
namespace types{
namespace chord{
std::ostream & operator << (std::ostream & os, const Chord& chord)
{
    os << chord.note.getStringNote() << chord.chordType;
	return os;
}
}}}}