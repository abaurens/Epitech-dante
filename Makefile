##
## Makefile for dante in /home/baurens/Work/Tek1/Projects/IA/dante/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Sun May 14 23:37:24 2017 Arthur Baurens
## Last update Mon May 29 13:01:57 2017 Arthur Baurens
##

CC	=	gcc

all:
#	mkdir -p tournament
	make -C ./astar
	make -C ./depth
	make -C ./breadth
	make -C ./generator
#	make -C ./tournament

clean:
	make -C ./generator clean
	make -C ./astar clean_dependencies
	make -C ./depth clean_dependencies
	make -C ./breadth clean_dependencies
#	make -C ./tournament clean_dependencies

fclean: clean
	make -C ./generator fclean
	make -C ./astar fclean_dependencies
	make -C ./depth fclean_dependencies
	make -C ./breadth fclean_dependencies
#	make -C ./tournament fclean_dependencies
#	rm -rf ./tournament/solver

re:	fclean all

.PHONY:	all clean fclean re
