#include "rushlib.h"
#include <stdio.h>
int *arr;

int r_pow(int b, int e)
{
    if(e == 1)
        return b;
    r_pow(b * b, e - 1);
}

int initialize_grid(char **grid, int side_size)
{   
    int i;

    i = 0;
    grid = (char**) malloc((side_size + 2) * sizeof(char*));
    while(i < side_size + 2)
        grid[i++] = malloc((side_size + 2) * sizeof(char));
    if(grid == NULL)
        return (3);
    return (0);
}


int init_and_check_if_return(char **grid, int side_size, char *str, int *arr)
{
    int r;

    r = 0;
    r += initialize_grid(grid, side_size);
    r += str_to_arr(str, arr, 0);
    r += input_check(arr);
    r += input_check(arr);
   

    return (r);
}
int main(int argc, char **argv)
{
    char **grid;
    //char *str;
    int side_size = calc_side_size(arr);
    
    if(argc != 2)
        return 1;

    //str = argv[1];

    if(init_and_check_if_return(grid, side_size, argv[1], arr) != 0)
        return init_and_check_if_return(grid, side_size, argv[1], arr);

    int i = 0;

    while(i < side_size + 2)
    {
        printf("%s", grid[i]);
        i++;
    }
    return 0;
}