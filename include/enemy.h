#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "util.h"

class Enemy{

	SDL_Surface* image;

	float x, y;

	float deltax;
	float deltay;

	float speed;

public:
	SDL_Rect box;
	Enemy(int origin);
	~Enemy();

	void draw();
	void update(Uint32 delta);
};

#endif