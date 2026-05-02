#include "RoomLighting.hpp"
#include <iostream>

using namespace std;


// Initialize RoomLighting object and validate brightness

RoomLighting::RoomLighting(int id,
    const string& name,
    const string& manu,
    int bright)
    : Device(id, name, manu, "Room Lighting")
{
    // Ensure brightness is within 0–100
    if (bright < 0)
    {
        brightness = 0;
    }
    else if (bright > 100)
    {
        brightness = 100;
    } 
    else
    {
        brightness = bright;
    }
        
}


// Control brightness 

void RoomLighting::InteractionEvent()
{
    // Check if device is ON
    if (!Isactivate())
    {
        cout << "\n[Warning] Room Lighting is OFF.\n";
        cout << "Turn ON the device first.\n";
        return;
    }

    int newBrightness;

    cout << "\n===== ROOM LIGHTING CONTROL =====\n";

    // Validate brightness input
    while (true)
    {
        cout << "Enter brightness (0-100): ";
        cin >> newBrightness;

        if (cin.fail())
        {
            cin.clear();             // clear error
            cin.ignore(1000, '\n');  // remove invalid input
            cout << "Invalid input. Enter numbers only.\n";
        }
        else if (newBrightness < 0 || newBrightness > 100)
        {
            cin.ignore(1000, '\n');
            cout << "Brightness must be between 0 and 100.\n";
        }
        else
        {
            cin.ignore(1000, '\n');
            brightness = newBrightness;  // update brightness
            cout << "Brightness updated successfully.\n";
            break;
        }
    }
}


// Display RoomLighting details 

void RoomLighting::ViewInfo() const
{
    cout << "\n----------------------------------------\n";

    cout << "Device Type     : Room Lighting\n";
    cout << "Device ID       : " << deviceID << endl;
    cout << "Device Name     : " << deviceName << endl;
    cout << "Manufacturer    : " << manufacturer << endl;
    cout << "Brightness      : " << brightness << endl;
    cout << "Status          : "
        << (status ? "ON" : "OFF") << endl;
    cout << "Connection      : "
        << (connectionStatus ? "Connected" : "Disconnected") << endl;

    cout << "----------------------------------------\n";
}


// Update brightness value

void RoomLighting::SetBrightness(int bright)
{
    if (bright >= 0 && bright <= 100)
    {
        brightness = bright;
    }
    else
    {
        cout << "Error: Brightness must be between 0 and 100.\n";
    }
}


// Return brightness value

int RoomLighting::GetBrightness() const
{
    return brightness;
}
