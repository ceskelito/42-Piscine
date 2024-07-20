#include "rushlib.h"

int grid_size = 4;

int r_atoi(char *str)
{
    int n=0;

    if(*str >= '0' && (*str <= '9'))
        n = ((int) *str - '0');
    
    return (n);     
}
bool input_control( char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        if(!(str[i] >= '1' && (str[i] <= '9') && (str[i-1] == ' ' || (str[i+1] == ' '))))
            return (false);
        i++;
    }
    return (true);
}
int **setcolrow( char *str)
{
    int row;
    int col;
    int **colrow;
    row = 0;
    col = 0;

    while(*str)
    {
        colrow[row][col]=r_atoi(str++);

        if(++col > grid_size - 1)
        {
            col = 0;
            row++;
        }
    }
    return (colrow);
}