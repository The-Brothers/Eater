#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
#include "text.h"

#include <iostream>
using namespace std;

Game::Game(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;

	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("Eater",NULL);
	TTF_Init();
	this->running = true;

	//Game stuff
	this->center = new Center();
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
	TTF_Quit();
	SDL_Quit();
}

void Game::run(){

	while(this->running){
		this->start = SDL_GetTicks();
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
				break;
				case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                    	case SDLK_ESCAPE:
                        	this->running = false;
                        break;
                        default:;
                    }
			}
		}
		//Logic
		
		//Render
		this->center->draw();
		SDL_Flip(screen);
		
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}
