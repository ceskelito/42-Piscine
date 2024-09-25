#include <stdlib.h>
#include <stdio.h>

int wcount(char *str, char *charset);
	char **ft_split(char *str, char *charset);

int main(int ac, char **av)
{
	ac--; av++;

	char **spl = malloc(sizeof(char*) * 9);

	for(int j=0; j<9; j++)
			spl[j] = malloc(sizeof(char) * 9);

	spl = ft_split(av[0], av[1]);
int i = 0;

	while(i < wcount(av[0], av[1]))
	{
			printf("%s", spl[i]);
			printf("\n");
			i++;
	}

return 0;}
