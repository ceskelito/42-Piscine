#include "rushlib.h"

void full_col(char** grid, int col)
{
    int row;
    row = 0;
    while(row < 4)
    {
        grid[++row][col] = row;
    }
}

void full_row(char** grid, int row)
{
    int col;
    col = 0;
    while(col < 4)
    {
        grid[row][++col] = col;
    }
}

void fill_1(char **grid, int *input)
{
    int row;
    int col;
    row = 0;
    while(row < 4)
    {
        col=0;
        while(col <  4)
        {
            if(input[row][col]==4)
                full_col(grid, col);
            col++;
        }
    }
    col = 0;
    while(col < 4)
    {
        row=0;
        while(row <  4)
        {
            if(input[col][row]==4)
                full_row(grid, row);
            row++;
        }
    }
}

fill_2(char **grid, int *input)
{
    
}

int main()
{
    int input[4][4] = {{4,3,2,1},{1,2,2,2},{4,3,2,1},{1,2,2,2}};
    char **grid;
    int grid_size = 4 * 4;
    int i = 0;

    grid = (char**) (grid_size * sizeof(char*) + 1);
    while(i < grid_size)
    {
        grid[i] = (char*) malloc(grid_size/grid_size * sizeof(char) + 1);
    }

    return 0;


}