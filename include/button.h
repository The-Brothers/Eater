#ifndef BUTTON_H
#define BUTTON_H

#include "SDL/SDL.h"
#include "util.h"


using namespace std;

class Button{
	
	SDL_Rect box;

	SDL_Surface * image;

public:
	Button(const char* img, int _x, int _y);
	~Button();

	void draw();
	void update();

	bool isClicked(int x, int y);

};

#endif
