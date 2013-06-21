
#ifndef _DTEXTBOX_H_
#define _DTEXTBOX_H_


#include "DComponent.h"
#include "Limits.h"

class DTextBox:public DComponent{
public:
	DTextBox(int x, int y, int width, int height, sf::String);


	void draw(sf::RenderWindow & rw);

	void setPosition(int x, int y);

	sf::String getText();

	bool mouseDown(int button,int x,int y);
	bool mouseUp(int button,int x,int y);
	bool keyUp(int button);
	bool keyDown(int button);

	void setKeyUpFunc(void (*func)());
	void setKeyDownFunc(void (*func)());

	void textEntered(sf::Uint32 c);


	unsigned char counter;

	unsigned char maxText;
	sf::Font font;
	sf::Text text;
	sf::Text writingText;
	sf::RectangleShape rect;
};

#endif