package com.ariasproj.common.exceptions;

@SuppressWarnings("serial")
public class InvalidNoteException extends Exception{
	
	private String noteNotInScale;
	
	public InvalidNoteException(){
		this.noteNotInScale = "";
	}
	
	public InvalidNoteException(String note){
		this.noteNotInScale = note;
	}
	
	String getNoteNotInScale(){ return this.noteNotInScale; }
}
