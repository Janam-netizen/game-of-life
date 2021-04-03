
// C function showing how to do time delay
#include "animation.h"
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdlib.h>

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
struct world w;
char grid[10][10];
char new_grid[10][10];

void set_grid(struct world w)
{
    for (int i = 0; i < w.population; i++)
    {
        set(grid, w.locations[i][0], w.locations[i][1]);
    }
}
/*struct world
{
    int row;
    int col;
    int population;
    int locations[100][2];

};*/

//w.row=5;
//w.col=5;

int peek(char x)
{

    return x == '*';
}
int left_neighbor(char grid[10][10], int row, int col)
{

    return peek(grid[row][col - 1]);
}
int right_neighbor(char grid[10][10], int row, int col)
{
    return peek(grid[row][col + 1]);
}
int up_neighbor(char grid[10][10], int row, int col)
{

    return peek(grid[row - 1][col]);
}
int down_neighbor(char grid[10][10], int row, int col)
{

    return peek(grid[row + 1][col]);
}
int ul_neighbor(char grid[10][10], int row, int col)
{
    return peek(grid[row - 1][col - 1]);
}

int dr_neighbor(char grid[10][10], int row, int col)
{
    return peek(grid[row + 1][col + 1]);
}

int ur_neighbor(char grid[10][10], int row, int col)
{

    return peek(grid[row - 1][col + 1]);
}
int dl_neighbor(char grid[10][10], int row, int col)
{

    return peek(grid[row + 1][col - 1]);
}
int left_edge(int row, int col)
{
    if (row < w.row - 1 && col == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int right_edge(int row, int col)
{
    if (row < w.row - 1 && col == w.col - 1)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int up_edge(int row, int col)
{
    if (row == 0 && col < w.col - 1)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int down_edge(int row, int col)
{
    if (row == w.row - 1 && col < w.col - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int no_of_neighbors(char grid[10][10], int row, int col)
{

    int no_of_neighbors = 0;
    if (row == 0 && col == 0)
    {

        no_of_neighbors = right_neighbor(grid, row, col) + down_neighbor(grid, row, col) + dr_neighbor(grid, row, col);
    }
    else if (row == 0 && col == w.col - 1)
    {

        no_of_neighbors = left_neighbor(grid, row, col) + down_neighbor(grid, row, col) + dl_neighbor(grid, row, col);
    }
    else if (row == w.row - 1 && col == 0)
    {

        no_of_neighbors = up_neighbor(grid, row, col) + right_neighbor(grid, row, col) + ur_neighbor(grid, row, col);
    }
    else if (row == w.row - 1 && col == w.col - 1)
    {
        no_of_neighbors = up_neighbor(grid, row, col) + ul_neighbor(grid, row, col) + left_neighbor(grid, row, col);
    }
    else if (up_edge(row, col))
    {
        no_of_neighbors = down_neighbor(grid, row, col) + dr_neighbor(grid, row, col) + dl_neighbor(grid, row, col) + left_neighbor(grid, row, col) + right_neighbor(grid, row, col);
    }
    else if (down_edge(row, col))
    {

        no_of_neighbors = up_neighbor(grid, row, col) + ul_neighbor(grid, row, col) + ur_neighbor(grid, row, col) + left_neighbor(grid, row, col) + right_neighbor(grid, row, col);
    }
    else if (left_edge(row, col))
    {

        no_of_neighbors = right_neighbor(grid, row, col) + ur_neighbor(grid, row, col) + dr_neighbor(grid, row, col) + up_neighbor(grid, row, col) + down_neighbor(grid, row, col);
    }

    else if (right_edge(row, col))
    {
        no_of_neighbors = left_neighbor(grid, row, col) + ul_neighbor(grid, row, col) + dl_neighbor(grid, row, col) + up_neighbor(grid, row, col) + down_neighbor(grid, row, col);
    }
    else
    {

        no_of_neighbors = left_neighbor(grid, row, col) + ul_neighbor(grid, row, col) + dl_neighbor(grid, row, col) + up_neighbor(grid, row, col) + down_neighbor(grid, row, col) + right_neighbor(grid, row, col) + ur_neighbor(grid, row, col) + dr_neighbor(grid, row, col);
    }
    return no_of_neighbors;
}
char update_state(char grid[10][10], int row, int col)

{
    int neighbors = no_of_neighbors(grid, row, col);
    if (neighbors < 2 || neighbors > 3)
    {
        return ' ';
    }
    else
    {
        if (neighbors == 3 && grid[row][col] == ' ')
        {
            return '*';
        }

        else
        {

            return grid[row][col];
        }
    }
}
void reset(char grid[10][10])
{
    for (int row = 0; row < 10; row++)
    {

        for (int col = 0; col < 10; col++)
        {
            grid[row][col] = ' ';
        }
    }
}
void execute_game(char og[10][10], char ng[10][10])
{

    reset(ng);
    for (int i = 0; i < w.row; i++)
    {
        for (int j = 0; j < w.col; j++)
        {
            ng[i][j] = update_state(og, i, j);
        }
    }
}

void set(char grid[10][10], int row, int col)
{

    grid[row][col] = '*';
    /*for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            update_state(grid, i, j);
        }
    }*/
}
void display_grid(char grid[10][10])
{printf(" ");
    for (int i = 0; i < w.col; i++)
    {
        printf("%i", i);
    }
    printf("\n");
    for (int i = 0; i < w.row; i++)
    {
        printf("%i", i);
        for (int j = 0; j < w.col; j++)
        {

            printf("%c", grid[i][j]);
        }

        printf("\n");
    }
}

// Driver code to test above function
/*int main()
{
    reset(grid);
    reset(new_grid);
    set(grid, 2, 0);
    set(grid, 3, 1);
    set(grid, 3, 2);
    set(grid, 2, 2);
    set(grid, 1, 2);
    /*system("clear");
    display_grid(grid);

    execute_game(grid, new_grid);
    delay(1);
    system("clear");
    display_grid(new_grid);
    delay(1);
    reset(grid);
    execute_game(new_grid,grid);
    system("clear");
    display_grid(grid);
    delay(1);
    system("clear");
    int i=0;
    while(1)
    {
        system("clear");
        if (i % 2 == 0)
        {
            reset(new_grid);
            display_grid(grid);
            execute_game(grid, new_grid);
        }
        else
        {
            reset(grid);
            display_grid(new_grid);
            execute_game(new_grid,grid);
        }
        delay(1);
        i++;
    }*/

/*for (int i = 0; i < 10; i++)

    {
        // delay of one second
        for (int j = 0; j < 10; j++)
        {
            set(grid, i, j);
            display_grid(grid);

            delay(1);

            //printf("\n");
            system("clear");
        }
    }*/
/*char c = 'r';
        printf("%i", c == '*');
    return 0;
}*/
