/*
** display.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 10:10:01 2017 Arthur Baurens
** Last update Fri Apr 28 12:28:34 2017 Arthur Baurens
*/

#include <stdio.h>
#include "gen.h"

void	display_maze(t_maze *maze)
{
  int	i;

  i = -1;
  while (++i < (maze->w + 2))
    printf("X");
  i = -1;
  printf("\n");
  while (++i < maze->h)
    printf("X%sX\n", maze->grid[i]);
  i = -1;
  while (++i < (maze->w + 2))
    printf("X");
  printf("\n");
}
