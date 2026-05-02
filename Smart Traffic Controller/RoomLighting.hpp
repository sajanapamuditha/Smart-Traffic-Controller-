#ifndef ROOMLIGHTING_H
#define ROOMLIGHTING_H

#include "Device.hpp"
#include <string>
using namespace std;

// Derived class for Room Lighting device
class RoomLighting : public Device
{
private:
    int brightness;   // brightness level (0–100)

public:

    // Constructor - initialize room lighting details
    RoomLighting(int id,
        const string& name,
        const string& manu,
        int bright);

    // Override interaction function
    void InteractionEvent() override;

    // Override view information function
    void ViewInfo() const override;

    // Set brightness value
    void SetBrightness(int bright);

    // Get brightness value
    int GetBrightness() const;
};

#endif
