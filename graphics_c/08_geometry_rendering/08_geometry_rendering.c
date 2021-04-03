/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
//#include <cmath>
#include <unistd.h>
#include<time.h>
//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 900;
char grid[5][5];
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

//SDL_Surface *square_surface = SDL_LoadBMP("images/square.bmp");
//SDL_Surface *white_surface = SDL_LoadBMP("images/circle.bmp");

//Starts up SDL and creates window
int init();

//Loads media
int loadMedia();

//Frees media and shuts down SDL
void reset();

//Loads individual image as texture
SDL_Texture *loadTexture(char *path);

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

int init()
{
	//Initialization flag
	int success = 1;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = 0;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = 0;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = 0;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				/*int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = 0;
				}*/
			}
		}
	}

	return success;
}

int loadMedia()
{
	//Loading success flag
	int success = 1;

	//Nothing to load
	return success;
}

void restart()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	//IMG_Quit();
	SDL_Quit();
}

/*SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}*/
void setup()
{
	set(grid, 2, 0);
	set(grid, 3, 1);
	set(grid, 3, 2);
	set(grid, 2, 2);
	set(grid, 1, 2);
	/*render_grid(grid);
	sleep(1);
	set(grid, 2, 0);
	set(grid, 3, 1);
	set(grid, 3, 2);
	set(grid, 2, 2);
	set(grid, 1, 2);
	render_grid(grid);
	sleep(1);

	return 0;*/
}
void draw_grid(char grid[5][5], SDL_Renderer *renderer)
{
	SDL_Rect rectangle;

	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 20;
	rectangle.h = 20;
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			rectangle.x = 50 * i;
			rectangle.y = 50 * j;

			//SDL_DestroyRenderer(gRenderer);
			//SDL_DestroyRenderer(gRenderer);
			//gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (grid[i][j] == '*')
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				//SDL_Rect rectangle;

				SDL_RenderFillRect(renderer, &rectangle);
			}
			//SDL_RenderDrawRect(gRenderer, &rectangle)
			//SDL_RenderFillRect(gRenderer, &rectangle);

			//	SDL_DestroyRenderer(gRenderer);
			//	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

			//SDL_RenderClear(gRenderer);
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				//SDL_Rect rectangle;

				SDL_RenderFillRect(renderer, &rectangle);
			}

			//SDL_Texture* square_texture=SDL_CreateTextureFromSurface(gRenderer,white_surface);
			//SDL_RenderPresent(gRenderer);
		}
	}
}
int main()
{
	//setup();
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			int quit = 0;

			//Event handler
			SDL_Event e;

			//While application is running
			for (int i = 0; i < 5; i++)
			{
			

					if (e.type == SDL_QUIT)
					{
						quit = 1;

						break;
					}
				
		
				grid[0][i]='*';

				SDL_DestroyRenderer(gRenderer);
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
				draw_grid(grid, gRenderer);
				SDL_RenderPresent(gRenderer);
				delay(1);
			}
			/*while (quit == 0 && e.type != SDL_QUIT)
			{
				SDL_RenderPresent(gRenderer);
			}*/
		}
	}
}
void set(char grid[5][5], int row, int col)
{

	grid[row][col] = '*';
	/*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            update_state(grid, i, j);
        }
    }*/
}
