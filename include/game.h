#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "center.h"

#define SCREEN_W 400
#define SCREEN_H 400
#define SCREEN_BPP 32

#define FPS 30

class Game{

	SDL_Surface* screen; //The game screen
	SDL_Event events; //The input events

	Uint32 start; //FPS control

	bool running; //Sets the game running


	//Game stuff
	Center* center;
public:
	Game();
	~Game();
	void run();
};

#endif
