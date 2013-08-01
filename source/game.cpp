#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
#include "text.h"

#include <iostream>
using namespace std;

Game::Game(){
	srand (time(NULL));
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
	this->player = new Player();

	this->stream1 = new Stream(1);
	this->stream2 = new Stream(2);
	this->stream3 = new Stream(3);
	this->stream4 = new Stream(4);

	this->delayticks=0;
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
	TTF_Quit();
	SDL_Quit();
}

void Game::run(){

	this->delta.start();
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
                    	case SDLK_1:
                    		this->stream1->insert_enemy();
                    	break;

                    	case SDLK_2:
                    		this->stream2->insert_enemy();
                    	break;

                    	case SDLK_3:
                    		this->stream3->insert_enemy();
                    	break;

                    	case SDLK_4:
                    		this->stream4->insert_enemy();
                    	break;

                    	case SDLK_UP:
                    		this->player->move(UP);                    		
                    	break;
                    	case SDLK_DOWN:
                    		this->player->move(DOWN);
                    	break;
                    	case SDLK_RIGHT:
                    		this->player->move(RIGHT);
                    	break;
                    	case SDLK_LEFT:
                    		this->player->move(LEFT);
                    	break;
                    	case SDLK_ESCAPE:
                        	this->running = false;
                        break;
                        default:;
                    }
			}
		}

		insert_enemies();

	    player_colision();
	    center_colision();
		
		//Logic

		this->player->update(delta.get_ticks());
		this->stream1->update(delta.get_ticks());
		this->stream2->update(delta.get_ticks());
		this->stream3->update(delta.get_ticks());
		this->stream4->update(delta.get_ticks());

		this->delta.start();
		//Render
		SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00)); //paints everything with black
		this->center->draw();
		this->player->draw();

		this->stream1->draw();
		this->stream2->draw();
		this->stream3->draw();
		this->stream4->draw();

		SDL_Flip(screen);
		
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}

void Game::insert_enemies(){
	this->delayticks+=delta.get_ticks();
	if (this->delayticks>1000){
		this->delayticks-=1000;
		int random_stream = rand() % 4 + 1;
		switch(random_stream){
	       	case 1:
	    		this->stream1->insert_enemy();
	    	break;

	    	case 2:
	    		this->stream2->insert_enemy();
	    	break;

	    	case 3:
	    		this->stream3->insert_enemy();
	    	break;

	    	case 4:
	    		this->stream4->insert_enemy();
	    	break;
		}
	}

}

void Game::player_colision(){
	//player colision stream1
		if (!stream1->enemies.empty()){
			if(handleColision(this->player->box,stream1->enemies.at(0)->box)){
				stream1->enemies.erase(stream1->enemies.begin());
			}		
		}
		//player colision stream2
		if (!stream2->enemies.empty()){
			if(handleColision(this->player->box,stream2->enemies.at(0)->box)){
				stream2->enemies.erase(stream2->enemies.begin());
			}		
		}
		//player colision stream3
		if (!stream3->enemies.empty()){
			if(handleColision(this->player->box,stream3->enemies.at(0)->box)){
				stream3->enemies.erase(stream3->enemies.begin());
			}		
		}
		//player colision stream4
		if (!stream4->enemies.empty()){
			if(handleColision(this->player->box,stream4->enemies.at(0)->box)){
				stream4->enemies.erase(stream4->enemies.begin());
			}		
		}
}	

void Game::center_colision(){
	//center colision stream1
		if (!stream1->enemies.empty()){
			if(handleColision(this->center->box,stream1->enemies.at(0)->box)){
				stream1->enemies.erase(stream1->enemies.begin());
			}		
		}
		//center colision stream2
		if (!stream2->enemies.empty()){
			if(handleColision(this->center->box,stream2->enemies.at(0)->box)){
				stream2->enemies.erase(stream2->enemies.begin());
			}			
		}
		//center colision stream3
		if (!stream3->enemies.empty()){
			if(handleColision(this->center->box,stream3->enemies.at(0)->box)){
				stream3->enemies.erase(stream3->enemies.begin());
			}				
		}
		//center colision stream4
		if (!stream4->enemies.empty()){
			if(handleColision(this->center->box,stream4->enemies.at(0)->box)){
				stream4->enemies.erase(stream4->enemies.begin());
			}			
		}
}	