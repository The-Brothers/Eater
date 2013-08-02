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

}

Stream::~Stream(){
	SDL_FreeSurface(this->image);
}

void Stream::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
	drawEnemies();
}

void Stream::update(Uint32 delta){
	for(int i=0;i<(int)this->enemies.size();i++){
		this->enemies[i]->update(delta);
	}
}

void Stream::drawEnemies(){
	for(int i=0;i<(int)this->enemies.size();i++){
		this->enemies[i]->draw();
	}
}

void Stream::insertEnemy(){
	this->enemies.push_back(new Enemy(this->id));
}