/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include "animation.h"
//#include <SDL_image.h>
#include <stdio.h>
#include <string.h>
#include "graphics.h"
//#include <cmath>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
//Screen dimension constants
void writetofile(char grid[10][10])
{
	FILE *fp = fopen("output.txt","w");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			putc(grid[i][j], fp);
		}
		putc('\n', fp);
	}
	fclose(fp);
}
int main()
{
	//reset(grid);
	reset(new_grid);
	input();
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
			for (int i = 0; i < steps; i++)
			{

				/*if (e.type == SDL_QUIT)
				{
					quit = 1;

					break;
				}*/

				SDL_DestroyRenderer(gRenderer);
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
				if (i % 2 == 0)
				{
					reset(new_grid);

					execute_game(grid, new_grid);
					draw_grid(grid, gRenderer);
					writetofile(grid);
					//draw_grid(grid, gRenderer);
				}
				else
				{
					reset(grid);
					display_grid(new_grid);
					execute_game(new_grid, grid);
					draw_grid(new_grid, gRenderer);
					writetofile(new_grid);
				}

				//grid[0][i]='*';

				SDL_RenderPresent(gRenderer);
				delay(1);
			}
			/*while (quit == 0 && e.type != SDL_QUIT)
			{
				SDL_RenderPresent(gRenderer);
			}*/
		}
	}


printf("Final state of world written to ouput.txt file.\n");
}
