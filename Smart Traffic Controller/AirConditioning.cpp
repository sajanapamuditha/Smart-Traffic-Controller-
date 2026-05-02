#include "AirConditioning.hpp"
#include <iostream>
using namespace std;


// Initialize Air Conditioning object
AirConditioning::AirConditioning(int id,
    const string& name,
    const string& manu,
    int temp)
    : Device(id, name, manu, "Air Conditioning")
{
    temperature = temp;   // set initial temperature
}



// Allows user to change temperature
void AirConditioning::InteractionEvent()
{
    // Check if device is ON
    if (!Isactivate())
    {
        cout << "[Warning] Device is OFF.\n";
        cout << "Activate the device before interaction.\n";
        return;
    }

    int newTemp;

    // Input validation loop
    while (true)
    {
        cout << "Enter new temperature (16-30): ";

        cin >> newTemp;

        // Check invalid input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter numbers only.\n";
            continue;
        }

        // Check temperature range
        if (newTemp < 16 || newTemp > 30)
        {
            cout << "Temperature must be between 16 and 30.\n";
            continue;
        }

        break;
    }

    temperature = newTemp;   // update temperature

    cout << "Temperature updated successfully.\n";
}



// Display full Air Conditioning details
void AirConditioning::ViewInfo() const
{
    cout << "\n----------------------------------------\n";

    cout << "Device Type        : Air Conditioning\n";
    cout << "Device ID          : " << deviceID << endl;
    cout << "Device Name        : " << deviceName << endl;
    cout << "Manufacturer       : " << manufacturer << endl;
    cout << "Temperature        : " << temperature << "°C\n";
    cout << "Status             : " << (status ? "ON" : "OFF") << endl;
    cout << "Connection         : " << (connectionStatus ? "Connected" : "Disconnected") << endl;

    cout << "----------------------------------------\n";
}


// Set temperature directly
void AirConditioning::SetTemperature(int temp)
{
    temperature = temp;
}
