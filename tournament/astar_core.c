/*
** astar_core.c for astar in /home/baurens/Work/Tek1/Projects/IA/dante/astar/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun May 14 23:35:50 2017 Arthur Baurens
** Last update Sun May 14 23:36:03 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "solver.h"
#include "lib_maze.h"
#include "lib_list.h"

int	get_heur(int dist, t_node *n, t_node *s)
{
  int		dist_x;
  int		dist_y;

  dist_x = (s->pos.x - n->pos.x);
  dist_x *= dist_x;
  dist_y = (s->pos.y - n->pos.y);
  dist_y *= dist_y;
  return (dist + (dist_x + dist_y));
}

void		add_astar(t_astar **list, t_node *n, t_node *s, t_astar *from)
{
  t_astar	*elem;

  if ((elem = malloc(sizeof(t_astar))) == NULL)
    return;
  elem->node = n;
  elem->dist = 0;
  if (from != NULL)
    elem->dist = from->dist + get_dist(from->node, n);
  elem->from = from;
  elem->total = get_heur(elem->dist, n, s);
  elem->next = *list;
  elem->prev = NULL;
  if (elem->next != NULL)
    elem->next->prev = elem;
  *list = elem;
}

void	link_astar(t_astar **list, t_astar *elem)
{
  elem->next = *list;
  elem->prev = NULL;
  if (elem->next != NULL)
    elem->next->prev = elem;
  *list = elem;
}

t_astar	*pop_astar(t_astar **list, t_astar *elem)
{
  if (*list == elem)
    *list = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

t_astar	*find_astar(t_astar *list, t_node *elem)
{
  while (list != NULL && list->node != elem)
    list = list->next;
  return (list);
}
