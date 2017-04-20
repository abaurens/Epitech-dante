##
## Makefile for generator in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Thu Apr 20 18:19:57 2017 Arthur Baurens
## Last update Thu Apr 20 19:17:40 2017 Arthur Baurens
##

NAME		=	generator

PERFECT		=	perfect

IMPERFECT	=	imperfect

INCLUDES	=	-I./include

$(NAME):	perfect_c imperfect_c
	@cp $(PERFECT) $(NAME)

all:	$(NAME)

perfect_c:
	@make -C ./$(PERFECT)_dir

imperfect_c:
	@make -C ./$(IMPERFECT)_dir

$(PERFECT): perfect_c
	@cp $(PERFECT) $(NAME)

$(IMPERFECT):	imperfect_c
	@cp $(IMPERFECT) $(NAME)

clean:
	@make -C ./$(PERFECT)_dir clean
	@make -C ./$(IMPERFECT)_dir clean

fclean:
	@make -C ./$(IMPERFECT)_dir fclean
	@make -C ./$(PERFECT)_dir fclean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	perfect imperfect all clean fclean re
