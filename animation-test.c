#include "unity.h"
#include "animation.h"

char input_grid[10][10];
char output_grid[10][10];
struct world w;


void check(char grid_a[10][10], char grid_b[10][10])
{//display_grid(grid_a);
//display_grid(grid_b);
  for (int i = 0; i < 10; i++)
  {

    for (int j = 0; j < 10; j++)
    {
      TEST_ASSERT(grid_a[i][j] == grid_b[i][j]);
    }
  }
}
void test_execute_game()
{
  char e1[10][10];
  char e2[10][10];
  char e3[10][10];
  char e4[10][10];
  reset(input_grid);
  reset(output_grid);
  reset(e1); //expected step 1
  reset(e2); //expected step 2
  reset(e3); //expected step 3
  reset(e4); //expected step 4
  //Initialising input world...
  set(input_grid, 2, 0);
  set(input_grid, 3, 1);
  set(input_grid, 3, 2);
  set(input_grid, 2, 2);
  set(input_grid, 1, 2);
  set(e1, 1, 1);
  set(e1, 2, 2);
  set(e1, 2, 3);
  set(e1, 3, 2);
  set(e1, 3, 1);
  set(e2, 1, 2);
  set(e2, 2, 3);
  set(e2, 3, 3);
  set(e2, 3, 2);
  set(e2, 3, 1);
  set(e3, 2, 1);
  set(e3, 3, 2);
  set(e3, 3, 3);
  set(e3, 4, 2);
  set(e3, 2, 3);
  set(e4, 3, 1);
  set(e4, 4, 2);
  set(e4, 4, 3);
  set(e4, 3, 3);
  set(e4, 2, 3);
  execute_game(input_grid, output_grid);
  check(output_grid, e1);
  display_grid(output_grid);
  reset(output_grid);

  execute_game(e1, output_grid);
  check(output_grid, e2);
  display_grid(output_grid);
  reset(output_grid);
  execute_game(e2, output_grid);
  check(output_grid, e3);
  display_grid(output_grid);
  reset(output_grid);
  execute_game(e3, output_grid);
  check(output_grid, e4);
  display_grid(output_grid);
  reset(output_grid);
}
void test_no_of_neighbors()
{ //Test on corner cells
  int s1 = no_of_neighbors(grid, 0, 0);
  int s2 = no_of_neighbors(grid, 9, 9);
  int s3 = no_of_neighbors(grid, 9, 0);
  int s4 = no_of_neighbors(grid, 0, 9);
  TEST_ASSERT(s1 == 3);
  TEST_ASSERT(s2 == 3);
  TEST_ASSERT(s3 == 3);
  TEST_ASSERT(s4 == 3);

  //Test on edge cells

  int s5 = no_of_neighbors(grid, 2, 0);
  int s6 = no_of_neighbors(grid, 0, 2);
  int s7 = no_of_neighbors(grid, 9, 2);
  int s8 = no_of_neighbors(grid, 2, 9);
  TEST_ASSERT(s5 == 5);
  TEST_ASSERT(s6 == 5);
  TEST_ASSERT(s7 == 5);
  TEST_ASSERT(s8 == 5);
  //Test on cells within the frame
  int s9 = no_of_neighbors(grid, 1, 1);
  TEST_ASSERT(s9 == 8);
}

void test_update_state()
{
  reset(grid);
  //Test for underpopulation(no.of neighbors<2)
  //no. of neighbors=0

  char t1 = update_state(grid, 1, 1);
  TEST_ASSERT(t1 == ' ');
  //no. of neighbors=1
  set(grid, 0, 1);

  char t2 = update_state(grid, 1, 1);
  TEST_ASSERT(t2 == ' ');

  //Test for overpopulation(no.of neighbors>3)
  set(grid, 0, 0);
  set(grid, 0, 2);
  set(grid, 2, 2);
  char t3 = update_state(grid, 1, 1);
  TEST_ASSERT(t3 == ' ');
  //Test when the no. of neighbors is 3
  grid[0][2] = ' ';
  char t4 = update_state(grid, 1, 1);
  TEST_ASSERT(t4 == '*');

  //Test when the no. of neighbors is 2
  grid[2][2] = ' ';
  char t5 = update_state(grid, 1, 1);
  //char t6=update_state(grid,1,1)
  grid[1][1] = '*';
  char t6 = update_state(grid, 1, 1);
  TEST_ASSERT(t6 == '*');
}
void setUp()
{
  //reset(grid);
  for (int i = 0; i < 10; i++)
  {

    for (int j = 0; j < 10; j++)
    {
      grid[i][j] = '*';
    }
  }
  w.row = 10;
  w.col = 10;
  
}
void tearDown()
{
  for (int i = 0; i < 10; i++)
  {

    for (int j = 0; j < 10; j++)
    {
      grid[i][j] = ' ';
    }
  }
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_no_of_neighbors);
  RUN_TEST(test_update_state);
  RUN_TEST(test_execute_game);

  return UNITY_END();
}
