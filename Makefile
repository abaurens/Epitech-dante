##
## Makefile for perfect in /home/baurens/Work/Tek1/Projects/IA/dante/generator/perfect_dir/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Apr 20 18:31:30 2017 Arthur Baurens
## Last update Fri Apr 28 08:59:31 2017 Arthur Baurens
##

CC		=	gcc

SRC		=	generator

OBJ		=	$(SRC:.c=.o)

all:	./generator/generator
	make -C ./generator/

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
