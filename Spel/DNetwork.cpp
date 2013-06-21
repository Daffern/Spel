#include "DNetwork.h"

// GeorgeGently: i am the are go beings men you know the things bro? XD

Pack* DNetwork::getPackets(sf::Packet packet){
	

	while(packet.endOfPacket() ==false){
		int id;
		packet>>id;

		switch (id){
		case login:
			Login l;
			packet>>l.name>>l.password;

		break;


		}
	}


	Pack *p = new Pack();
	
	return p;
}

sf::Packet DNetwork::addPacket(Pack * pack){


	switch (id){
		case login:
			Login l;
			packet>>l.name>>l.password;

		break;


		}
	packet<<


}

if (typeid(*ptr) == typeid(DerivedType) {
    /* ... ptr points to a DerivedType ... */
}