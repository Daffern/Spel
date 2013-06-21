#include "DButton.h"


#include <iostream>

DButton::DButton(int x, int y, int width, int height, sf::String string):DComponent(x,y,width,height){

	mouseDownFunc=NULL;
	mouseUpFunc=NULL;

	rect.setPosition(x,y);
	rect.setSize(sf::Vector2f(width,height));
	rect.setOutlineThickness(3);
	rect.setOutlineColor(sf::Color::Blue);


	font.loadFromFile("data/fonts/7thsc.ttf");
	text.setString(string);
	text.setFont(font);
	text.setColor(sf::Color::Blue);
	text.setPosition(x,y);

	active=true;
}

void DButton::setMouseDownFunc(void (*func)()){
	this->mouseDownFunc = (*func);
}
void DButton::setMouseUpFunc(void (*func)()){
	this->mouseUpFunc = (*func);
}

void DButton::draw(sf::RenderWindow & rw){
	rw.draw(rect);
	rw.draw(text);
}

bool DButton::mouseDown(int button,int x,int y){
	bool test=false;
	if (active){
		if (this->mouseDownFunc!= NULL){
			if (Limits::checkBounds(x,y,this->x,this->y,width, height)){
				test=true;
				this->mouseDownFunc();

			}
		}
	}
	return test;
}
bool DButton::mouseUp(int button,int x,int y){
	bool test=false;
	if (active){
		if (this->mouseUpFunc!= NULL){
			if (Limits::checkBounds(x,y,this->x,this->y,width, height)){
				test=true;
				this->mouseUpFunc();

			}
		}
	}
	return test;
}
void DButton::setPosition(int x, int y){
	this->rect.setPosition(x,y);
	text.setPosition(x,y-3);
	this->x=x;
	this->y=y;
}