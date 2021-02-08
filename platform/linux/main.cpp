#include "noteobject.hpp"
#include <iostream>
using namespace std;
using namespace arias::common::types::note;

int main(){

    NoteObject o;
    NoteObject n (NoteLetterType::D_SHARP, 0, true);

    cout << "Test\n" << o<<"\n"<<n<<"\n";

    return 0;
}