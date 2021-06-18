#include "svcmon.h"
#include <sdbus-c++/sdbus-c++.h>

ServiceMonitor::ServiceMonitor()
{
}

ServiceMonitor::~ServiceMonitor()
{
}


std::string ServiceMonitor::getActiveState(const std::string& name)
{
    // Create proxy object for the concatenator object on the server side. Since here
    // we are creating the proxy instance without passing connection to it, the proxy
    // will create its own connection automatically, and it will be system bus connection.
    std::string destinationName = "org.freedesktop.systemd1";
    std::string objectPath = "/org/freedesktop/systemd1/unit/" + name;
    auto proxy = sdbus::createProxy(destinationName.c_str(), objectPath.c_str());

    sdbus::Variant var = proxy->getProperty("ActiveState").onInterface("org.freedesktop.systemd1.Unit");
    return var.get<std::string>();
}