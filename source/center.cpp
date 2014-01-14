#include "center.h"

Center::Center(){
	#ifdef PS3
		this->image = loadImage("/dev_hdd0/game/EATER0001/data/center.png");
	#else
		this->image = loadImage("data/center.png");
	#endif
	this->box.x = 180;
	this->box.y = 180;
	this->box.w = 40;
	this->box.h = 40;
	this->hurt=new Sound();
	#ifdef PS3
		this->hurt->loadSound("/dev_hdd0/game/EATER0001/data/sound/hurt.ogg");
	#else
		this->hurt->loadSound("data/sound/hurt.ogg");
	#endif
	this->hurt->setVolume(SFX,30);
}

Center::~Center(){
	SDL_FreeSurface(this->image);
}

void Center::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Center::update(Uint32 delta){

}