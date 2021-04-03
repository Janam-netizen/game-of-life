#include "unity.h"
#include "animation.h"

char grid[10][10];

void test_update_state()
{//Test on corner cells
  char s1=update_state(grid, 0, 0);
  char s2=update_state(grid, 9, 9);
  char s3=update_state(grid, 9, 0);
  char s4=update_state(grid, 0, 9);
  TEST_ASSERT(s1==' ');
  TEST_ASSERT(s2==' ');
  TEST_ASSERT(s3==' ');
  TEST_ASSERT(s4==' ');

//Test on edge cells



//Test on cells within the frame

;
}


void test_validate_world(){
  //test for repeated assignments of cell
   struct world w1 = {2,2 ,3,{{0,0}{0,1}{0,0}}};
   //test for negative dimensions  and out of range dimensions
   struct world w2 

   //test for out of scope assignments of  cell





int t1=validate_world();
int t2=;
int t3=;

int t4=;




}
void setUp()
{
  //reset(grid);
  for (int i = 0; i < 10; i++)
  {

    for (int j = 0; j < 10; j++)
    {
      grid[i][j] = ' ';
    }
  }

  set(grid, 2, 0);
  set(grid, 3, 1);
  set(grid, 3, 2);
  set(grid, 2, 2);
  set(grid, 1, 2);
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
  RUN_TEST(test_update_state);

  return UNITY_END();
}
