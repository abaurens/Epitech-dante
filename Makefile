##
## Makefile for dante in /home/baurens/Work/Tek1/Projects/IA/dante/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sun May 14 23:37:24 2017 Arthur Baurens
## Last update Sun May 14 23:44:26 2017 Arthur Baurens
##

CC	=	gcc

NAME	=	dante

DEP	=	solver
DEP1_D	=	./astar/
DEP2_D	=	./astar/
DEP3_D	=	./astar/
DEP1	=	./astar/$(DEP)
DEP2	=	./astar/$(DEP)
DEP3	=	./astar/$(DEP)

$(NAME):	$(DEP1) $(DEP2) $(DEP3)

$(DEP1):
	make -C $(DEP1_D)

$(DEP2):
	make -C $(DEP2_D)

$(DEP3):
	make -C $(DEP3_D)

all:	$(NAME)

clean:
	make -C $(DEP) clean

clean_dependencies: clean
	make -C $(DEP) clean_dependencies

fclean:	clean
	make -C $(DEP) fclean

fclean_dependencies: fclean
	make -C $(DEP) fclean_dependencies

rebuild_dependencies:
	make -C $(DEP_DIR) re_dependencies

re_dependencies: rebuild_dependencies re

re:
	make -C $(DEP) re

.PHONY:	all debug clean clean_dependencies fclean fclean_dependencies re re_dependencies r
