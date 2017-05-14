/*
** display.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 10:10:01 2017 Arthur Baurens
** Last update Sun May 14 19:06:05 2017 Arthur Baurens
*/

#include <unistd.h>
#include <stdio.h>
#include "gen.h"

void	display_maze(t_maze *maze)
{
  int	i;

  i = -1;
  while (++i < maze->h)
    {
      printf("%s", maze->grid[i]);
      if (i < maze->h - 1)
	printf("\n");
    }
}
