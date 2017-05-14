##
## Makefile for dante in /home/baurens/Work/Tek1/Projects/IA/dante/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sun May 14 23:37:24 2017 Arthur Baurens
## Last update Sun May 14 23:49:10 2017 Arthur Baurens
##

CC	=	gcc

all:
	make -C ./astar
	make -C ./depth
	make -C ./breadth
	make -C ./generator

clean:
	make -C ./astar clean
	make -C ./depth clean
	make -C ./breadth clean
	make -C ./generator clean

clean_dependencies: clean
	make -C ./astar clean_dependencies
	make -C ./depth clean_dependencies
	make -C ./breadth clean_dependencies
	make -C ./generator clean_dependencies

fclean:	clean
	make -C ./astar fclean
	make -C ./depth fclean
	make -C ./breadth fclean
	make -C ./generator fclean


fclean_dependencies: fclean
	make -C ./astar fclean_dependencies
	make -C ./depth fclean_dependencies
	make -C ./breadth fclean_dependencies
	make -C ./generator fclean_dependencies

re:
	make -C ./astar re
	make -C ./depth re
	make -C ./breadth re
	make -C ./generator re

.PHONY:	all clean clean_dependencies fclean fclean_dependencies re
