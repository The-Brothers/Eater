#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

using namespace std;


#define MENU 1
#define INGAME 2
#define INGAMEMENU 3
#define GAMEOVER 4
#define EXIT 5

#define FPS 30

//Flip flags
#define  FLIP_VERTICAL  1
#define  FLIP_HORIZONTAL  2

SDL_Surface * loadImage(const char* img);

bool handleColision(SDL_Rect box1, SDL_Rect box2);

Uint32 get_pixel32( SDL_Surface *surface, int x, int y );

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );

SDL_Surface *flipImage( SDL_Surface *surface, int flags );

#ifdef PS3
	#include <stdarg.h>
	#include <stdlib.h>
	#include <string.h>

	#include <net/net.h>
	#include <netinet/in.h>

	static int SocketFD;
	#define DEBUG_IP "192.168.43.113"
	#define DEBUG_PORT 1314

	void debugPrintf(const char* fmt, ...);

	void debugInit();

	void debugStop();

#endif

#endif