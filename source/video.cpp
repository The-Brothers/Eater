#include "video.h"

using namespace std;

Video::Video(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	#ifdef PS3
		IMG_Init(IMG_INIT_PNG);
	#endif
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;
	#ifdef PS3
		this->screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, SCREEN_BPP , SDL_DOUBLEBUF|SDL_FULLSCREEN);
	#else
		this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	#endif
	SDL_WM_SetCaption("Eater",NULL);
	TTF_Init();

	
}

Video::~Video(){
	SDL_FreeSurface(this->screen);
	TTF_Quit();
	#ifdef PS3
		IMG_Quit();
	#endif
	SDL_Quit();
}


SDL_Surface* Video::getScreen(){
	return this->screen;
}