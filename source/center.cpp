#include "center.h"

Center::Center(){
	this->image = loadImage("data/center.png");
	this->box.x = 180;
	this->box.y = 180;
	this->box.w = 40;
	this->box.h = 40;
}

Center::~Center(){
	SDL_FreeSurface(this->image);
}

void Center::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Center::update(Uint32 delta){

}