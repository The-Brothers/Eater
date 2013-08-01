#include "player.h"
#include "util.h"

Player::Player(){
	this->image = loadImage("data/player.png");
	
	this->box.w = 30;
	this->box.h = 30;

	this->pos = 0;
}

Player::~Player(){
	SDL_FreeSurface(this->image);
}

void Player::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Player::update(Uint32 delta){
	switch(this->pos){
		case 0:
			this->box.x = 150;
			this->box.y = 220;
			break;
		case 1:
			this->box.x = 220;
			this->box.y = 220;
			break;
		case 2:
			this->box.x = 220;
			this->box.y = 150;
			break;
		case 3:
			this->box.x = 150;
			this->box.y = 150;
			break;
	}
}

void Player::move(int direction){

	switch(direction){
		case UP:
			if (this->pos == 0) this->pos = 3;
			if (this->pos == 1) this->pos = 2;
		break;
		case DOWN:
			if (this->pos == 3) this->pos = 0;
			if (this->pos == 2) this->pos = 1;
		break;
		case RIGHT:
			if (this->pos == 0) this->pos = 1;
			if (this->pos == 3) this->pos = 2;
		break;
		case LEFT:
			if (this->pos == 2) this->pos = 3;
			if (this->pos == 1) this->pos = 0;
		break;
	}

//Controle mecanico
	// switch(this->pos){
	// 	case 0:
	// 		if(direction) this->pos = 1;
	// 		else this->pos = 3;
	// 	break;
	// 	case 1:
	// 		if(direction) this->pos = 2;
	// 		else this->pos = 0;
	// 	break;
	// 	case 2:
	// 		if(direction) this->pos = 1;
	// 		else this->pos = 3;
	// 	break;
	// 	case 3:
	// 		if(direction) this->pos = 2;
	// 		else this->pos = 0;
	// 	break;
	// }

//Controle rotativo
	// //true = right = add
	// if(direction){
	// 	if(this->pos == 3)
	// 		this->pos = 0;
	// 	else
	// 		this->pos+=1;
	// }
	// //false = left = subtract
	// else{
	// 	if(this->pos == 0)
	// 		this->pos = 3;
	// 	else
	// 		this->pos-=1;
	// }

}