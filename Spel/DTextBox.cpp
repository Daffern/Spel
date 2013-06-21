#include "DTextBox.h"


DTextBox::DTextBox(int x, int y, int width, int height, sf::String string):DComponent(x,y,width,height){
	font.loadFromFile("data/fonts/7thsc.ttf");

	maxText=width/30;
	text.setScale(sf::Vector2f((float)(height)/30.0,(float)(height)/30.0));
	text.setString(string);
	text.setFont(font);
	text.setColor(sf::Color::Blue);

	writingText.setFont(font);
	writingText.setColor(sf::Color::Black);
	writingText.setScale(sf::Vector2f((float)(height)/30.0,(float)(height)/30.0));

	rect.setSize(sf::Vector2f(width,height));
	rect.setOutlineThickness(3);
	rect.setOutlineColor(sf::Color::Blue);

	setPosition(x,y);

	active=false;

	counter=0;
}


void DTextBox::draw(sf::RenderWindow & rw){


	counter++;
	if (counter>30){
		writingText.setString(' ');
		if (counter>60){
			writingText.setString('|');
			counter=0;
		}
	}
	rw.draw(rect);
	rw.draw(text);
	if (active)
	rw.draw(writingText);
}

bool DTextBox::mouseDown(int button,int x,int y){

	if (Limits::checkBounds(x,y,this->x,this->y,width, height)){
		active=true;
		return true;
	}
	else{
		active=false;
		return false;
	}
}
bool DTextBox::mouseUp(int button,int x,int y){
	bool test=false;
	if (active){
		if (Limits::checkBounds(x,y,this->x,this->y,width, height)){
			test=true;
		}
	}
	return test;
}
void DTextBox::setPosition(int x, int y){
	this->x=x;
	this->y=y;
	this->rect.setPosition(this->x,this->y);
	text.setPosition(this->x+8,this->y-3);
	writingText.setPosition(this->x,this->y-3);

}
bool DTextBox::keyUp(int button){
	return false;
}
bool DTextBox::keyDown(int button){
	return false;
}
void DTextBox::textEntered(sf::Uint32 c){
	if (active){
		if (c==8){//backslash unicode

			sf::String newstring = text.getString();
			if (newstring.getSize()>0){
				newstring.erase(newstring.getSize()-1,1);

				text.setString(newstring);
			}

		}
		else if (maxText>text.getString().getSize()){
			text.setString(text.getString()+c);
		}
	}
}