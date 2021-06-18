
/**
 * Simple test of sdbus-c++ library where we want to check 
 * the state of a service.
 * Implementation based on feedback from
 * https://stackoverflow.com/questions/61940461/how-to-get-the-state-of-a-service-with-sd-bus.
 * 
 */ 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>       // catch ctrl+c
#include "svcmon.h"


static volatile bool stopApp = false;



void signal_callback_handler(int signum) {
   std::cout << "Caught signal " << signum << std::endl;
   stopApp = true;
}





int main()
{
    std::cout << "SysMon v1.0" << std::endl;
    signal(SIGINT, signal_callback_handler);

    ServiceMonitor svcMon;
    std::string activeState = svcMon.getActiveState("bluetooth_2eservice");
    
    std::cout << "Bluetooth service state: " << activeState << std::endl;

    return 0;
}