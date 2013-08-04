#include "game.h"
#include "video.h"

int main(){
	
	Video * video=new Video();
	Game * game;

	game = new Game(video->getScreen());
	game->run();

	video->~Video();

	return 0;
}