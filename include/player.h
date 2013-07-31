#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>

class Player{
	SDL_Surface* image;
	

	int pos;
public:
	SDL_Rect box;
	Player();
	~Player();

	void draw();
	void update(Uint32 delta);

	void move(bool direction);
};

#endif