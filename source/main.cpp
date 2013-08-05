#include "gui.h"
#include "game.h"
#include "video.h"

int main(){
	
	Video * video=new Video();
	Game * game;
	Gui * menu;
	int state;
	state=MENU;
	do{		
		if(state==MENU || state==GAMEOVER ){
			menu = new Gui(video->getScreen(),&state);
			menu->run();
		}
		if (state==INGAME){
			game = new Game(video->getScreen(), &state);
			game->run();
		}
	} while (state!=EXIT);

	video->~Video();

	return 0;
}