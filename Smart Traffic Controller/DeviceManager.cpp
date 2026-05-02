#include <iostream>
#include <iomanip>

#include "DeviceManager.hpp"


using namespace std;


// CONSTRUCTOR
DeviceManager::DeviceManager()
{
    head = nullptr;
}


// CHECK EMPTY
bool DeviceManager::IsEmpty() const
{
    return head == nullptr;
}

// Safe integer input with validation
int DeviceManager::ReadIntSafe(int min, int max)
{
    string input;
    int value;

    while (true)
    {
        getline(cin, input);  // read full line

        // Check if empty
        if (input.empty())
        {
            cout << "Input cannot be empty. Enter number between " << min << " and " << max << ": ";
            continue;
        }

        // Check if all characters are digits
        bool valid = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Invalid input! Enter numbers between" << min << " and " << max << ": ";
            continue;
        }

        // Convert string to integer
        value = stoi(input);

        // Check range
        if (value < min || value > max)
        {
            cout << "Invalid range! Enter between "
                << min << " and " << max << ": ";
            continue;
        }

        return value;
    }
}

// Safe integer input with validation
string DeviceManager::ReadStringSafe()
{
    string text;

    while (true)
    {
        getline(cin, text);

        if (text.empty())
        {
            cout << "Input cannot be empty. Try again: ";
            continue;
        }

        return text;
    }
}

// MAIN SYSTEM MENU 
void DeviceManager::Run()
{
    int option;

    do
    {
        cout << "\n========================================\n";
        cout << "        UNIVERSITY DEVICE CONTROLLER\n";
        cout << "========================================\n\n";

        cout << "1. Register New Device\n";
        cout << "2. Display All Devices\n";
        cout << "3. Turn ON All Devices\n";
        cout << "4. Turn OFF All Devices\n";
        cout << "5. Connect or Disconnect Device\n";
        cout << "6. Edit a Device\n";
        cout << "7. Remove a Device\n";
        cout << "8. Control a Device\n";
        cout << "9. View Connected Devices\n";
        cout << "10. View Disconnected Devices\n";
        cout << "11. Exit System\n\n";

        cout << "Enter option: ";
        option = ReadIntSafe(1, 11);

        switch (option)
        {
        case 1:
            RegisterDevice();
            break;

        case 2:
            DisplayAllDevices();
            break;

        case 3:
            TurnOnAllDevices();
            break;

        case 4:
            TurnOffAllDevices();
            break;

        case 5:
            ConnectDisconnectDevice();
            break;

        case 6:
            EditDevice();
            break;

        case 7:
            RemoveDevice();
            break;

        case 8:
            ControlDevice();
            break;

        case 9:
            ViewConnectedDevices();
            break;

        case 10:
            ViewDisconnectedDevices();
            break;

        case 11:
            ClearAll();   // free linked list memory
            cout << "\nExiting system...\n";
            break;
        }

    } while (option != 11);
}


// function to register a new device
void DeviceManager::RegisterDevice()
{
    cout << "\n========= REGISTER NEW DEVICE =========\n";
    int deviceType;

    while (true)
    {
        cout << "1. Security Camera\n";
        cout << "2. Air Conditioning\n";
        cout << "3. Projector\n";
        cout << "4. Room Lighting\n";
        cout << "5. Door Lock\n";
        cout << "0. Cancel\n";

        cout << "Enter choice: ";
        deviceType = ReadIntSafe(0, 5);

        if (deviceType == 0)
        {
            return;
        }
           

        break;
    }

    int deviceId;

    while (true)  // loop until valid ID
    {
        cout << "Enter Device ID: ";
        deviceId = ReadIntSafe(1, 10000);

        // Check duplicate
        DeviceNode* check = head;              // start from head
        bool exists = false;                   // duplicate flag

        while (check != nullptr)               // traverse list
        {
            if (check->device->GetID() == deviceId)
            {
                exists = true;
                break;
            }
            check = check->next;
        }

        if (exists)                            // if duplicate
        {
            cout << "Device ID already exists. Try again.\n";
            continue;                          // ask again
        }

        break;                                 // valid ID
    }

    cout << "Enter Device Name: ";
    string deviceName = ReadStringSafe();

    cout << "Enter Manufacturer: ";
    string manufacturer = ReadStringSafe();

    Device* newDevice = nullptr;              // pointer for new device

    // SECURITY CAMERA
    if (deviceType == 1)
    {
        cout << "Select Quality:\n";
        cout << "1. 360p\n";
        cout << "2. 480p\n";
        cout << "3. 720p\n";
        cout << "4. 1080p\n";
        cout << "5. 4K\n";
        cout << "Enter choice: ";

        int qua = ReadIntSafe(1, 5);

        string quality;

        switch (qua)
        {
        case 1: quality = "360p"; 
            break;
        case 2: quality = "480p";
            break;
        case 3: quality = "720p";
            break;
        case 4: quality = "1080p";
            break;
        case 5: quality = "4K";
            break;
        }

        cout << "\nPower Source:\n";          // show power menu
        cout << "1. Mains\n";
        cout << "2. Battery\n";
        cout << "3. Batter+Solar\n";
        cout << "Enter choice: ";

        int pow = ReadIntSafe(1, 3);

        string power;

        switch (pow)
        {
        case 1: power = "Mains";
            break;
        case 2: power = "Battery"; 
            break;
        case 3: power = "Batter+Solar"; 
            break;
        }

        newDevice = new SecurityCamera(deviceId, deviceName, manufacturer, quality, power); // create object
    }

    // AIR CONDITIONING
    else if (deviceType == 2)
    {
        cout << "Temperature (16-30): ";
        int temp = ReadIntSafe(16, 30);

        newDevice = new AirConditioning(deviceId, deviceName, manufacturer, temp);
    }

    // PROJECTOR
    else if (deviceType == 3)
    {
        cout << "Brightness (0-100): ";
        int bright = ReadIntSafe(0, 100);

        cout << "Source:\n";
        cout << "1. VGA\n";
        cout << "2. HDMI\n";
        cout << "3. Wireless\n";
        cout << "Enter choice: ";

        int sour = ReadIntSafe(1, 3);

        string source =
            (sour == 1) ? "VGA" :
            (sour == 2) ? "HDMI" : "Wireless";

        newDevice = new Projector(deviceId, deviceName, manufacturer, bright, source);
    }

    // ROOM LIGHTING
    else if (deviceType == 4)
    {
        cout << "Brightness (0-100): ";
        int bright = ReadIntSafe(0, 100);

        newDevice = new RoomLighting(deviceId, deviceName, manufacturer, bright);
    }

    // DOOR LOCK
    else if (deviceType == 5)
    {
        cout << "Locked?\n";
        cout << "1. Yes\n";
        cout << "0. No\n";
        cout << "Enter choice: ";

        int locked = ReadIntSafe(0, 1);

        cout << "Last opened by: ";
        string user = ReadStringSafe();

        newDevice = new DoorLock(deviceId, deviceName, manufacturer, locked == 1, user);
    }

    // Insert into linked list
    DeviceNode* newNode = new DeviceNode;     // create node
    newNode->device = newDevice;              // assign device
    newNode->next = nullptr;                  

    if (head == nullptr)                      // if list empty
    {
        head = newNode;                       // new node becomes head
    }

    else
    {
        DeviceNode* current = head;           // start from head

        while (current->next != nullptr)      // go to last node
        {
            current = current->next;
        }
           

        current->next = newNode;              // attach new node
    }

    cout << "\nDevice Registered Successfully.\n";
}


// function to display all registered devices
void DeviceManager::DisplayAllDevices() const
{
    if (IsEmpty())  // check if list is empty
    {
        cout << "No devices registered.\n";
        return;
    }

    cout << "\n================================================================================\n";


    cout << left
        << setw(6) << "ID"
        << setw(20) << "TYPE"
        << setw(20) << "NAME"
        << setw(10) << "STATUS"
        << setw(15) << "CONNECTION"
        << endl;

    cout << "================================================================================\n";

    DeviceNode* current = head;  // start from head node

    while (current != nullptr)   // loop through linked list
    {
        Device* device = current->device;  // get device pointer

        // Print device details in table format
        cout << left
            << setw(6) << device->GetID()
            << setw(20) << device->GetType()
            << setw(20) << device->GetName()
            << setw(10) << (device->Isactivate() ? "ON" : "OFF")
            << setw(15) << (device->CheckConnection() ? "Connected" : "Disconnected")
            << endl;

        current = current->next;  // move to next node
    }

    cout << "================================================================================\n"; 
}


// function to turn ON all devices
void DeviceManager::TurnOnAllDevices()
{
    if (IsEmpty())
    {
        cout << "\nNo devices available.\n";
        return;
    }

    // Print title
    cout << "\n========================================\n";
    cout << "          ACTIVATING ALL DEVICES\n";
    cout << "========================================\n\n";

    // Table Header
    cout << left
        << setw(20) << "DEVICE NAME"
        << setw(20) << "TYPE"
        << setw(10) << "STATUS" << endl;

    cout << "------------------------------------------------------------\n";

    DeviceNode* current = head;

    while (current != nullptr)  // loop through all devices
    {
        current->device->activate();  // turn ON device

        // Print updated status
        cout << left
            << setw(20) << current->device->GetName()
            << setw(20) << current->device->GetType()
            << setw(10) << "ON" << endl;

        current = current->next;
    }

    cout << "------------------------------------------------------------\n";
    cout << "All devices activated successfully.\n";
}


// function to turn OFF all devices
void DeviceManager::TurnOffAllDevices()
{
    if (IsEmpty())
    {
        cout << "\nNo devices available.\n";
        return;
    }

    // Print title
    cout << "\n========================================\n";
    cout << "         DEACTIVATING ALL DEVICES\n";
    cout << "========================================\n\n";

    // Table Header
    cout << left
        << setw(20) << "DEVICE NAME"
        << setw(20) << "TYPE"
        << setw(10) << "STATUS" << endl;

    cout << "------------------------------------------------------------\n";

    DeviceNode* current = head;

    while (current != nullptr)
    {
        current->device->deactivate();

        // Print updated status
        cout << left
            << setw(20) << current->device->GetName()
            << setw(20) << current->device->GetType()
            << setw(10) << "OFF" << endl;

        current = current->next;
    }

    cout << "------------------------------------------------------------\n";
    cout << "All devices deactivated successfully.\n";
}

// function to connect or disconnect device
void DeviceManager::ConnectDisconnectDevice()
{
    if (IsEmpty())
    {
        cout << "No devices available.\n";
        return;
    }

    cout << "\n=========== CONNECT / DISCONNECT DEVICE ===========\n";

    DeviceNode* current = head;
    int index = 1;

    // Display devices with connection status
    while (current != nullptr)
    {
        cout << index << ". "
            << current->device->GetName()
            << " - " << current->device->GetType()
            << " ("
            << (current->device->CheckConnection() ? "Connected" : "Disconnected")
            << ")\n";

        current = current->next;
        index++;
    }

    cout << "Enter device number: ";
    int choice = ReadIntSafe(1, index - 1);

    current = head;
    index = 1;

    while (current != nullptr && index < choice)  // find selected device
    {
        current = current->next;
        index++;
    }

    if (current == nullptr)   // invalid selection
    {
        cout << "Invalid device number.\n";
        return;
    }

    Device* device = current->device;  // selected device

    cout << "\n1. Connect\n";
    cout << "2. Disconnect\n";
    cout << "Enter choice: ";

    int option = ReadIntSafe(1, 2);

    if (option == 1)
    {
        device->Connect();
        cout << "Device connected successfully.\n";
    }
    else
    {
        device->Disconnect();
        cout << "Device disconnected successfully.\n";
    }

}

// function to edit devices
void DeviceManager::EditDevice()
{
    if (IsEmpty())
    {
        cout << "No devices available.\n";
        return;
    }

    cout << "\n=========== EDIT DEVICE ===========\n";

    DeviceNode* current = head;
    int index = 1;

    while (current != nullptr)   // display all device
    {
        cout << index << ". "
            << current->device->GetName()
            << " (" << current->device->GetType() << ")\n";

        current = current->next;
        index++;
    }

    cout << "Enter device number: ";
    int choice = ReadIntSafe(1, index - 1);

    current = head;   // reset pointer
    index = 1;   // reset index

    while (current != nullptr && index < choice)   // find selected device
    {
        current = current->next;
        index++;
    }

    if (current == nullptr)   // check if invalid
    {
        cout << "Invalid device number.\n";
        return;
    }

    Device* device = current->device;   // get selected device

    if (device->CheckConnection())   // allow edit only if connected
    {
        cout << "\nEditing Device: " << device->GetName() << endl;

        // Edit name
        cout << "Enter new device name: ";
        string newName = ReadStringSafe();
        device->SetName(newName);

        // Edit power
        cout << "Power (1=ON, 0=OFF): ";
        int power = ReadIntSafe(0, 1);

        if (power == 1)
        {
            device->activate();
        }
        else
        {
            device->deactivate();
        }

        // Edit device-specific attributes
        string type = device->GetType();   // get device type


        if (type == "Security Camera")
        {
            SecurityCamera* cam = (SecurityCamera*)device;

            // Edit Camera Quality
            cout << "Select Camera Quality:\n";
            cout << "1. 360p\n";
            cout << "2. 480p\n";
            cout << "3. 720p\n";
            cout << "4. 1080p\n";
            cout << "5. 4K\n";
            cout << "Enter choice: ";

            int qualityChoice = ReadIntSafe(1, 5);

            string newQuality;

            switch (qualityChoice)
            {
            case 1: newQuality = "360p";
                break;
            case 2: newQuality = "480p";
                break;
            case 3: newQuality = "720p"; 
                break;
            case 4: newQuality = "1080p";
                break;
            case 5: newQuality = "4K"; 
                break;
            }

            cam->SetCameraQuality(newQuality);

            // Edit Power Source
            cout << "\nSelect Power Source:\n";
            cout << "1. Mains\n";
            cout << "2. Battery\n";
            cout << "3. Battery + Solar\n";
            cout << "Enter choice: ";

            int powerChoice = ReadIntSafe(1, 3);

            string newPower;

            switch (powerChoice)
            {
            case 1: newPower = "Mains";
                break;
            case 2: newPower = "Battery"; 
                break;
            case 3: newPower = "Battery + Solar";
                break;
            }

            cam->SetPowerSource(newPower);
        }
        else if (type == "Air Conditioning")
        {
            AirConditioning* ac = (AirConditioning*)device;  // cast pointer

            cout << "Temperature (16-30): ";
            ac->SetTemperature(ReadIntSafe(16, 30));
        }
        else if (type == "Projector")
        {
            Projector* proj = (Projector*)device;

            // Edit Brightness
            cout << "Brightness (0-100): ";
            proj->SetBrightness(ReadIntSafe(0, 100));

            // Edit Input Source
            cout << "Select Input Source:\n";
            cout << "1. VGA\n";
            cout << "2. HDMI\n";
            cout << "3. Wireless\n";
            cout << "Enter choice: ";

            int sourceChoice = ReadIntSafe(1, 3);

            string newSource =
                (sourceChoice == 1) ? "VGA" :
                (sourceChoice == 2) ? "HDMI" : "Wireless";

            proj->SetInputSource(newSource);
        }

        else if (type == "Room Lighting")
        {
            RoomLighting* light = (RoomLighting*)device;
            cout << "Brightness (0-100): ";
            light->SetBrightness(ReadIntSafe(0, 100));   // set brightness
        }
        else if (type == "Door Lock")
        {
            DoorLock* lock = (DoorLock*)device;

            cout << "Lock State (1=Locked, 0=Unlocked): ";
            lock->SetLocked(ReadIntSafe(0, 1) == 1);   // update lock state

            cout << "Last opened by: ";
            lock->SetLastOpenedBy(ReadStringSafe());   // update username
        }
    }
    else   // if device is disconnected
    {
        cout << "Device is disconnected. Attributes cannot be edited.\n";
    }

    cout << "\nDevice updated successfully.\n";
}

// function to remove a device
void DeviceManager::RemoveDevice()
{
    if (IsEmpty())
    {
        cout << "\nNo devices available to remove.\n";
        return;
    }

    cout << "\n=========== REMOVE DEVICE ===========\n";

    DeviceNode* current = head;   // pointer to traverse list
    int index = 1;                // numbering devices

    // Display all devices
    cout << "No\tID\tName\t\tType\n";
    cout << "----------------------------------------\n";

    while (current != nullptr)   // show device list
    {
        cout << index << "\t"
            << current->device->GetID() << "\t"
            << current->device->GetName() << "\t\t"
            << current->device->GetType() << endl;

        current = current->next;
        index++;
    }

    cout << "----------------------------------------\n";

    // Ask user choice
    cout << "Enter device number to remove (0 to cancel): ";

    int choice;
    choice = ReadIntSafe(0, index - 1);


    if (choice == 0)
    {
        cout << "Remove cancelled.\n";
        return;
    }

    // Find selected device
    current = head;               // reset pointer
    DeviceNode* previous = nullptr; // track previous node
    index = 1;                    // reset index

    while (current != nullptr && index < choice)  // locate selected device
    {
        previous = current;
        current = current->next;
        index++;
    }

    if (current == nullptr)   // invalid selection
    {
        cout << "Invalid device number.\n";
        return;
    }

    // Store info before deleting
    string name = current->device->GetName();
    int id = current->device->GetID();

    // Remove node
    if (previous == nullptr)   // if first node
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }
        

    delete current->device;  // delete device object
    delete current;          // delete node

    cout << "\nDevice removed successfully.\n";
    cout << "Removed Device: " << name << " (ID: " << id << ")\n";
}

// function to control  device
void DeviceManager::ControlDevice()
{
    if (IsEmpty())
    {
        cout << "No devices available.\n";
        return;
    }

    DeviceNode* current;   // pointer to traverse list
    int choice;

    // LOOP until valid device selected
    while (true)
    {
        cout << "\n=========== SELECT DEVICE ===========\n";

        current = head;   // start from first device
        int index = 1;    // numbering devices

        while (current != nullptr)   // display all devices
        {
            cout << index << ". "
                << current->device->GetName()
                << " (" << current->device->GetType() << ")\n";

            current = current->next;
            index++;
        }

        cout << "Enter choice: ";
        choice = ReadIntSafe(1, index - 1);

        current = head;   // reset pointer
        index = 1;        // reset index

        while (current != nullptr && index < choice)  // find selected device
        {
            current = current->next;
            index++;
        }

        if (current == nullptr)   // if invalid selection
        {
            cout << "Invalid choice. Try again.\n";
            continue;   // repeat selection
        }

        break;
    }

    Device* device = current->device;   // selected device pointer

    // Check connection before control
    if (!device->CheckConnection())
    {
        cout << "\nDevice is DISCONNECTED.\n";
        cout << "Please connect the device first.\n";
        return;   // stop control
    }

    int option;

    while (true)   // device control loop
    {
        cout << "\n=========== DEVICE CONTROL ===========\n";

        cout << "Power      : "
            << (device->Isactivate() ? "ON" : "OFF") << endl;

        cout << "\n1. Activate\n";
        cout << "2. Deactivate\n";
        cout << "3. InteractionEvent\n";
        cout << "4. View Info\n";
        cout << "0. Back\n";

        cout << "Enter option: ";
        option = ReadIntSafe(0, 4);

        switch (option)
        {
        case 0:
            cout << "Returning...\n";
            return;   

        case 1:
            device->activate();
            cout << "Device turned ON.\n";
            break;

        case 2:
            device->deactivate();
            cout << "Device turned OFF.\n";
            break;

        case 3:
            device->InteractionEvent();  // polymorphism
            break;

        case 4:
            device->ViewInfo();   // polymorphism
            break;
        }
    }

}

// function to show connected devices
void DeviceManager::ViewConnectedDevices() const
{
    DeviceNode* current = head;
    bool found = false;           // flag to check if any device found

    cout << "\nConnected Devices:\n";
    cout << "-------------------------------------------------\n";
    cout << "ID\tName\t\tStatus\t\tConnection\n";
    cout << "-------------------------------------------------\n";

    while (current != nullptr)   // loop through list
    {
        if (current->device->CheckConnection())
        {
            cout << current->device->GetID() << "\t"
                << current->device->GetName() << "\t\t"
                << (current->device->Isactivate() ? "ON" : "OFF") << "\t\t"
                << "Connected"
                << endl;

            found = true;   // mark as found
        }

        current = current->next;
    }

    if (!found)   // if no connected devices
    {
        cout << "No connected devices.\n";
    }

    cout << "-------------------------------------------------\n";
}

// function to show disconnected devices
void DeviceManager::ViewDisconnectedDevices() const
{
    DeviceNode* current = head;
    bool found = false;

    cout << "\nDisconnected Devices:\n";
    cout << "-------------------------------------------------\n";
    cout << "ID\tName\t\tStatus\t\tConnection\n";
    cout << "-------------------------------------------------\n";

    while (current != nullptr)   // loop through list
    {
        if (!current->device->CheckConnection())
        {
            cout << current->device->GetID() << "\t"
                << current->device->GetName() << "\t\t"
                << (current->device->Isactivate() ? "ON" : "OFF") << "\t\t"
                << "Disconnected"
                << endl;

            found = true;
        }

        current = current->next;
    }

    if (!found)
    {
        cout << "No disconnected devices.\n";
    }

    cout << "-------------------------------------------------\n";
}

// Delete all devices and free memory
void DeviceManager::ClearAll()
{
    DeviceNode* current = head;  // start from head

    while (current != nullptr)
    {
        DeviceNode* temp = current;
        current = current->next;

        delete temp->device;
        delete temp;
    }

    head = nullptr;  // reset list

}
