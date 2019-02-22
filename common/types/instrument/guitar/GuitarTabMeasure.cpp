package com.ariasproj.common.types.instrument.guitar;

import java.util.ArrayList;

import com.ariasproj.common.exceptions.MeasureBeatsExceededException;
import com.ariasproj.common.types.note.NoteLetterType;
import com.ariasproj.common.types.note.NoteValue;
import com.ariasproj.common.types.note.NoteValueType;

public class GuitarTabMeasure {
	
	@SuppressWarnings("unused")
	private float beats_per_measure;       // currently not supported assuming four beats per measure
	@SuppressWarnings("unused")
  private NoteValue beat_note; // currently not supported assuming quarter note always gets beat
	private float beats_left;
	private byte guitar_strings;
	
	
	// measure notes
	private ArrayList<GuitarNote> measure; // measure notes
	
	/**
	 * Constructor
	 * @param beats_per_measure number of beats in the measure, only whole beats are supported.
	 * @param beat_note which note gets the beat
	 * @param guitar_strings number of guitar strings in the tabs
	 */
	public GuitarTabMeasure(int beats_per_measure, NoteValue beat_note, byte guitar_strings){
	  this.beats_per_measure = beats_per_measure;	
	  this.beat_note = beat_note; // currently not supported
	  this.beats_left = (float) beats_per_measure;	
	  this.measure = new ArrayList<GuitarNote>();
	  this.guitar_strings = guitar_strings;
	}

	
	/**
	 * Gets the number of beats left in the measure
	 * <p>
	 * Based on the notes that have been added to the measure
	 * @return number of beats left in the measure
	 */
	public float getBeatsLeft(){ return this.beats_left; }
	
	/**
	 * Adds a new <Class>GuitarNote</Class> to the measure
	 * <p>
	 * An exception is raised if the note desired to be added exceeds the number
	 * of beats left in the measure.
	 *  
	 * @param note guitar note to add to the measure
	 * @throws MeasureBeatsExceededException
	 */
	public void addNote(GuitarNote note) throws MeasureBeatsExceededException{
		if (note.getValue().getBeats() > this.beats_left)
			throw new MeasureBeatsExceededException(note.getValue().getBeats() - this.beats_left);
		
		measure.add(note);
	}
  
	/**
	 * Gets the size of the measure with respect to the number of notes
	 * @return size of the measure.
	 */
	public int size(){ return this.measure.size(); }
	
  /**
   * Gets the guitar note at the given index with respect to the order that
   * they were added to the list
   * @param index index of the guitar note to get
   * @return guitar note at the given index
   */
  public GuitarNote getIndex(int index){  return this.measure.get(index); }
  
  /**
   * Gets all the <Class>GuitarNote</Class> that have been added to the measure.
   * @return notes in the measure
   */
  public ArrayList<GuitarNote> getNotes(){ return this.measure; }
  
  public String guitarStringToString(int string_index){
  	String string_tab_report = "";
  	for(GuitarNote note : this.measure){
  		
  		int string_number = note.getStringNumber();

      if (note.isRest())
      {
        string_tab_report += String.format("%4s",
                          "x").replace(' ', '-');
      }
      else if (string_number == string_index){
      	string_tab_report += String.format("%4s",
	      		 							note.getFretNumber()).replace(' ', '-');
      }
  	  else{
  	  	string_tab_report += "----";
  	  }
  		
  	}
    
    return string_tab_report+"|\n";  
  }
  
  /**
   * Converts class to string representation
   * @return string representation of the class
   */
  public String toString(){
  	String tab_report = "";
  	for(GuitarNote note : this.measure){
  		
  		int string_number = note.getStringNumber();
  	
      for(int string_index = this.guitar_strings - 1; 
      		string_index >= 0; 
      		string_index --){

        if (note.isRest())
        {
          tab_report += String.format("%4s",
                            "x").replace(' ', '-');
        }
        else if (string_number == string_index){
    	  	tab_report += String.format("%4s",
  	      		 							note.getFretNumber()).replace(' ', '-');
        }
    	  else{
    	  	tab_report += "----";
    	  }
    	  tab_report += "|\n";
      }
  	}
    
    return tab_report;   
  	
  }
	
}
