#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

using namespace std;

//Flip flags
#define  FLIP_VERTICAL  1
#define  FLIP_HORIZONTAL  2

SDL_Surface * loadImage(const char* img);

bool handleColision(SDL_Rect box1, SDL_Rect box2);

Uint32 get_pixel32( SDL_Surface *surface, int x, int y );

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );

SDL_Surface *flipImage( SDL_Surface *surface, int flags );

#endif