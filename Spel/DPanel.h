
#ifndef _DPANEL_H_
#define _DPANEL_H_

#include "DComponent.h"
#include "Limits.h"
#include <SFML\Window\Event.hpp>

class DPanel:public DComponent{
public:
	DPanel(int x,int y,int width, int height);
	void draw(sf::RenderWindow & rw);
	void addComponent(DComponent *dc);
	void setPosition(int x, int y);

	bool mouseDown(int button,int x,int y);
	bool mouseUp(int button,int x,int y);
	bool keyDown(int key);
	bool keyUp(int key);
	void textEntered(sf::Uint32 c);
	void mouseMove(int x, int y);

	void setMouseUpFunc(void (*func)());
	void setMouseDownFunc(void (*func)());
	void (*mouseDownFunc)();
	void (*mouseUpFunc)();

	void setKeyUpFunc(void (*func)());
	void setKeyDownFunc(void (*func)());
	void (*keyDownFunc)();
	void (*keyUpFunc)();

	bool moving;
	int xLength,yLength;

	sf::RectangleShape rect;

};

#endif