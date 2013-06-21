#include "ClientMain.h"


ClientMain::ClientMain(int x, int y, int width, int height):DPanel( x, y, width,  height){

	DNetwork * net = DNetwork::getInstance();
}

void ClientMain::draw(sf::RenderWindow & rw){
	DPanel::draw(rw);
}

void ClientMain::textEntered(sf::Uint32 c){

}