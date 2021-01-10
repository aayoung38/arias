#pragma once

// project includes
#include "invalidintervalexception.hpp"

// std lib includes
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