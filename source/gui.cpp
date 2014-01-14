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
	#ifdef PS3
		this->music->loadSound("/dev_hdd0/game/EATER0001/data/sound/music.ogg");
	#else
		this->music->loadSound("data/sound/music.ogg");
	#endif

	//Background
	#ifdef PS3
		this->background = loadImage("/dev_hdd0/game/EATER0001data/background.png");
	#else
		this->background = loadImage("data/background.png");
	#endif
	this->currentstate=state;
}

Gui::~Gui(){
}

void Gui::run(){
	this->music->playSound(MUSIC,1);
	this->running=true;
	*this->currentstate=MENU;
	while(this->running){
		//Events
		#ifdef PS3
			ioPadGetInfo (&this->padinfo);
		    for(int i = 0; i < 2; i++) {
		        if(this->padinfo.status[i]) {
		            ioPadGetData (i, &paddata);
		            if(paddata.BTN_START){
		            	this->running = false;
						*this->currentstate=EXIT;
		            }
		            if(paddata.BTN_CROSS){
		            	this->running = false;
	               		*this->currentstate=INGAME;
		            }
		           
		        }
		    }
    	#else
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
		#endif

		//Render
		SDL_BlitSurface(this->background,NULL,SDL_GetVideoSurface(),NULL);


		SDL_Flip(screen);
		
	
	}
}
