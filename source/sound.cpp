#include "sound.h"

using namespace std;

Sound::Sound(){
	Mix_OpenAudio( 22050,AUDIO_S16SYS,1,640 );
}

Sound::~Sound(){
	Mix_FreeChunk(this->music);
	Mix_CloseAudio();
}

void Sound::loadSound(const char* sound){
	this->music = Mix_LoadWAV(sound);
}

void Sound::playSound(int type, int repeat){
	Mix_PlayChannel(type,this->music, repeat);
}

void Sound::mute(){
	Mix_Volume(-1,0);
}

void Sound::unMute(){
	Mix_Volume(-1,100);
}

void Sound::setVolume(int type, int volume){
	Mix_Volume(type,volume);
}