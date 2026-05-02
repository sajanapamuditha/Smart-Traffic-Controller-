#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H

#include "Device.hpp"
#include <string>
using namespace std;

// Derived class for Air Conditioning device
class AirConditioning : public Device
{
private:
    int temperature;   // temperature value (16–30)

public:
    // Constructor - initialize air conditioner details
    AirConditioning(int id,
        const string& name,
        const string& manu,
        int temp);

    // Override interaction function
    void InteractionEvent() override;

    // Override view information function
    void ViewInfo() const override;

    // Set new temperature
    void SetTemperature(int temp);
};

#endif
