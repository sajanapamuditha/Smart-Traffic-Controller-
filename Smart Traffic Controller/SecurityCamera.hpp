#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.hpp"
#include <string>
using namespace std;

// Derived class for Security Camera device
class SecurityCamera : public Device
{
private:
    string cameraQuality;   
    string powerSource;   

public:

    // Constructor - initialize security camera details
    SecurityCamera(int id,
        const string& name,
        const string& manu,
        const string& quality,
        const string& power);

    // Override interaction function
    void InteractionEvent() override;

    // Override view information function
    void ViewInfo() const override;

    // Set camera quality
    void SetCameraQuality(const string& quality);

    // Set power source
    void SetPowerSource(const string& power);
};

#endif
