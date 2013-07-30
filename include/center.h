#ifndef CENTER_H
#define CENTER_H

#include "SDL/SDL.h"
#include "util.h"

class Center{
	SDL_Surface* image;
	SDL_Rect box;

public:
	Center();
	~Center();

	void draw();
	void update();

};

#endif