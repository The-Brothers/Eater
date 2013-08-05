#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "timer.h"
#include "text.h"

#include "center.h"
#include "sound.h"
#include "player.h"
#include "stream.h"
#include "enemy.h"
#include "healthbar.h"

class Game{

	SDL_Surface* screen; //The game screen
	SDL_Event events; //The input events

	Timer delta;
	Uint32 start; //FPS control

	bool running; //Sets the game running

 	int delayticks;

	//Game stuff
	SDL_Surface *background;
	Center* center;
	Player* player;
	Stream* stream1;
	Stream* stream2;
	Stream* stream3;
	Stream* stream4;

	HealthBar* healthbar;

	Text* score;
	
	Sound *gamemusic;

	int *currentStatus;
	int scoreCount;
public:
	Game(SDL_Surface * screen, int *state);
	~Game();
	void run();
	void insertEnemies();
	void centerColision();
	void playerColision();
};

#endif
