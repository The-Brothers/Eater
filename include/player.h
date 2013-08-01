#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

class Player{
	SDL_Surface* image;
	

	int pos;
public:
	SDL_Rect box;
	Player();
	~Player();

	void draw();
	void update(Uint32 delta);

	void move(int direction);
};

#endif