#ifndef GUI_H
#define GUI_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "text.h"

#include "sound.h"
class Gui{

	SDL_Surface* screen; //The gui screen
	SDL_Event events; //The input events

	bool running; //Sets the gui running

	//gui stuff
	SDL_Surface *background;

	Text* score;

	Sound *music;
	int * currentstate;

public:
	Gui(SDL_Surface * screen,  int *state);
	~Gui();
	void run();
};

#endif
