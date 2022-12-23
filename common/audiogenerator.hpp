#pragma once

namespace arias{
namespace common{
class Tone
{
    private:
        const double sampleRate;
        double s; /* current position along the unit sine curve */
        double lastSample;
    public:
        double getSample() const;
        double nextSample(double frequency, double amplitude);
        Tone(double sampleRate);
};

}}