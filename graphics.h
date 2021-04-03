

#include <SDL2/SDL.h>
//#include "animation.h"
//#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
//#include <cmath>
#include <unistd.h>
#include <time.h>
int SCREEN_WIDTH ;
int SCREEN_HEIGHT ;



//The window we'll be rendering to


extern SDL_Window *gWindow;

//The window renderer
extern SDL_Renderer *gRenderer;
//Starts up SDL and creates window
int init();

//Loads media
int loadMedia();
