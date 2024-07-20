#include <stdio.h>
#include <stdlib.h>


#define TIPO void
#define NOME  ft_putstr
#define PARAM char *str
#define ARG str
TIPO NOME (PARAM);

int main(int argc, char *argv[])
{	
	if(argc==0){};
	char *str = argv[1];
		NOME(ARG);
	//printf("%s", str);
	
	return 0;}
