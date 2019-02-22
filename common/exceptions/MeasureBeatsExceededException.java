package com.ariasproj.common.exceptions;

@SuppressWarnings("serial")
public class MeasureBeatsExceededException extends Exception{

	private float number_exceeded_beats;
	
	/**
	 * Default Constructor
	 */
	public MeasureBeatsExceededException(){
		this.number_exceeded_beats = (float) 0.0;
	}
	
	/**
	 * Constructor
	 * @param number_exceeded_beats number of exceeded beats for the
	 * erroneous measure
	 */
	public MeasureBeatsExceededException(float number_exceeded_beats){
		this.number_exceeded_beats = number_exceeded_beats;
	}
	
	/**
	 * Gets the number of exceeded beats for the erroneous measure
	 * @return number of exceeded beats
	 */
	public float getExceededBeats(){ return this.number_exceeded_beats; }
}
