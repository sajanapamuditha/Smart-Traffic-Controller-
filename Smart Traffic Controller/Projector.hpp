#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "Device.hpp"
#include <string>
using namespace std;

// Derived class for Projector device
class Projector : public Device
{
private:
    int brightness;      
    string inputSource;    

public:

    // Constructor - initialize projector details
    Projector(int id,
        const string& name,
        const string& manu,
        int bright,
        const string& inputSrc = "HDMI");

    // Override interaction function
    void InteractionEvent() override;

    // Override view information function
    void ViewInfo() const override;

    // Set brightness value
    void SetBrightness(int bright);

    // Set input source
    void SetInputSource(const string& source);

    // Get brightness value
    int GetBrightness() const;

    // Get input source
    string GetInputSource() const;
};

#endif
