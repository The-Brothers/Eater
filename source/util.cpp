#include "util.h"

using namespace std;

SDL_Surface * loadImage(const char* img){
	// Deve-se fazer um tratamento para verificar a extensão da imagem
	// Inicializa a imagem a se carregada
	SDL_Surface * loadedImage = NULL;
	
	// Inicializa a imagem otimizada
	SDL_Surface * optimizedImage =  NULL;
	
	// Carrega a imagem
	loadedImage = IMG_Load(img);
		
	// Se a imagem foi carregada
	if(!loadedImage)
	{
		cout << "Erro ao abrir: " << SDL_GetError() << endl;
		return NULL;
	}
	
	// Cria a imagem otimizada
  optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
   
  // Libera a imagem antiga da memória
  SDL_FreeSurface(loadedImage);
    
  return optimizedImage;
}

bool handleColision(SDL_Rect box1, SDL_Rect box2){
	if(!((box1.x>box2.x+box2.w || ((box1.x+box1.w)<box2.x)) || (box1.y>box2.y+box2.h ||(box1.y+box1.h)<box2.y)))
				return true;
	return false;
}

Uint32 get_pixel32( SDL_Surface *surface, int x, int y ){
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel ){
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}


SDL_Surface *flipImage( SDL_Surface *surface, int flags ){
    //Pointer to the soon to be flipped surface
    SDL_Surface *flipped = NULL;

    //If the image is color keyed
    if( surface->flags & SDL_SRCCOLORKEY )
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, 0 );
    else
        flipped = SDL_CreateRGBSurface( SDL_SWSURFACE, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask );
      //If the surface must be locked
    if( SDL_MUSTLOCK( surface ) ){
        //Lock the surface
        SDL_LockSurface( surface );
    }

    //Go through columns
    for( int x = 0, rx = flipped->w - 1; x < flipped->w; x++, rx-- ){
        //Go through rows
        for( int y = 0, ry = flipped->h - 1; y < flipped->h; y++, ry-- ){
            //Get pixel
            Uint32 pixel = get_pixel32( surface, x, y );

            //Copy pixel
            if( ( flags & FLIP_VERTICAL ) && ( flags & FLIP_HORIZONTAL ) ){
                put_pixel32( flipped, rx, ry, pixel );
            }
            else if( flags & FLIP_HORIZONTAL ){
                put_pixel32( flipped, rx, y, pixel );
            }
            else if( flags & FLIP_VERTICAL ){
                put_pixel32( flipped, x, ry, pixel );
            }
        }
    }

    //Unlock surface
    if( SDL_MUSTLOCK( surface ) ){
        SDL_UnlockSurface( surface );
    }

    
    //Return flipped surface
    return flipped;
}

#ifdef PS3
    void debugPrintf(const char* fmt, ...){
      char buffer[0x800];
      va_list arg;
      va_start(arg, fmt);
      vsnprintf(buffer, sizeof(buffer), fmt, arg);
      va_end(arg);
      netSend(SocketFD, buffer, strlen(buffer), 0);
    }

    void debugInit(){
      netInitialize();
      struct sockaddr_in stSockAddr;
      SocketFD = netSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

      memset(&stSockAddr, 0, sizeof stSockAddr);

      stSockAddr.sin_family = AF_INET;
      stSockAddr.sin_port = htons(DEBUG_PORT);
      inet_pton(AF_INET, DEBUG_IP, &stSockAddr.sin_addr);

      netConnect(SocketFD, (struct sockaddr *)&stSockAddr, sizeof stSockAddr);
       
      debugPrintf("network debug module initialized\n") ;
      debugPrintf("ready to have a lot of fun\n\n") ;
    }

    void debugStop(){
      netDeinitialize();
    }

#endif