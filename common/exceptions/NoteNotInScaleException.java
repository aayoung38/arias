package com.ariasproj.common.exceptions;

@SuppressWarnings("serial")
public class NoteNotInScaleException extends Exception{
	
	private String noteNotInScale;
	
	public NoteNotInScaleException(){
		this.noteNotInScale = "";
	}
	
	public NoteNotInScaleException(String note){
		this.noteNotInScale = note;
	}
	
	String getNoteNotInScale(){ return this.noteNotInScale; }
}
