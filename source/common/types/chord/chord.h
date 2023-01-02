#pragma once

#include "chordtype.h"
#include "noteletter.h"

using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace types{
namespace chord{

class Chord{

    public:

        //Chord() =0;
        Chord(NoteLetter note, ChordType chord);
        bool operator==(const Chord &) const;
        std::string chordType()const;
        friend std::ostream & operator << (std::ostream &, const Chord& chord);
    private:
        ChordType _chordType;
        note::NoteLetter _note;
};

}
}
}
}