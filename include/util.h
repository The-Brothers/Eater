#ifndef UTIL_H
#define UTIL_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

using namespace std;

SDL_Surface * loadImage(const char* img);

bool handleColision(SDL_Rect box1, SDL_Rect box2);

#endif