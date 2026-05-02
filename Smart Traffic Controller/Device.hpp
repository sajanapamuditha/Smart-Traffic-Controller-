#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

// Base class for all smart devices
class Device
{
protected:
    int deviceID;            
    string deviceName;         
    string manufacturer;    
    string deviceType;         

    bool status;               
    bool connectionStatus;     

public:

    // Constructor - initialize basic device details
    Device(int id, const string& name, const string& manu, const string& type);

    // Power control functions
    void activate();         
    void deactivate();         
    bool Isactivate() const;   

    // Connection control functions
    void Connect();            
    void Disconnect();         
    void SetConnectionStatus(bool state);  
    bool CheckConnection() const;       

    // Getter functions
    int GetID() const;
    string GetName() const;
    string GetManufacturer() const;
    string GetType() const;

    // Setter functions
    void SetName(const string& name);
    void SetManufacturer(const string& manu);

    // Virtual functions for polymorphism
    virtual void InteractionEvent() = 0;  
    virtual void ViewInfo() const = 0;    

    // Virtual Destructor
    virtual ~Device();


};

#endif
