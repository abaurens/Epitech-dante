##
## Makefile for perfect in /home/baurens/Work/Tek1/Projects/IA/dante/generator/perfect_dir/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Apr 20 18:31:30 2017 Arthur Baurens
## Last update Thu Apr 20 18:59:54 2017 Arthur Baurens
##

CC		=	gcc

NAME		=	imperfect

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	cp $(NAME) ../

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY:	all clean fclean re
