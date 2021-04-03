#include <stdio.h>
//#include "graphics.h"
//#include <SDL2/SDL.h>
#include "animation.h"
#include <stdlib.h>
//char grid[10][10];
//struct world w;
int steps;

void input()
{
    printf("Enter no.of rows(0-9):");

    scanf("%i", &w.row);
    printf("\n");
    printf("Enter no. of columns(0-9)");
    scanf("%i", &w.col);
    printf("\n");
    printf("Enter population:");
    scanf("%i", &w.population);
    printf("\n");
    printf("Enter steps:");
    scanf("%i",&steps);
    printf("\n");
    printf("Please enter  coordintes of the form x,y\n");
    reset(grid);

    for (int i = 0; i < w.population; i++)
    {
        //SDL_DestroyRenderer(gRenderer);
        //gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        //draw_grid(grid, gRenderer);
        //SDL_RenderPresent(gRenderer);
        display_grid(grid);
        printf("Enter coordinate:");
        scanf("%i,%i", &(w.locations[i][0]), &(w.locations[i][1]));
        set(grid, w.locations[i][0], w.locations[i][1]);
        system("clear");
    }
}
/*int main()
{//init();
//loadMedia();


    input();
}*/
