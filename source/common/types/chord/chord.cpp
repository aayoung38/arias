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