#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "util.h"

class Enemy{

	SDL_Surface* image;
	SDL_Rect box;

	float x, y;

	float deltax;
	float deltay;

	float speed;

public:
	Enemy(int origin);
	~Enemy();

	void draw();
	void update(Uint32 delta);
};

#endif