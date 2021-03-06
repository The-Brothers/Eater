#include "game.h"


#ifdef PS3
	#include <sysutil/msg.h>
	#include <sysutil/sysutil.h>
#endif

using namespace std;

Game::Game(SDL_Surface * screen, int *state){
	srand (time(NULL));
	#ifdef PS3
		debugInit();
	#endif

	this->screen=screen;
	//Game stuff
	this->delayticks=0;

	this->currentStatus=state;
	this->center = new Center();
	this->player = new Player();

	this->stream1 = new Stream(1);
	this->stream2 = new Stream(2);
	this->stream3 = new Stream(3);
	this->stream4 = new Stream(4);

	this->healthbar = new HealthBar(10);

	this->gamemusic= new Sound();
	#ifdef PS3
		this->gamemusic->loadSound("/dev_hdd0/game/EATER0001/data/sound/get_lucky.ogg");
	#else
		this->gamemusic->loadSound("data/sound/get_lucky.ogg");
	#endif

	//Background
	#ifdef PS3
		this->background = loadImage("/dev_hdd0/game/EATER0001/data/background.png");
	#else
		this->background = loadImage("data/background.png");
	#endif
}

Game::~Game(){
}

void Game::init(){
	this->scoreCount = 0;
	char temp[5];
	sprintf(temp,"%d",this->scoreCount);
	this->score = new Text(string(temp),32,180,0);
	this->score->setColor(WHITE);	
	this->healthbar->health_points=10;
}

void Game::run(){
	this->init();
	gamemusic->playSound(MUSIC,1);
	this->delta.start();
	this->running = true;
	while(this->running && *this->currentStatus!=GAMEOVER){
		this->start = SDL_GetTicks();
		
		#ifdef PS3
			ioPadGetInfo (&this->padinfo);
		    for(int i = 0; i < 2; i++) {
		        if(this->padinfo.status[i]) {
		            ioPadGetData (i, &paddata);
		            if(paddata.BTN_START){
		            	this->running = false;
						*this->currentStatus=EXIT;
		            }
		            if(paddata.BTN_UP)
		            	this->player->move(UP);
		            
		            if(paddata.BTN_DOWN)
		            	this->player->move(DOWN);
		            
		            if(paddata.BTN_RIGHT)
		            	this->player->move(RIGHT);
		            
		            if(paddata.BTN_LEFT) 
		            	this->player->move(LEFT);
		            
		            if(paddata.BTN_L1)
	            		this->stream1->insertEnemy();
	            	

	            	if(paddata.BTN_L2)
	            		this->stream2->insertEnemy();
	            	

	            	if(paddata.BTN_R1)
	            		this->stream3->insertEnemy();
	            	

	            	if(paddata.BTN_R2)
	            		this->stream4->insertEnemy();
	            	
		           
		        }
		    }
    	#else
			//Events
			while(SDL_PollEvent(&this->events)){
				switch(this->events.type){
					case SDL_QUIT:
						this->running = false;
						*this->currentStatus=EXIT;
					break;

					case SDL_KEYDOWN:
	                    switch (events.key.keysym.sym) {                    	
	                    	case SDLK_1:
	                    		this->stream1->insertEnemy();
	                    	break;

	                    	case SDLK_2:
	                    		this->stream2->insertEnemy();
	                    	break;

	                    	case SDLK_3:
	                    		this->stream3->insertEnemy();
	                    	break;

	                    	case SDLK_4:
	                    		this->stream4->insertEnemy();
	                    	break;

	                    	case SDLK_m:
	                    		gamemusic->mute();
	                    	break;

	                    	case SDLK_u:
	                    		gamemusic->unMute();
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
	                        	*this->currentStatus=MENU;
	                        break;

	                        default:;
	                    }
	                break;
				}
			}
		#endif
		insertEnemies();
	    playerColision();
	    centerColision();

		if(this->healthbar->health_points==0)
			*this->currentStatus=GAMEOVER;

		//Logic
	    this->score->update();
		this->player->update(delta.getTicks());
		this->stream1->update(delta.getTicks());
		this->stream2->update(delta.getTicks());
		this->stream3->update(delta.getTicks());
		this->stream4->update(delta.getTicks());
		this->healthbar->update(delta.getTicks());

		this->delta.start();

		//Render
		SDL_BlitSurface(this->background,NULL,SDL_GetVideoSurface(),NULL);
		this->center->draw();
		this->player->draw();

		this->stream1->draw();
		this->stream2->draw();
		this->stream3->draw();
		this->stream4->draw();

		this->score->draw();
		this->healthbar->draw();

		SDL_Flip(screen);
		
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}

void Game::insertEnemies(){
	this->delayticks+=delta.getTicks();
	if (this->delayticks>350){
		this->delayticks-=350;
		int random_stream = rand() % 4 + 1;
		switch(random_stream){
	       	case 1:
	    		this->stream1->insertEnemy();
	    	break;

	    	case 2:
	    		this->stream2->insertEnemy();
	    	break;

	    	case 3:
	    		this->stream3->insertEnemy();
	    	break;

	    	case 4:
	    		this->stream4->insertEnemy();
	    	break;
		}
	}
}

void Game::playerColision(){
	//player colision stream1
		if (!stream1->enemies.empty()){
			if(handleColision(this->player->box,stream1->enemies.at(0)->box)){
				stream1->enemies.erase(stream1->enemies.begin());
			
				this->scoreCount++;
				char temp[5];
				sprintf(temp,"%d",this->scoreCount);
				this->score->setText(string(temp));
			}		
		}
		//player colision stream2
		if (!stream2->enemies.empty()){
			if(handleColision(this->player->box,stream2->enemies.at(0)->box)){
				stream2->enemies.erase(stream2->enemies.begin());
			
				this->scoreCount++;
				char temp[5];
				sprintf(temp,"%d",this->scoreCount);
				this->score->setText(string(temp));
			}		
		}
		//player colision stream3
		if (!stream3->enemies.empty()){
			if(handleColision(this->player->box,stream3->enemies.at(0)->box)){
				stream3->enemies.erase(stream3->enemies.begin());
			
				this->scoreCount++;
				char temp[5];
				sprintf(temp,"%d",this->scoreCount);
				this->score->setText(string(temp));
			}		
		}
		//player colision stream4
		if (!stream4->enemies.empty()){
			if(handleColision(this->player->box,stream4->enemies.at(0)->box)){
				stream4->enemies.erase(stream4->enemies.begin());
			
				this->scoreCount++;
				char temp[5];
				sprintf(temp,"%d",this->scoreCount);
				this->score->setText(string(temp));
			}		
		}
}	

void Game::centerColision(){
	//center colision stream1
		if (!stream1->enemies.empty()){
			if(handleColision(this->center->box,stream1->enemies.at(0)->box)){
				stream1->enemies.erase(stream1->enemies.begin());
				this->healthbar->removeHp(1);
				this->center->hurt->playSound(SFX,0);
			}		
		}
		//center colision stream2
		if (!stream2->enemies.empty()){
			if(handleColision(this->center->box,stream2->enemies.at(0)->box)){
				stream2->enemies.erase(stream2->enemies.begin());
				this->healthbar->removeHp(1);
				this->center->hurt->playSound(SFX,0);
			}			
		}
		//center colision stream3
		if (!stream3->enemies.empty()){
			if(handleColision(this->center->box,stream3->enemies.at(0)->box)){
				stream3->enemies.erase(stream3->enemies.begin());
				this->healthbar->removeHp(1);
				this->center->hurt->playSound(SFX,0);
			}				
		}
		//center colision stream4
		if (!stream4->enemies.empty()){
			if(handleColision(this->center->box,stream4->enemies.at(0)->box)){
				stream4->enemies.erase(stream4->enemies.begin());
				this->healthbar->removeHp(1);
				this->center->hurt->playSound(SFX,0);
			}			
		}
}	
