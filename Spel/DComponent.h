
#ifndef _DCOMPONENT_H_
#define _DCOMPONENT_H_

#include <list>
#include <SFML\Graphics.hpp>
#include <iostream>
class DComponent{
public:
	DComponent(int x,int y, int width, int heigth);
	virtual void draw(sf::RenderWindow & rw){}

	virtual void addComponent(DComponent *dc);

	virtual bool mouseDown(int button,int x,int y){return false;}
	virtual bool mouseUp(int button,int x,int y){return false;}
	virtual bool keyUp(int button){return false;}
	virtual bool keyDown(int button){return false;}
	
	virtual void mouseMove(int,int){};
	virtual void textEntered(sf::Uint32 c){}

	virtual void setPosition(int x, int y);


	std::list<DComponent*> DComponents;

	bool visible;
	bool active;
	int x;
	int y;
	int width;
	int height;

};

#endif