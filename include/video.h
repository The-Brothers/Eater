#ifndef VIDEO_H
#define VIDEO_H

#include "SDL/SDL.h"

#define SCREEN_W 400
#define SCREEN_H 400
#define SCREEN_BPP 32

#define FPS 30

class Video{
	SDL_Surface* screen; //The Video screen

public:
	Video();
	~Video();
	SDL_Surface* getScreen();
};

#endif
