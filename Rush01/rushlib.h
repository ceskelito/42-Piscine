#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int r_atoi(char str);
int is_sqr(int s);
int calc_side_size(int *arr);
int str_to_arr(char *str, int *arr, int phase);
void input_fill(int *arr, char **grid, int side_size);
int input_check(int *arr);
int r_pow(int b, int e);