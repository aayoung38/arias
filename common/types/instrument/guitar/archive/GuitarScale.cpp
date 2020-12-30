/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common.types.instrument.guitar;

import java.util.LinkedList;
import java.util.List;

import com.ariasproj.common.ScaleManager;
import com.ariasproj.common.exceptions.InvalidNoteException;
import com.ariasproj.common.exceptions.NoteNotInScaleException;
import com.ariasproj.common.types.note.NoteLetter;

public class GuitarScale extends Guitar {
  
  private ScaleManager mgr;


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
  public GuitarScale(ScaleManager mgr){
    super();
    this.mgr = mgr;
    filterStrings();
    
  }

  /**
   * Gets a random note in the initialized key
   * @return <Class>GuitarNote</Class> object containing a random note in the 
   * initialized key.
   */
  @Override
  public GuitarNote getRandomNote(){
  	
  	GuitarNote random_note = super.getRandomNote();
    
    while (!mgr.noteInScale(random_note.getNoteLetter().getNote()))
      random_note = super.getRandomNote(); 
    
    return random_note;
  
  }

  /**
   * Gets the interval of the guitar note and the initialized root note
   * 
   * @param note guitar note that the interval is to be determined
   * @return interval between 1 - 8
   * @throws InvalidNoteException 
   */
  public byte getInterval(GuitarNote note) throws NoteNotInScaleException, InvalidNoteException{
  	
  	NoteLetter local_note = note.getNoteLetter();
  	
    if (!this.mgr.noteInScale(local_note.getNote()))
    	throw new NoteNotInScaleException();
    
    return this.mgr.getInterval(local_note.getNote());
  
  }

  /**
   * Gets a list of random notes in the initialized key.
   * 
   * @param num_random_notes number of random notes to generate
   * @return <Class>LinkedList</Class> of random notes in the initialized
   *   key having length <code>num_random_notes</code>
   */
  public List<GuitarNote> getRandomNotes(int num_random_notes){
    LinkedList<GuitarNote> random_notes = new LinkedList<GuitarNote>();
    
    for (int i = 0; i < num_random_notes; i++){
      
      random_notes.add(getRandomNote());
    }
    
    return random_notes;
    
  }

  /**
   * Gets a list of random chords in the initialized key.
   * 
   * @param num_random_chords number of random chords to generate
   * @return <Class>LinkedList</Class> of random chords in the initialized
   *   key having length <code>num_random_chords</code>
   */
  public List<String> getRandomScaleChords(int num_random_chords){
    
    return mgr.getRandomChords(num_random_chords);
    
  }

  /**
   * Gets a list of random chords in the initialized key.
   * 
   * @return <Class>LinkedList</Class> of random chords in the initialized
   *   key having length <code>num_random_chords</code>
   */
  public String getRandomScaleChord(){ return mgr.getRandomChords(1).get(0); }

  /**
   * Filters out all of the guitar notes that are not in the initialized key. 
   */
  private void filterStrings()
  {

    for (int fret_number = 0; fret_number < GUITAR_FRETS ; fret_number++)
    {
      for (int string_number = 0; string_number < GUITAR_STRINGS; string_number++)
      {
        if (! mgr.noteInScale
                (strings[string_number].getNoteElement
                    (fret_number).getNoteLetter().getNote()))
        {
        	this.strings[string_number].getNoteElement(fret_number).setNull();
      
        }
      }
    } 
  }
  public List<GuitarNote> getNotes()
  {
    List notes = new LinkedList<GuitarNote>();
    for (int string_number = 0; string_number < GUITAR_STRINGS; string_number++)
    {
      for (int fret_number = 0; fret_number < GUITAR_FRETS ; fret_number++)
      {
      
        GuitarNote n = strings[string_number].getNoteElement(fret_number);
        
        if (mgr.noteInScale (n.getNoteLetter().getNote()))
        {
          notes.add(n);
      
        }
      }
    }
    return notes;
  }
}
