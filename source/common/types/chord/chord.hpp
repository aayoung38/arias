#pragma once

#include "chordtype.hpp"
#include "noteletter.hpp"

using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace types{
namespace chord{

class Chord{

    public:

        Chord();
        Chord(NoteLetter note, ChordType chord);
        friend std::ostream & operator << (std::ostream &, const Chord& chord);
    private:
        ChordType chordType;
        note::NoteLetter note;
};

}
}
}
}