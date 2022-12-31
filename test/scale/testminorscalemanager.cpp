#include "gtest/gtest.h"
#include "minorscalemanager.h"
#include "notelettertype.h"
#include "chord.h"
#include "chordtype.h"
#include <cmath>

using namespace arias::common::scale;
using namespace arias::common::types::note;
using namespace arias::common::types::chord;
TEST (MinorScaleManagerTest, RelativeScale) { 

    std::pair<MinorScaleManager, Chord> inputs[7] =
    {
        std::make_pair(MinorScaleManager(A), Chord(NoteLetter(C),Major)),
        std::make_pair(MinorScaleManager(B), Chord(NoteLetter(D),Major)),
        std::make_pair(MinorScaleManager(C), Chord(NoteLetter(D_SHARP),Major)),
        std::make_pair(MinorScaleManager(D), Chord(NoteLetter(F),Major)),
        std::make_pair(MinorScaleManager(E), Chord(NoteLetter(G),Major)),
        std::make_pair(MinorScaleManager(F), Chord(NoteLetter(G_SHARP),Major)),
        std::make_pair(MinorScaleManager(G), Chord(NoteLetter(A_SHARP),Major))
    };
    
    for (int i=0; i<7; i++)
        EXPECT_EQ (inputs[i].second, inputs[i].first.getRelativeScale());

}

