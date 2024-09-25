SRCS = srcs/*.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

libft.a : $(SRCS) includes/ft.h 
	$(CC) $(CFLAGS) $(SRCS) -I includes && make move && ar -rcs libft.a $(OBJ) 

move :
	mv *.o srcs/

clean :
	rm -f srcs/*.o includes/*.gch

all :
	make libft.a

fclean :
	make clean && rm -f *.bin
re :
	make fclean && make all
