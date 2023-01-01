
#include "instrumenttypes.h"   
#include <random>
#include <iostream>
namespace arias{
namespace common{
namespace types{

class RandomInterval
{

   public:
      RandomInterval() : distribution(1,SCALE_NOTES)
      {
      }

      InstrumentOctave getInterval()
      { 
         return distribution(gen); 
      }

   private:
      std::default_random_engine gen;
      std::uniform_int_distribution<InstrumentOctave> distribution;
};

}}}