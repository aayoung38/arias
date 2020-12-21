#pragma once
#include "invalidintervalexception.hpp"

#include "stdint.h"

namespace arias{
namespace common{
namespace types{
namespace note{


class NoteInterval {
  public:
	NoteInterval();
	
	NoteInterval(uint8_t interval);

	uint8_t getInterval();

	private:
      uint8_t interval;
};
}
}
}
}