##
## Makefile for str in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_str/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Fri May 12 15:13:49 2017 Arthur Baurens
## Last update Fri May 12 16:16:32 2017 Arthur Baurens
##

CC	=	gcc

NAME	=	libstr.a

SRC	=	str_len.c	\
		my_strncat.c	\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -ansi -pedantic

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

r:	fclean debug

.PHONY:	all debug clean fclean re r
