#include "center.h"

Center::Center(){
	this->image = carregaImagem("data/center.png");
	this->box.x = 180;
	this->box.y = 180;
	this->box.w = 40;
	this->box.h = 40;
}

Center::~Center(){

}

void Center::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Center::update(Uint32 delta){

}