/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

#pragma once

#include "scalemanager.hpp"
#include "guitar.hpp"
#include "notenotinscaleexception.hpp"
#include "noteletter.hpp"

#include <vector>

namespace arias{
namespace common{
namespace types{
namespace instrument{
namespace guitar{

class GuitarScale : public Guitar {
  
	/**
	 * Constructor for the <Class>Scale_Guitar</Class> class.
	 * <p>
	 * The notes that are not in the key of the <Class>Scale_Manager</Class>
	 * will be filtered out.
	 * 
	 * @param scale_manager
	 *          manager containing the key to initialize the guitar class to.
	 * 
	 */
  public:
    GuitarScale(ScaleManager mgr);

  /**
   * Gets a random note in the initialized key
   * @return <Class>GuitarNote</Class> object containing a random note in the 
   * initialized key.
   */
  virtual
  GuitarNote getRandomNote();
  /**
   * Gets the interval of the guitar note and the initialized root note
   * 
   * @param note guitar note that the interval is to be determined
   * @return interval between 1 - 8
   * @throws InvalidNoteException 
   */
  std::uint8_t getInterval(GuitarNote note);

  /**
   * Gets a list of random notes in the initialized key.
   * 
   * @param num_random_notes number of random notes to generate
   * @return <Class>LinkedList</Class> of random notes in the initialized
   *   key having length <code>num_random_notes</code>
   */
  std::vector<GuitarNote> getRandomNotes(int num_random_notes);

  /**
   * Gets a list of random chords in the initialized key.
   * 
   * @param num_random_chords number of random chords to generate
   * @return <Class>LinkedList</Class> of random chords in the initialized
   *   key having length <code>num_random_chords</code>
   */
  std::vector<std::string> getRandomScaleChords(int num_random_chords);

  /**
   * Gets a list of random chords in the initialized key.
   * 
   * @return <Class>LinkedList</Class> of random chords in the initialized
   *   key having length <code>num_random_chords</code>
   */
  std::string getRandomScaleChord();


  std::vector<GuitarNote> getNotes();

  private:

    ScaleManager mgr;
    /**
   * Filters out all of the guitar notes that are not in the initialized key. 
   */
   
    void filterStrings();
};

}
}
}
}
}
