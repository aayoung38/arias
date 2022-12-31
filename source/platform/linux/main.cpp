#include "note.h"
#include "guitarnote.h"
#include "instrumenttypes.h"
#include "majorscalemanager.h"
#include "minorscalemanager.h"
//#include "audiodriver.hpp"
#include <iostream>
using namespace std;
using namespace arias::common::types;
using namespace arias::common::types::note;
using namespace arias::common::types::instrument::guitar;

int main(){

    InstrumentOctave a = 0;
    InstrumentOctave b = 1;

    Note o;
    Note n (NoteLetterType::D_SHARP, a, true);
    Note m (NoteLetterType::C, 1, false);

    GuitarNote l(NoteLetterType::D_SHARP, a, InstrumentFret(1), InstrumentString(2));
    
    cout << "Test\n" << o<<"\n"<<n<<"\n"<< m << "\n" << l <<"\n";

    //int result = arias::common::run();
    //cout << "result = "<<result;
    return 0;
}