#include "DPanel.h"


DPanel::DPanel(int x, int y, int width, int height):DComponent(x,y,width,height){

	mouseDownFunc=NULL;
	mouseUpFunc=NULL;
	keyUpFunc=NULL;
	keyDownFunc=NULL;

	rect.setPosition(x,y);
	rect.setSize(sf::Vector2f(width,height));
	rect.setOutlineThickness(3);
	rect.setOutlineColor(sf::Color::Blue);


	moving=false;
}
void DPanel::draw(sf::RenderWindow & rw){

	if (visible){
		//std::cout<<moving;

		rw.draw(rect);

		for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
			(*it)->draw(rw);

		}
	}

}
void DPanel::addComponent(DComponent *dc){
	dc->setPosition(dc->x+x,dc->y+y);
	DComponents.push_back(dc);
}
void DPanel::mouseMove(int mouseX, int mouseY){
	if (active){
		if (moving){

			setPosition(mouseX-xLength,mouseY-yLength);


		}
		for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
			(*it)->mouseMove(mouseX,mouseY);
		} 
	}

}

bool DPanel::mouseDown(int button, int x, int y){


	bool test=false;
	if (active){
		test=true;
		if (Limits::checkBounds(x,y,this->x,this->y,width, height)){

			for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
				if ((*it)->mouseDown(button,x,y)){
					test=false;
				}

			}
			if (test){
				moving=true;

				xLength=x-this->x;
				yLength=y-this->y;

			}
		}
		else test=false;
	}

	return test;
}
bool DPanel::mouseUp(int button, int x, int y){
	moving=false;

	bool test=false;
	if (active){
		test=true;
		if (Limits::checkBounds(x,y,this->x,this->y,width, height)){
			for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
				if (!(*it)->mouseUp(button,x,y)){
					test=false;
				}
			}
		}
	}
	std::cout<<"mouseUp ";

	return test;
}
bool DPanel::keyUp(int button){
	if (active){
		for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
			(*it)->keyUp(button);
		}
	}
	return active;
}
bool DPanel::keyDown(int button){
	if (active){
		for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
			(*it)->keyDown(button);
		}
	}
	return active;
}
void DPanel::textEntered(sf::Uint32 c){
	if (active){
		for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
			(*it)->textEntered(c);
		}
	}
}


void DPanel::setPosition(int x, int y){
	rect.setPosition(x,y);

	for(std::list<DComponent*>::iterator it = DComponents.begin() ; it != DComponents.end() ; it++){
		(*it)->setPosition((*it)->x+x-this->x,(*it)->y+y-this->y);
	}
	this->x=x;
	this->y=y;
}
void DPanel::setMouseDownFunc(void (*func)()){
	this->mouseDownFunc = (*func);
}
void DPanel::setMouseUpFunc(void (*func)()){
	this->mouseUpFunc = (*func);
}
void DPanel::setKeyDownFunc(void (*func)()){
	this->keyDownFunc = (*func);
}
void DPanel::setKeyUpFunc(void (*func)()){
	this->keyUpFunc = (*func);
}