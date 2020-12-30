#include "noteobject.hpp"
#include <iostream>
using namespace std;
using namespace arias::common::types::note;



int main(){

    NoteObject o;
    cout << "Test\n" << o.getBeatName()<<"\n";

    return 0;
}