#ifndef STREAM_H
#define STREAM_H

#include "SDL/SDL.h"
#include "util.h"
#include "enemy.h"
#include <vector>

using namespace std;

class Stream{

	SDL_Surface* image;
	SDL_Rect box;


	int id;

public:
	vector<Enemy *> enemies;
	Stream(int id);
	~Stream();

	void draw();
	void update(Uint32 delta);

	void drawEnemies();
	void insertEnemy();
};
#endif