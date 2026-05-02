#include "DoorLock.hpp"
#include <iostream>

using namespace std;


// Initialize DoorLock object and set lock state
DoorLock::DoorLock(int id,
    const string& name,
    const string& manu,
    bool lockState,
    const string& lastUser)
    : Device(id, name, manu, "Door Lock")
{
    locked = lockState;   // set initial lock state

    // Set last opened user (default = Unknown)
    if (lastUser.empty())
    {
        lastOpenedBy = "Unknown";
    }
    else
    {
        lastOpenedBy = lastUser;
    }

      
}


// Handle lock/unlock menu
void DoorLock::InteractionEvent()
{
    // Check if device is ON
    if (!Isactivate())
    {
        cout << "[Warning] Device is OFF.\n";
        cout << "Activate the device before interaction.\n";
        return;
    }

    // Display lock menu
    cout << "\n========== DOOR LOCK MENU ==========\n";
    cout << "Status      : " << (locked ? "LOCKED" : "UNLOCKED") << endl;
    cout << "Last Opened : " << lastOpenedBy << endl;

    cout << "\n1. Lock Door\n";
    cout << "2. Unlock Door\n";
    cout << "0. Back\n";

    int choice;

    // Validate menu input
    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 0-2.\n";
        }
        else if (choice < 0 || choice > 2)
        {
            cin.ignore(1000, '\n');
            cout << "Invalid option. Enter between 0 and 2.\n";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }

    // Back option
    if (choice == 0)
    {
        cout << "Returning...\n";
        return;
    }

    // Get username
    string user;
    cout << "Enter username: ";
    getline(cin, user);

    // Update last opened user
    lastOpenedBy = user.empty() ? "Unknown" : user;

    // Lock or unlock door
    if (choice == 1)
    {
        locked = true;
        cout << "Door locked successfully by "
            << lastOpenedBy << ".\n";
    }
    else
    {
        locked = false;
        cout << "Door unlocked by "
            << lastOpenedBy << ".\n";
    }
}



// Display full door lock details
void DoorLock::ViewInfo() const
{
    cout << "\n----------------------------------------\n";

    cout << "Device Type     : Door Lock\n";
    cout << "Device ID       : " << deviceID << endl;
    cout << "Device Name     : " << deviceName << endl;
    cout << "Manufacturer    : " << manufacturer << endl;
    cout << "Lock Status     : " << (locked ? "Locked" : "Unlocked") << endl;
    cout << "Last Opened By  : " << lastOpenedBy << endl;
    cout << "Status          : " << (status ? "ON" : "OFF") << endl;
    cout << "Connection      : " << (connectionStatus ? "Connected" : "Disconnected") << endl;

    cout << "----------------------------------------\n";
}



// Update lock state
void DoorLock::SetLocked(bool lockState)
{
    locked = lockState;
}


// Update last opened user
void DoorLock::SetLastOpenedBy(const string& user)
{
    if (!user.empty())
    {
        lastOpenedBy = user;
    }
       
}


// Return lock status
bool DoorLock::IsLocked() const
{
    return locked;
}


// Return last user
string DoorLock::GetLastOpenedBy() const
{
    return lastOpenedBy;
}
