##
## Makefile for lst in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Fri May 12 15:20:49 2017 Arthur Baurens
## Last update Sat May 13 22:53:12 2017 Arthur Baurens
##

CC	=	gcc

NAME	=	liblst.a

DEP	=	../libstr.a

DEP_DIR	=	../lib_str/

SRC	=	elements.c	\
		instancier.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -I../../include -W -Wall -Wextra #-ansi -pedantic

$(NAME):	$(OBJ) $(DEP)
	ar rcs $(NAME) $(OBJ)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

$(DEP):
	make -C $(DEP_DIR)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	$(DEP) $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	cp -f ./include/* ../../include/
	cp -f ./$(NAME) ../

clean:
	$(RM) $(OBJ)

clean_dependencies: clean
	make -C $(DEP_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

fclean_dependencies: fclean
	make -C $(DEP_DIR) fclean

re:	fclean all

rebuild_dependencies:
	make -C $(DEP_DIR) re

re_dependencies: rebuild_dependencies re

r:	fclean debug

.PHONY:	all debug clean clean_dependencies fclean fclean_dependencies re re_dependencies r
