package com.ariasproj.common.types.note;

import com.ariasproj.common.exceptions.InvalidIntervalException;

public class NoteInterval {

	private byte interval;
	public NoteInterval(){
		this.interval = 0;
	}
	public NoteInterval(byte interval) throws InvalidIntervalException{
		if (interval < 1 || interval > 8)
			throw new InvalidIntervalException();
		
		this.interval = interval;
	}

	public byte getInterval(){
		return this.interval;
	}
}
