##
## Makefile for maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Fri May 12 16:17:41 2017 Arthur Baurens
## Last update Sat May 13 22:52:18 2017 Arthur Baurens
##

CC	=	gcc

NAME	=	libmaze.a

SRC	=	files.c		\
		maze.c		\
		graph.c		\
		nodes.c		\
		vec.c

DEP	=	../liblst.a

DEP_DIR	=	../lib_list/

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -I../../include -W -Wall -Wextra -g#-ansi -pedantic

$(NAME):	$(DEP) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

$(DEP):
	make -C $(DEP_DIR)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(dep) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

clean:
	$(RM) $(OBJ)

clean_dependencies: clean
	make -C $(DEP_DIR) clean_dependencies

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

fclean_dependencies: fclean
	make -C $(DEP_DIR) fclean_dependencies

re:	fclean all

rebuild_dependencies:
	make -C $(DEP_DIR) re_dependencies

re_dependencies: rebuild_dependencies re

r:	fclean debug

.PHONY:	all debug clean clean_dependencies fclean fclean_dependencies re re_dependencies r
