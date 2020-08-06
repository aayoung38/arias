#pragma once
#include "invalidintervalexception.hpp"

namespace arias{
namespace common{
namespace types{
namespace note{


class NoteInterval {
  public:
	NoteInterval();
	
	NoteInterval(byte interval);

	byte getInterval();

	private:
      byte interval;
};
}
}
}
}