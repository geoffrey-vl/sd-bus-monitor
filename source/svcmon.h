#ifndef SVCMON_H
#define SVCMON_H

#include <string>

class ServiceMonitor
{
public:
    ServiceMonitor();
    virtual ~ServiceMonitor();

    std::string getActiveState(const std::string& name);
};

#endif // SVCMON_H
