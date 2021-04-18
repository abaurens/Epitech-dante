/*
** checker.c for depth in /home/baurens/Work/Tek1/Projects/IA/dante/depth/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun May 14 17:51:40 2017 Arthur Baurens
** Last update Sun May 14 19:50:01 2017 Arthur Baurens
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib_str.h"
#include "lib_list.h"
#include "lib_maze.h"
#include "solver.h"

char	check_io(char **maze, int w, int h)
{
  int	i;

  i = -1;
  if (maze[0][0] == EMPTY && maze[h - 1][w - 1] == EMPTY)
    return (0);
  write(1, "no solution found\n", 18);
  while (maze[++i])
    free(maze[i]);
  free(maze);
  return (1);
}

static void	display(t_maze *maze)
{
  int		y;
  int		x;

  y = -1;
  while (++y < maze->h)
    {
      x = -1;
      while (++x < maze->w)
	printf("%c", maze->tab[y][x]);
      printf("\n");
    }
}

static void	place_path(t_list *path, t_maze *maze)
{
  int		l;
  t_vec		dif;
  t_node	*n1;
  t_node	*n2;

  while (path->size)
    {
      if (path->head->next != NULL)
	{
	  n1 = path->head->data;
	  n2 = path->head->next->data;
	  dif.x = n2->pos.x - n1->pos.x;
      	  dif.y = n2->pos.y - n1->pos.y;
      	  l = ABS(dif.x + dif.y);
      	  dif.x /= l;
      	  dif.y /= l;
      	  while (l >= 0)
      	    {
      	      maze->tab[n1->pos.y + dif.y * l][n1->pos.x + dif.x * l] = PATH;
      	      l--;
      	    }
	}
      remove_elem(path, path->head->data);
    }
}

int	check_solution(t_list *path, t_maze *maze, t_list *graph)
{
  int	ret;

  ret = 84;
  if (path->size > 0)
    {
      place_path(path, maze);
      display(maze);
      ret = 0;
    }
  else
    write(1, "no solution found\n", 18);
  delete_maze(maze);
  clear_graph(graph);
  return (ret);
}
