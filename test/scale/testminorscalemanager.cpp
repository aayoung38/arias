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

    const int numInputs = 37;
    std::pair<MinorScaleManager, Chord> inputs[numInputs] =
    {
        std::make_pair(MinorScaleManager(A), Chord(NoteLetter(C),Major)),
        std::make_pair(MinorScaleManager(B), Chord(NoteLetter(D),Major)),
        std::make_pair(MinorScaleManager(C), Chord(NoteLetter(D_SHARP),Major)),
        std::make_pair(MinorScaleManager(D), Chord(NoteLetter(F),Major)),
        std::make_pair(MinorScaleManager(E), Chord(NoteLetter(G),Major)),
        std::make_pair(MinorScaleManager(F), Chord(NoteLetter(G_SHARP),Major)),
        std::make_pair(MinorScaleManager(G), Chord(NoteLetter(A_SHARP),Major)),
        std::make_pair(MinorScaleManager(A_SHARP), Chord(NoteLetter(C_SHARP),Major)),
        std::make_pair(MinorScaleManager(C_SHARP), Chord(NoteLetter(E),Major)),
        std::make_pair(MinorScaleManager(D_SHARP), Chord(NoteLetter(F_SHARP),Major)),
        std::make_pair(MinorScaleManager(F_SHARP), Chord(NoteLetter(A),Major)),
        std::make_pair(MinorScaleManager(G_SHARP), Chord(NoteLetter(B),Major)),

        std::make_pair(MinorScaleManager(A,false), Chord(NoteLetter(C),Major)),
        std::make_pair(MinorScaleManager(B,false), Chord(NoteLetter(D),Major)),
        std::make_pair(MinorScaleManager(C,false), Chord(NoteLetter(D_SHARP),Major)),
        std::make_pair(MinorScaleManager(D,false), Chord(NoteLetter(F),Major)),
        std::make_pair(MinorScaleManager(E,false), Chord(NoteLetter(G),Major)),
        std::make_pair(MinorScaleManager(F,false), Chord(NoteLetter(G_SHARP),Major)),
        std::make_pair(MinorScaleManager(G,false), Chord(NoteLetter(A_SHARP),Major)),
        std::make_pair(MinorScaleManager(A_SHARP,false), Chord(NoteLetter(C_SHARP),Major)),
        std::make_pair(MinorScaleManager(C_SHARP,false), Chord(NoteLetter(E),Major)),
        std::make_pair(MinorScaleManager(D_SHARP,false), Chord(NoteLetter(F_SHARP),Major)),
        std::make_pair(MinorScaleManager(F_SHARP,false), Chord(NoteLetter(A),Major)),
        std::make_pair(MinorScaleManager(G_SHARP,false), Chord(NoteLetter(B),Major)),

        std::make_pair(MinorScaleManager(A,true), Chord(NoteLetter(C),Major)),
        std::make_pair(MinorScaleManager(B,true), Chord(NoteLetter(D),Major)),
        std::make_pair(MinorScaleManager(C,true), Chord(NoteLetter(D_SHARP),Major)),
        std::make_pair(MinorScaleManager(D,true), Chord(NoteLetter(F),Major)),
        std::make_pair(MinorScaleManager(E,true), Chord(NoteLetter(G),Major)),
        std::make_pair(MinorScaleManager(F,true), Chord(NoteLetter(A_FLAT),Major)),
        std::make_pair(MinorScaleManager(G,true), Chord(NoteLetter(B_FLAT),Major)),
        std::make_pair(MinorScaleManager(B_FLAT,true), Chord(NoteLetter(D_FLAT),Major)),
        std::make_pair(MinorScaleManager(D_FLAT,true), Chord(NoteLetter(E),Major)),
        std::make_pair(MinorScaleManager(E_FLAT,true), Chord(NoteLetter(G_FLAT),Major)),
        std::make_pair(MinorScaleManager(G_FLAT,true), Chord(NoteLetter(A),Major)),
        std::make_pair(MinorScaleManager(A_FLAT,true), Chord(NoteLetter(B),Major)),
        std::make_pair(MinorScaleManager(NULL_NOTE,true), Chord(NoteLetter(NULL_NOTE),NULL_CHORD))
    };
    
    for (int i=0; i<numInputs; i++){
        EXPECT_EQ (inputs[i].second, inputs[i].first.getRelativeScale());
    }
}

TEST (MinorScaleManagerTest, StandardOutput) { 
    MinorScaleManager scale(A);

    std::cout << scale << std::endl;

    MinorScaleManager null_scale(NULL_NOTE);

    std::cout << null_scale << std::endl;
    EXPECT_TRUE(true);
}

TEST (MinorScaleManagerTest, RandomScale) { 
    MinorScaleManager scaleA(A);
    MinorScaleManager randomScaleA = scaleA.getRandomScale();

    EXPECT_NE(scaleA, randomScaleA);

    MinorScaleManager scaleB(NULL_NOTE);
    MinorScaleManager randomScaleB = scaleB.getRandomScale();

    EXPECT_EQ(scaleB, randomScaleB);
    
}

TEST (MinorScaleManagerTest, Equality) { 
    MinorScaleManager scaleA(A);
    MinorScaleManager scaleB(A);
    MinorScaleManager scaleC(B);

    EXPECT_EQ(scaleA, scaleB);
    EXPECT_NE(scaleA, scaleC);
    
}