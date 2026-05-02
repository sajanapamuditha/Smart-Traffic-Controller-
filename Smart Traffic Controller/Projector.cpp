#include "Projector.hpp"
#include <iostream>

using namespace std;



// Initialize Projector object and validate brightness

Projector::Projector(int id,
    const string& name,
    const string& manu,
    int bright,
    const string& inputSrc)
    : Device(id, name, manu, "Projector")
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


    inputSource = inputSrc;  // set input source
}



// Handle projector control menu

void Projector::InteractionEvent()
{
    // Check if device is ON
    if (!Isactivate())
    {
        cout << "\n[Warning] Projector is OFF.\n";
        cout << "Turn ON the device first.\n";
        return;
    }

    int choice;

    // Display control menu
    cout << "\n===== PROJECTOR CONTROL =====\n";
    cout << "Current Brightness : " << brightness << endl;
    cout << "Current Source     : " << inputSource << endl;

    cout << "\n1. Change Brightness\n";
    cout << "2. Change Input Source\n";
    cout << "0. Back\n";

    // Validate menu choice
    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter 0-2 only.\n";
        }
        else if (choice < 0 || choice > 2)
        {
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Enter between 0 and 2.\n";
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }


    switch (choice)
    {
    case 0:
    {
        cout << "Returning...\n";
        return;

    }
    case 1:
    {
        int newBrightness;

        // Validate brightness input
        while (true)
        {
            cout << "Enter brightness (0-100): ";
            cin >> newBrightness;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Numbers only.\n";
            }
            else if (newBrightness < 0 || newBrightness > 100)
            {
                cin.ignore(1000, '\n');
                cout << "Brightness must be 0-100.\n";
            }
            else
            {
                cin.ignore(1000, '\n');
                brightness = newBrightness;  // update brightness
                cout << "Brightness updated successfully.\n";
                break;
            }
        }
        break;
    }

    case 2:
    {
        string newSource;

        // Get new input source
        cout << "Enter input source (HDMI / VGA / Wireless): ";
        getline(cin, newSource);

        if (!newSource.empty())
        {
            inputSource = newSource;  // update source
            cout << "Input source updated successfully.\n";
        }
        else
        {
            cout << "Invalid source.\n";
        }
        break;
    }
    }
}


// Display projector details

void Projector::ViewInfo() const
{
    cout << "\n----------------------------------------\n";

    cout << "Device Type     : Projector\n";
    cout << "Device ID       : " << deviceID << endl;
    cout << "Device Name     : " << deviceName << endl;
    cout << "Manufacturer    : " << manufacturer << endl;
    cout << "Brightness      : " << brightness << endl;
    cout << "Input Source    : " << inputSource << endl;
    cout << "Status          : " << (status ? "ON" : "OFF") << endl;
    cout << "Connection      : " << (connectionStatus ? "Connected" : "Disconnected") << endl;

    cout << "----------------------------------------\n";
}


// Update brightness value

void Projector::SetBrightness(int bright)
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


// Update input source

void Projector::SetInputSource(const string& source)
{
    if (!source.empty())
    {
        inputSource = source;
    }
    else
    {
        cout << "Error: Input source cannot be empty.\n";
    }
}



// Return brightness value

int Projector::GetBrightness() const
{
    return brightness;
}




// Return input source

string Projector::GetInputSource() const
{
    return inputSource;
}
