##
## Makefile for depth in /home/baurens/Work/Tek1/Projects/IA/dante/depth/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sat May 13 22:40:04 2017 Arthur Baurens
## Last update Sat May 13 23:01:10 2017 Arthur Baurens
##

CC	=	gcc

NAME	=	depth

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

LIBS	=	-L../lib/ -lmaze -llst -lstr

CFLAGS	=	-I./include -I../include -W -Wall -Wextra -ansi -pedantic

DEP	=	../lib/libmaze.a

DEP_DIR	=	../lib/lib_maze/


$(NAME):	$(DEP) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

$(DEP):
	make -C $(DEP_DIR)


all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	$(RM) $(OBJ)

clean_dependencies: clean
	make -C $(DEP_DIR) clean_dependencies

fclean:	clean
	$(RM) $(NAME)

fclean_dependencies: fclean
	make -C $(DEP_DIR) fclean_dependencies

rebuild_dependencies:
	make -C $(DEP_DIR) re_dependencies

re_dependencies: rebuild_dependencies re

re:	fclean all

r:	fclean debug

.PHONY:	all debug clean clean_dependencies fclean fclean_dependencies re re_dependencies r
