#ifndef STREAM_H
#define STREAM_H

#include "SDL/SDL.h"
#include "util.h"

class Stream{

	SDL_Surface* image;
	SDL_Rect box;

	int id;

public:
	Stream(int id);
	~Stream();

	void draw();
	void update(Uint32 delta);

	void draw_balls();
};
#endif