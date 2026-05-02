#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "Device.hpp"
#include <string>
using namespace std;

// Derived class for Door Lock device
class DoorLock : public Device
{
private:
    bool locked;              
    string lastOpenedBy;     

public:

    // Constructor - initialize door lock details
    DoorLock(int id,
        const string& name,
        const string& manu,
        bool lockState,
        const string& lastUser);

    // Override interaction function
    void InteractionEvent() override;

    // Override view information function
    void ViewInfo() const override;

    // Set lock state
    void SetLocked(bool lockState);

    // Set last opened user
    void SetLastOpenedBy(const string& user);

    // Get lock state
    bool IsLocked() const;

    // Get last opened user
    string GetLastOpenedBy() const;
};

#endif
