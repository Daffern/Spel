
#ifndef _DBUTTON_H_
#define _DBUTTON_H_


#include "DComponent.h"
#include "Limits.h"

class DButton:public DComponent{
public:
	DButton(int x, int y, int width, int height, sf::String);


	void draw(sf::RenderWindow & rw);

	void setPosition(int x, int y);

	bool mouseDown(int button,int x,int y);
	bool mouseUp(int button,int x,int y);


	void setMouseUpFunc(void (*func)());
	void setMouseDownFunc(void (*func)());
	void (*mouseDownFunc)();
	void (*mouseUpFunc)();

	sf::Font font;
	sf::Text text;
	sf::RectangleShape rect;
};

#endif