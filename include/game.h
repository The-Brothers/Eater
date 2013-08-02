#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "timer.h"
#include "text.h"

#include "center.h"
#include "player.h"
#include "stream.h"
#include "enemy.h"
#include "healthbar.h"

#define SCREEN_W 400
#define SCREEN_H 400
#define SCREEN_BPP 32

#define FPS 30

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

	enum States {menu,inGame,gameOver};
	
	Mix_Chunk *gamemusic;

	States currentStatus;
	int scoreCount;
public:
	Game();
	~Game();
	void run();
	void insertEnemies();
	void centerColision();
	void playerColision();
	void makeSound();
};

#endif
