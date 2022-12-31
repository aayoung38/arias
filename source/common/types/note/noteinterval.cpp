

#include "noteinterval.h"
#include "invalidintervalexception.h"
using namespace arias::common::types::note;
using namespace arias::common::exceptions;


NoteInterval::NoteInterval()
{
	this->interval = 0;
}

NoteInterval::NoteInterval(uint8_t interval) 
{
	if (interval < 1 || interval > 8)
		throw InvalidIntervalException();
		
	this->interval = interval;
}

uint8_t NoteInterval::getInterval()
{
	return this->interval;
}

