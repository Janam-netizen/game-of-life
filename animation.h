


void delay(int number_of_seconds);
#define MaxRow 10 // The number of rows in the frame buffer
#define MaxCol 10
extern char grid[MaxRow][MaxCol];
extern char new_grid[MaxRow][MaxCol];
struct world
{
    int row;
    int col;
    int population;
    int locations[100][2];

}; 

extern struct world w;

extern int steps;

int peek(char x);

int left_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int right_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int up_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int down_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int ul_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int dr_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int ur_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int dl_neighbor(char grid[MaxRow][MaxCol], int row, int col);

int left_edge(int row, int col);

int right_edge(int row, int col);

int up_edge(int row, int col);

int down_edge(int row, int col);
int no_of_neighbors(char grid[10][10],int row,int col);
char update_state(char grid[MaxRow][MaxCol], int row, int col);

void reset(char grid[MaxCol][MaxCol]);

void execute_game(char og[MaxRow][MaxCol], char ng[MaxCol][MaxCol]);

void set(char grid[MaxRow][MaxCol], int row, int col);

void display_grid(char grid[MaxRow][MaxCol]);

