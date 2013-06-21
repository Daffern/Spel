#include "DServer.h"

bool DServer::instanceFlag = false;
DServer* DServer::single = nullptr;
DServer* DServer::getInstance()
{
    if(! instanceFlag)
    {
        single = new DServer();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void DServer::method()
{
    
}