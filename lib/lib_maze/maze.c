/*
** maze.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:32:26 2017 Arthur Baurens
** Last update Mon May 29 14:07:22 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_list.h"
#include "lib_maze.h"

static char	cmp_node(t_node *node, t_vec *pos)
{
  if (node->pos.x == pos->x && node->pos.y == pos->y)
    return (1);
  return (0);
}

static char	is_cross(t_maze *maze, int x, int y)
{
  int		c;
  char		**tab;

  c = 0;
  tab = maze->tab;
  if ((y == 0 && x == 0) || (y == maze->h - 1 && x == maze->w - 1))
    return (1);
  if (x < 0 || x >= maze->w || y < 0 || y >= maze->h || tab[y][x] != '*')
    return (0);
  if (y + 1 < maze->h && tab[y + 1][x] == '*')
    c++;
  if (y - 1 >= 0 && tab[y - 1][x] == '*')
    c++;
  if (x - 1 >= 0 && tab[y][x - 1] == '*')
    c++;
  if (x + 1 < maze->w && tab[y][x + 1] == '*')
    c++;
  if ((c == 2 && y + 1 < maze->h && y - 1 >= 0 && tab[y + 1][x] == '*' &&
       tab[y - 1][x] == '*') || (c == 2 && x + 1 < maze->w && x - 1 >= 0 &&
       tab[y][x + 1] == '*' && tab[y][x - 1] == '*'))
    return (0);
  return (1);
}

static void	link_nodes(t_maze *maze, t_list *graph)
{
  int		i;
  int		j;
  t_node	*l;
  t_vec		pos;
  t_elem_list	*e;

  e = graph->head;
  while (e != NULL)
    {
      i = -1;
      pos = ((t_node *)e->data)->pos;
      while (++i < 2)
	{
	  if (pos.y + i >= maze->h || pos.x + (1 - i) >= maze->w ||
	      maze->tab[pos.y + i][pos.x + (1 - i)] != '*')
	    continue;
	  j = 0;
	  while (++j && !is_cross(maze, pos.x + (1 - i) * j, pos.y + i * j));
	  pos.y = pos.y + i * j;
  	  pos.x = pos.x + (1 - i) * j;
	  l = get_elem(graph, &pos, &cmp_node);
	  link_node(e->data, l);
	}
      e = e->next;
    }
}

void		get_maze_graph(t_maze *maze, t_list *graph)
{
  unsigned int	x;
  unsigned int	y;
  t_node_state	ns;

  y = -1;
  dprintf(2, "\tadding nodes...\n");
  while (++y < maze->h)
    {
      x = -1;
      while (++x < maze->w)
	{
	  if (x == 0 && y == 0)
	    ns = NS_INPUT;
	  else if (x == maze->w - 1 && y == maze->h - 1)
	    ns = NS_OUTPUT;
	  else
	    ns = NS_MIDLE;
	  if (is_cross(maze, x, y))
	    add_elem(graph, new_node(x, y, ns));
	}
    }
  dprintf(2, "\tLinking nodes...\n");
  link_nodes(maze, graph);
}

void	delete_maze(t_maze *maze)
{
  int	i;

  i = 0;
  while (maze->tab[i])
    {
      free(maze->tab[i]);
      i++;
    }
  free(maze->tab);
  maze->tab = NULL;
}
