
#include "instrumenttypes.hpp"   
#include <random>

namespace arias{
namespace common{
namespace types{

class RandomInterval
{

   public:
      RandomInterval()
      {
         distribution = std::uniform_int_distribution<int> (1, SCALE_NOTES);
      }
      InstrumentOctave getInterval(){ return distribution(generator); }
   private:
      std::default_random_engine generator;
      std::uniform_int_distribution<int> distribution;
};

}}}