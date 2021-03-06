#include "button.h"

using namespace std;

Button::Button(const char* img, int _x, int _y){
	this->image = loadImage(img);
	this->box.x = _x;
	this->box.y = _y;

	this->box.w=this->image->w;
	this->box.h=this->image->h;
}

Button::~Button(){
	SDL_FreeSurface(this->image);
}

void Button::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

//check if the board was clicked or not
bool Button::isClicked(int x, int y){
	//if the mouse click is inside the board coordinates
	if(((x >= this->box.x) && (x<= (this->box.x + this->box.w))) && ((y >= this->box.y) && (y<= (this->box.y + this->box.h))))
		return true;
	return false;
}
