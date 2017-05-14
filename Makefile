##
## Makefile for dante in /home/baurens/Work/Tek1/Projects/IA/dante/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sun May 14 23:37:24 2017 Arthur Baurens
## Last update Sun May 14 23:38:39 2017 Arthur Baurens
##

CC	=	gcc

DEP	=	./astar/solver	\
		./depth/solver	\
		./breadth/solver

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
