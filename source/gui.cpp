#include "gui.h"
#include "util.h"
#include <iostream>
#include <string>
#include "text.h"

#include <iostream>
using namespace std;

Gui::Gui(SDL_Surface * screen, int *state){
	srand (time(NULL));
	this->running = true;

	this->screen=screen;

	//Gui stuff
	this->music= new Sound();
	this->music->loadSound("data/sound/music.ogg");

	//Background
	this->background = loadImage("data/background.png");
	this->currentstate=state;
}

Gui::~Gui(){
}

void Gui::run(){
	this->music->playSound(MUSIC,1);
	
	while(this->running){
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
					*this->currentstate =EXIT;
				break;

				case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {                    	
                    	case SDLK_m:
                    		this->music->mute();
                    	break;

                    	case SDLK_u:
                    		this->music->unMute();
                    	break;

                    	case SDLK_s:
                    		this->running = false;
                    		*this->currentstate=INGAME;
                    	break;

                    	case SDLK_ESCAPE:
	                   		this->running = false;
							*this->currentstate =EXIT;
                        break;

                        default:;
                    }
                break;
			}
		}

		//Render
		SDL_BlitSurface(this->background,NULL,SDL_GetVideoSurface(),NULL);


		SDL_Flip(screen);
		
	
	}
}
