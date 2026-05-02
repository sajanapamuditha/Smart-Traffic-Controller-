#include "Device.hpp"

#include <iostream>
using namespace std;


// Initialize base Device object
Device::Device(int id, const string& name, const string& manu, const string& type)
{
    deviceID = id;          
    deviceName = name;      
    manufacturer = manu;   
    deviceType = type;      

    status = false;         // default power OFF
    connectionStatus = true; // default connected
}



// Turn device ON
void Device::activate()
{
    status = true;
}

// Turn device OFF
void Device::deactivate()
{
    status = false;
}

// Check power status
bool Device::Isactivate() const
{
    return status;
}


// Connect device
void Device::Connect()
{
    connectionStatus = true;
}

// Disconnect device
void Device::Disconnect()
{
    connectionStatus = false;
}

// Manually set connection state
void Device::SetConnectionStatus(bool state)
{
    connectionStatus = state;
}

// Check connection status
bool Device::CheckConnection() const
{
    return connectionStatus;
}


// Get device ID
int Device::GetID() const
{
    return deviceID;
}

// Get device name
string Device::GetName() const
{
    return deviceName;
}

// Get manufacturer name
string Device::GetManufacturer() const
{
    return manufacturer;
}

// Get device type
string Device::GetType() const
{
    return deviceType;
}


// Change device name
void Device::SetName(const string& name)
{
    deviceName = name;
}

// Change manufacturer name
void Device::SetManufacturer(const string& manu)
{
    manufacturer = manu;
}

// Virtual Destructor
Device::~Device()
{
   
}
