#include "rushlib.h"

int side_size = 4;

int r_atoi(char str)
{
    int n=0;

    if(str >= '0' && (str <= '9'))
        n = ((int) str - '0');
    
    return (n);     
}
int str_to_arr(char *str, int *arr, int phase)
{
    int i;
    int digits;

    i = 0;
    arr = (int *) malloc(digits * sizeof(int));
    digits = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= '1' && (str[i] <= '9')) && (str[i-1] == ' ' || (str[i+1] == ' ')))
        { 
                if(phase == 0)
                    digits++;
                else
                    arr[i] = r_atoi(str[i]);
        }  
        else if(!(str[i] == ' ') && (str[i-1] >= '1' && (str[i-1] <= '9')))
            return (4);
        i++;
    }
    if(phase == 0)
        str_to_arr(str, arr, ++phase);
    return (0);
}

int calc_side_size(int *arr)
{
    int s = sizeof(arr) / sizeof(int);
    return s;
}
/* int is_sqr(int s)
{
    int i;
    int j;
    int *e;
    
    i = 2;
    while (i <= s)
    {
        e[i] = 0;
        while (s % i == 0 && (s > 1))
        {
            s /= i;
            e[i]++;
        }
        i++;
    }
    j = 2;
    while(j <= i)
        if(e[j++] % 2 != 0)
            return (1);
    return (0);
} */
int input_check(int *arr)
{
    int i;
    int s = calc_side_size(arr);

    if(sizeof(arr) % 4 != 0)
        return (1);
    i = 0;
    while(i < s)
        if (arr[i] > s)
            return (1);
    return (0);
}
void input_fill(int *arr, char **grid, int side_size)
{
    int i;
    int j;
    int arr_lenght = calc_side_size(arr);
    int row;
    int col;

    j = side_size;
    while(i < arr_lenght)
    {
        if(i < arr_lenght / 2)
        {
            if((i / side_size) % 2 == 0)
                row = 0;
            else
                row = side_size + 1;
            col = (j % side_size) + 1;
        }
        else
        {
            if((i / side_size) % 2 == 0)
                col = 0;
            else
                col = side_size + 1;
            row = (j % side_size) + 1;
        }
        grid[row][col] = arr[i];
        i++;
        j++;
    }
}