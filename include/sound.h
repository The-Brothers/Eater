#ifndef SOUND_H
#define SOUND_H

#include <SDL/SDL.h>
#include "SDL/SDL_mixer.h"
class Sound{

	Mix_Chunk *music;

public:
	Sound();
	~Sound();
	void loadSound(const char* sound);
	void playSound(int repeat);
};

#endif