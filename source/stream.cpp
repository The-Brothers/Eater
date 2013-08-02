#include "stream.h"

Stream::Stream(int id){
	this->id = id;
	this->image = loadImage("data/stream.png");
	
	switch(this->id){
		case 1:
			this->box.x = 10;
			this->box.y = 10;
		break;
		case 2:
			this->box.x = 360;
			this->box.y = 10;
		break;
		case 3:
			this->box.x = 10;
			this->box.y = 360;
		break;
		case 4:
			this->box.x = 360;
			this->box.y = 360;
		break;
	}

	this->box.w = 30;
	this->box.h = 30;

	for(int i=0;i<6;i++){
		this->clip[i].x = i*this->box.w;
		this->clip[i].y = 0;
		this->clip[i].h = this->box.h;
		this->clip[i].w = this->box.w;
	}

	this->frame = 0;
}

Stream::~Stream(){
	SDL_FreeSurface(this->image);
}

void Stream::draw(){
	SDL_BlitSurface(this->image,&this->clip[(int) (this->frame)],SDL_GetVideoSurface(),&this->box);
	drawEnemies();
}

void Stream::update(Uint32 delta){
	for(int i=0;i<(int)this->enemies.size();i++){
		this->enemies[i]->update(delta);
	}

	this->frame+=0.2f;
	if(this->frame>=5)
		this->frame=0.f;
}

void Stream::drawEnemies(){
	for(int i=0;i<(int)this->enemies.size();i++){
		this->enemies[i]->draw();
	}
}

void Stream::insertEnemy(){
	this->enemies.push_back(new Enemy(this->id));
}