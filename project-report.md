# Project Report

#### Project title:Conway game of life

#### Name:Janam Zaveri

#### Student ID: 201391181

## Project Design

A program that depicts a system involving cellular automation graphically, where people(represented as cells in a grid) evolve in accordance to the rules that govern their world. In this program the world would be assumed to be of finite size. 

### Key modules:
-Animation.c- To and implement the system .

-unit_tests.c-To see if functions of Animation.c pass the tests

-Main.c- To render the game to a graphical interface

-Animation.h- Consists of function prototypes of the functions implemented in Animation.c 

## Test plan:

Function: int set(char grid[10][10],int row,int col)
Expected behaviour: Sets cells to the state of being alive at given coordinates.
checked exceptions: returns -1 if the given coordinates  are out of scope

Assertion:Returns an integer value.



Function:int no_of_neighbors(char grid[][],int row,int col)

Expected behaviour: Returns the no. of neighbors of a particulr cell in the grid.

Assertion:Returns the correct number of neighbors

Checked exception:N/A


Function: char update_state(char grid[5][5],int row, int col):

Expected Behaviour: Given the current state of a cell, the function computes the next state based on the number of neighbors.

Checked exception:N/A

Assertion:Returns '*' to indicate that the cell at given coordinate is alive and ' ' to indicate that cell at given location is dead.





## Project Schedule:

| Week  | Task |
| ------------- |:-------------:|
| 6     | Designing header files and function prototypes.      |
|  7      |  Writting unit tests for functions and implementing functions in the corrosponding modules.     |
| 8     |Running unit tests to see if edge cases have  been covered in implementation.|
|9 |Visulaising the game graphically.|
|10|Add ing the functionality of making the world more configutable by user|
|11|Refactoring code  to improve  readablity|
