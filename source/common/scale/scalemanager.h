/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include "invalidnoteexception.h"
#include "noteletter.h"
#include "notelettertype.h"
#include "instrumenttypes.h"
#include "chord.h"

#include <random>
#include <vector>
#include <stdlib.h>

using namespace arias::common::types;
using namespace arias::common::types::chord;
using namespace arias::common::types::note;

namespace arias{
namespace common{
namespace scale{

class ScaleManager {
  public:
	  /**
    * Constructor for the Scale_Manager class
    *
    * @param  scale root note for the scale to initialize the class in
    * <p>
    * By default the class uses sharps unless the root note specified is a
    * flat note.
    *
    */
    ScaleManager(NoteLetterType scale);

    /**
    * Constructor for the Scale_Manager class
    *
    * @param  scale root note for the scale to initialize the class in
    * <p>
    * By default the class uses sharps unless the root note specified is a
    * flat note.
    * @param  use_flats boolean that when true uses represents notes in terms 
    *         of flats rather than sharps.
    * @throws InvalidNoteException 
    */
    ScaleManager(NoteLetter scale, bool use_flats);
  
    /**
    * Computes the number of half steps from the root given the interval from 
    * the root.
    *
    * @param  interval a number between (1-8) which represents the interval of 
    *         the root note. If the number is greater than 8 it is assumed to be
    *         in a higher octave.
    * @return a number in half steps from the root.
    */
    int toHalfSteps(InstrumentOctave interval) const;
    virtual InstrumentOctave diminishedInterval() const =0;
    /**
    * Gets a chord in the key of the initialized root note using the interval as 
    * the distance from the root. 
    *
    * @param  interval a number between (1-8) which represents the interval of 
    *         the root note. If the number is greater than 8 it is assumed to be
    *         in a higher octave.
    * @return a chord from the given interval of the root in the scale of the 
    *         initialized root note as a string.
    * @throws InvalidNoteException 
    * @see    String
    */
    virtual Chord getChord(InstrumentOctave interval) const =0;

    /**
    * Gets the relative scale of the root depending on the scale. If the scale 
    * is a major scale then the relative minor is computed. If the scale is
    * a minor scale the the relative major is computed.
    * 
    * @return relative scale of the initialized note.
    * 
    */
    virtual Chord getRelativeScale() const =0;
  
    /**
    * Gets the note in the interval of the initialized root note.
    * 
    * @param interval - range 1 .. 8
    * @return computed note in the scale of the initialized note as a string.
    * @throws InvalidNoteException 
    * 
    */
    virtual NoteLetterType getNote(InstrumentOctave interval) const;
  
    /**
    * Gets a random interval between 1 - 8 inclusive from the root note
    * 
    * @return random interval
    */
    uint32_t getRandomInterval();

    /**
    * Generates a list of random chords having the size of the given parameter.
    * 
    * @param num_random_chords number of random chords needed to be generated
    * @return list of random chords
    */
    std::vector<Chord> getRandomChords(int num_random_chords);

    /**
    * Determines if the given note is in the initialized scale
    * @param note note to be checked
    * @return true if the note is in the scale and false otherwise
    * @throws InvalidNoteException 
    */
    bool noteInScale(NoteLetterType note);

    /**
    * Gets the interval the given note is from the initialized scale root note
    * 
    * @param noteLetterType
    * @return number of intervals from the root note.
    * @throws InvalidNoteException 
    */
    InstrumentOctave getInterval(NoteLetterType note);

    /**
    * Converts the <Class>ScaleManager</Class> object to string
    * 
    * @return String representation of the Scale_Manager object.
    * @see ScaleManager
    */
	  friend std::ostream & operator << (std::ostream &, const ScaleManager& scale);
  
  protected:

    bool use_flats;
    NoteLetter scale;
    int halfStepsMap[SCALE_NOTES];
 
};
}
}
}