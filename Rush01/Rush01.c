#include "rushlib.h"



       
        /* if(col > grid_size || (row > grid_size))
            return (false); */
       /* grid[row][col] = str[i]; 
        else
            return (false);
        if(++col > grid_size - 1)
        {
            col = 0;
            row++;
        } */


int main(int argc, char **argv)
{
    char **grid;
    char *str;
    int **colrow;
    int grid_size = 4;

    if(argc != 2)
        return 1;

    grid = (char**) malloc (grid_size * sizeof(int));
    if(grid == NULL)
        return 3;

    int i = 0;
    int j =0;
    while (i < grid_size) 
    {
        grid[i] = (int**) malloc (4 * sizeof(int));
    
    }
    i = 0;
    while(i < 4)
    {
        while(j < 4)
        {
            grid[i][j] = 
        }
    }
    /* olrow = (int**) malloc (4); */
    if (colrow == NULL)
        return 3;

    str = argv[1];
    /* if(!(input_control(str)))
        return 2; */

   // colrow
   
   //grid[][] = setcolrow(str);
    

    while(*str)
    {
        write(1,str++ ,1);
    }


        return 0;

}