#ifndef _DSERVER_H_
#define _DSERVER_H_


class DServer{
public:
	
	static DServer* getInstance();
    void method();
    ~DServer()
    {
        instanceFlag = false;
    }
private:
    static bool instanceFlag;
    static DServer *single;
    
};

#endif