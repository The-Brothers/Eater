#include "healthbar.h"

HealthBar::HealthBar(int hp){
	this->image = loadImage("data/hp.png");
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

