#include "util.h"

using namespace std;

SDL_Surface * loadImage(const char* img){
	// Deve-se fazer um tratamento para verificar a extensão da imagem
	// Inicializa a imagem a se carregada
	SDL_Surface * loadedImage = NULL;
	
	// Inicializa a imagem otimizada
	SDL_Surface * optimizedImage =  NULL;
	
	// Carrega a imagem
	//cout << "Abrindo: " << img.c_str() << endl;
	loadedImage = IMG_Load(img);
	//loadedImage = SDL_LoadBMP(img.c_str());
	
	// Se a imagem foi carregada
	if(!loadedImage)
	{
		cout << "Erro ao abrir: " << SDL_GetError() << endl;
		return NULL;
	}
	//cout << "Aberta com sucesso!" << endl;
	// Cria a imagem otimizada
    optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
    
    // Libera a imagem antiga da memória
    SDL_FreeSurface(loadedImage);
    
    // Fazer o colorKey
    //Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0x00,0xff,0xfc);
    //Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0xff,0x00,0xff);
    //SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);

    return optimizedImage;
}


bool handleColision(SDL_Rect box1, SDL_Rect box2){
	if(!((box1.x>box2.x+box2.w || ((box1.x+box1.w)<box2.x)) || (box1.y>box2.y+box2.h ||(box1.y+box1.h)<box2.y)))
				return true;
	return false;
}