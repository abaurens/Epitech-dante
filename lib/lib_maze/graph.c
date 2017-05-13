/*
** graph.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:49:36 2017 Arthur Baurens
** Last update Sat May 13 22:53:51 2017 Arthur Baurens
*/

#include <unistd.h>
#include "lib_list.h"
#include "lib_maze.h"

static void	remove_useless_nodes(t_list *graph)
{
  t_node	*cur;
  t_elem_list	*lst;
  t_elem_list	*nxt;

  lst = graph->head;
  while (lst != NULL)
    {
      cur = lst->data;
      nxt = lst->next;
      if (cur->linked.size == 0)
	remove_elem(graph, cur);
      lst = nxt;
    }
}

void		simplify_graph(t_list *graph)
{
  t_node	*n;
  t_node	*t;
  t_elem_list	*lst;

  lst = graph->head;
  while (lst != NULL)
    {
      n = lst->data;
      while (n->state == NS_MIDLE && n->linked.size == 1)
	{
	  t = n->linked.head->data;
	  if (t->state == NS_MIDLE)
	    unlink_node(n, t);
	  n = t;
	}
      lst = lst->next;
    }
  remove_useless_nodes(graph);
}
