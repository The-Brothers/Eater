#ifndef SOUND_H
#define SOUND_H

#include <SDL/SDL.h>
#include "SDL/SDL_mixer.h"
class Sound{

	Mix_Chunk *music;

	// Audio Types
	#define SFX 1
	#define MUSIC 2


public:
	Sound();
	~Sound();
	void loadSound(const char* sound);
	void playSound(int type, int repeat);
	void mute();
	void unMute();
	void setVolume(int type, int volume);
};

#endif