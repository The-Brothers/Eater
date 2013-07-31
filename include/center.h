#ifndef CENTER_H
#define CENTER_H

#include "SDL/SDL.h"
#include "util.h"

class Center{
	SDL_Surface* image;

public:
	SDL_Rect box;
	Center();
	~Center();

	void draw();
	void update(Uint32 delta);

};

#endif