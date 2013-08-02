#include "sound.h"

#include <iostream>
using namespace std;

Sound::Sound(){
	Mix_OpenAudio( 22050,AUDIO_S16SYS,2,640 );
}

Sound::~Sound(){
	Mix_FreeChunk(this->music);
	Mix_CloseAudio();
}

void Sound::loadSound(const char* sound){
	this->music = Mix_LoadWAV(sound);
}

void Sound::playSound(int repeat){
	Mix_PlayChannel(-1,this->music, repeat);
}