#include "gui.h"
#include "game.h"
#include "video.h"

int main(){
	
	Video * video=new Video();
	Game * game;
	Gui * menu;
	int state;
	state=MENU;
	menu = new Gui(video->getScreen(),&state);
	game = new Game(video->getScreen(), &state);
	
	do{		
		if(state==MENU || state==GAMEOVER ){
			menu->run();
		}
		if (state==INGAME){
			game->run();
		}
	} while (state!=EXIT);

	video->~Video();

	return 0;
}