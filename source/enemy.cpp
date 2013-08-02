#include "enemy.h"

Enemy::Enemy(int origin){
	this->image = loadImage("data/enemy.png");
	
	this->box.h = 30;
	this->box.w = 30;

	this->speed = 100;

	switch(origin){
		case 1:
			this->x = this->box.x = 10;
			this->y = this->box.y = 10;
			this->deltax = this->speed;
			this->deltay = this->speed;
		break;
		case 2:
			this->invert();
			this->x = this->box.x = 365;
			this->y = this->box.y = 10;
			this->deltax = -1 * this->speed;
			this->deltay = this->speed;
		break;
		case 3:
			this->x = this->box.x = 10;
			this->y = this->box.y = 365;
			this->deltax = this->speed;
			this->deltay = -1 * this->speed;
		break;
		case 4:
			this->invert();
			this->x = this->box.x = 365;
			this->y = this->box.y = 365;
			this->deltax = -1 * this->speed;
			this->deltay = -1 * this->speed;
		break;
	}

}

Enemy::~Enemy(){

}

void Enemy::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Enemy::update(Uint32 delta){
	this->x += this->deltax * delta/1000.0f;
	this->y += this->deltay * delta/1000.0f;
	this->box.x = (int) this->x;
	this->box.y = (int) this->y;
}

void Enemy::invert(){
	this->image=flipImage(this->image,FLIP_HORIZONTAL);
}