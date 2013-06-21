#include "DComponent.h"
#include "Limits.h"

#include <iterator>

DComponent::DComponent(int x, int y, int width, int height){
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->visible=true;
	this->active=true;

}

void DComponent::addComponent(DComponent *dc){
	DComponents.push_back(dc);
}

void DComponent::setPosition(int x, int y){
	this->x=x;
	this->y=y;
}


