#include "SecurityCamera.hpp"
#include <iostream>

using namespace std;


// Initialize SecurityCamera object

SecurityCamera::SecurityCamera(int id,
    const string& name,
    const string& manu,
    const string& quality,
    const string& power)
    : Device(id, name, manu, "Security Camera")
{
    cameraQuality = quality;   // set camera resolution
    powerSource = power;       // set power source
}



// Simulate camera viewing 

void SecurityCamera::InteractionEvent()
{
    // Check if device is ON
    if (!Isactivate())
    {
        cout << "[Warning] Device is OFF.\n";
        cout << "Activate the device before interaction.\n";
        return;
    }

    // Display camera viewing message
    cout << "now viewing camera: " << deviceName << endl;
}



// Display SecurityCamera details 

void SecurityCamera::ViewInfo() const
{
    cout << "\n----------------------------------------\n";

    cout << "Device Type      : Security Camera\n";
    cout << "Device ID        : " << deviceID << endl;
    cout << "Device Name      : " << deviceName << endl;
    cout << "Manufacturer     : " << manufacturer << endl;
    cout << "Camera Quality   : " << cameraQuality << endl;
    cout << "Power Source     : " << powerSource << endl;
    cout << "Status           : " << (status ? "ON" : "OFF") << endl;
    cout << "Connection       : " << (connectionStatus ? "Connected" : "Disconnected") << endl;

    cout << "----------------------------------------\n";
}


// Update camera resolution

void SecurityCamera::SetCameraQuality(const string& quality)
{
    cameraQuality = quality;
}



// Update power source type

void SecurityCamera::SetPowerSource(const string& power)
{
    powerSource = power;
}
