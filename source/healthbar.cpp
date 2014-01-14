#include "healthbar.h"

HealthBar::HealthBar(int hp){
	#ifdef PS3
		this->image = loadImage("/dev_hdd0/game/EATER0001/data/hp.png");
	#else
		this->image = loadImage("data/hp.png");
	#endif
	this->box.x = 125;
	this->box.y = 360;
	this->health_points = hp;
}

HealthBar::~HealthBar(){
	SDL_FreeSurface(this->image);
}

void HealthBar::draw(){
	SDL_Rect temp_box = this->box;
	for(int i=0;i<this->health_points;i++){
		SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&temp_box);
		temp_box.x += 15;
	}
}

void HealthBar::update(Uint32 delta){

}

void HealthBar::removeHp(int quantity){
	if(this->health_points!=0)
		this->health_points -= quantity;
}

