#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Device.hpp"
#include "SecurityCamera.hpp"
#include "AirConditioning.hpp"
#include "Projector.hpp"
#include "RoomLighting.hpp"
#include "DoorLock.hpp"
using namespace std;

// Class that manages all devices in the system
class DeviceManager
{
private:
    struct DeviceNode
    {
        Device* device;
        DeviceNode* next;
    };

    DeviceNode* head;

public:
    // Constructor
    DeviceManager();

    // Check if device list is empty
    bool IsEmpty() const;

    // Safely read integer within range
    int ReadIntSafe(int min, int max);

    // Safely read non-empty string
    string ReadStringSafe();

    // Run main system menu
    void Run();

    // Add new device to system
    void RegisterDevice();

    // Display all registered devices
    void DisplayAllDevices() const;

    // Turn ON / OFF all devices
    void TurnOnAllDevices();        
    void TurnOffAllDevices();     

    // Edit selected device details
    void EditDevice();             

    // Connect or disconnect device
    void ConnectDisconnectDevice(); 

    // Remove device from system
    void RemoveDevice();           

    // Control a single device
    void ControlDevice();

    // Show connected /disconnected devices
    void ViewConnectedDevices() const;    
    void ViewDisconnectedDevices() const;  

    // Delete all devices and free memory
    void ClearAll();                
};

#endif
