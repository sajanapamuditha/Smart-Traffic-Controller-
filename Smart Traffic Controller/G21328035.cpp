#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


#include "DeviceManager.hpp"
       
#include <iostream>     
using namespace std;


int main()
{
    // Create DeviceManager object in HEAP
    DeviceManager* manager = new DeviceManager();

    // Run the system menu
    manager->Run();

    // Free heap memory
    delete manager;
    _CrtDumpMemoryLeaks();
    return 0;
}