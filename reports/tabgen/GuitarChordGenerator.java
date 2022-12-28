/**
 * @author      Adam Young <aag24ster@gmail.com>
 * @version     0.1
 * @since       2013-06-09          
 */

package com.ariasproj.common;

import java.util.LinkedList;
import java.util.List;
import java.util.Random;

import com.ariasproj.common.types.instrument.guitar.GuitarScale;

public class GuitarChordGenerator {
  private int beats_per_measure;
  private int beat_note;
  private int num_random_measures;
  private GuitarScale guitar;
  
  // List of strings tabs which has an array of measures
  private List<String> chords;
  
  /**
	 * Constructor for the <Class>Guitar_Tab_Generator</Class> class.
	 * 
	 * @param manager
	 *          scale manager containing the key to initialize the \
	 *          <Class>Scale_Guitar</Class> in.
	 * @param beats_per_measure
	 * 					how many beats per measure to initialize the time signature in.
	 * @param beat_note
	 * 					what note gets the beats to initialize the time signature in.
	 * 
	 */
  public GuitarChordGenerator(GuitarScale guitar, int beats_per_measure, int beat_note){
    this.beats_per_measure = beats_per_measure;
    this.beats_per_measure = 4; // Remove this once beats per measure has been implemented
    this.num_random_measures = 0;
    this.beat_note = beat_note;
    this.guitar = guitar;
    this.chords = new LinkedList<String>();
  }

	/**
	 * Returns the portion of the time signature that represents how many beats 
	 * per measure.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return how many beats per measure
	 */
  public int getBeatsPerMeasure(){ return beats_per_measure; }


	/**
	 * Returns the portion of the time signature that represents which note gets 
	 * the beat.
	 * <p>
	 * In a time signature the top note is how many beats per measure. The 
	 * bottom note represents what note gets the beat.
	 * 
	 * @return what note gets the beat
	 */
  public int getBeatNote(){ return beat_note; }

	/**
	 * 
	 */
  public void generateRandomChordReport(){
  	Random generator = new Random();
  	this.chords.clear();
  	
  	this.num_random_measures = generator.nextInt(6)+2;
  	this.chords = this.guitar.getRandomScaleChords(num_random_measures);

  	// debug
    for(String chord : chords){
  	  System.out.println(chord);
  	}
    
  }


	/**
	 * 
	 */
  public void generateRandomUniqueChordReport(){
  	Random generator = new Random();
  	String prev_chord = "";
  	String rand_chord = "";
  
  	int i = 0;
  	
  	this.num_random_measures = generator.nextInt(6)+2;
  	this.chords.clear();
  	
  	while (i < this.num_random_measures){
  		rand_chord = this.guitar.getRandomScaleChord();
  		if(!prev_chord.equals(rand_chord)){
  			this.chords.add(rand_chord);
  			prev_chord = rand_chord;
  			i++;
  		}
  	}

  	// debug
    for(String chord : chords){
  	  System.out.println(chord);
  	}
    
  }
  
  public List<String> getChords(){
	  return chords;
  }

	/**
	 * Generates a tab report in human readable format.ets the number of octaves
	 * in the given distance.
	 * <p>
	 * Each line in the tab report represents a string. The lowest line represents
	 * the low E, and the highest represent the high E.
	 */
  public String toString(){
  	String tab_report = "";
  	
  	//this.generateRandomChordReport();

  	for(String chord : chords)
  	  tab_report += chord + "\n";
    
    return tab_report;   
  }
  
}
