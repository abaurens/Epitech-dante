/*
** main.c for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:19:45 2017 Arthur Baurens
** Last update Sat May 13 22:36:36 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "lib_str.h"
#include "lib_list.h"
#include "lib_maze.h"

void		display(t_maze *maze, t_list *graph)
{
  int		y;
  int		x;
  t_node	*n;
  t_node	*l;
  t_elem_list	*lk;
  t_elem_list	*ls;

  for (ls = graph->head; ls != NULL; ls = ls->next)
    {
      n = ls->data;
      maze->tab[n->pos.y][n->pos.x] = 'o';
      for (lk = n->linked.head; lk != NULL; lk = lk->next)
	{
	  l = lk->data;
	  x = l->pos.x - n->pos.x;
	  y = l->pos.y - n->pos.y;
	  if (x > 0)
	  {
	      x--;
	      for (; x > 0; x--)
		  maze->tab[n->pos.y][n->pos.x + x] = '-';
	  }
	  if (y > 0)
	  {
	      y--;
	      for(; y > 0; y--)
		  maze->tab[n->pos.y + y][n->pos.x] = '|';
	  }
	}
  }
    for (y = 0; y < maze->h; y++)
      {
        for (x = 0; x < maze->w; x++)
  	{
	  if (maze->tab[y][x] == '*' || maze->tab[y][x] == 'X')
	    printf(" ");
	  else
	    printf("%c", maze->tab[y][x]);
  	}
      printf("\n");
      }
}

int		main(int ac, char **av)
{
  int		fd;
  t_list	lst;
  t_list	graph;
  t_maze	maze;

  if (ac != 2)
    return (0);
  graph = init_list();
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (1);
  lst = get_files_lines(fd);
  close(fd);
  get_tab_from_list(&lst, &maze);
  get_maze_graph(&maze, &graph);
  simplify_graph(&graph);
  display(&maze, &graph);
  return (0);
}
