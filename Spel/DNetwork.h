#ifndef _DNETWORK_H_
#define _DNETWORK_H_

#include <list>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>

enum packets{login,input,output};

class DNetwork{
public:





	sf::Packet addPacket(Pack *pack);
	sf::Packet packet;
	
	Pack * getPackets(sf::Packet packet);
	
};

struct Pack{
	sf::Int8 id;
};

struct Login:Pack{
	Login(){
		id=login;
	}
	sf::String name;
	sf::String password;
};

#endif