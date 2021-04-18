/*
** nodes.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:20:14 2017 Arthur Baurens
** Last update Sun May 14 19:59:14 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_list.h"
#include "lib_maze.h"

t_node		*new_node(int x, int y, t_node_state s)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos.x = x;
  node->pos.y = y;
  node->state = s;
  node->marked = 0;
  node->parent = NULL;
  node->linked = init_list();
  return (node);
}

void		link_node(t_node *n1, t_node *n2)
{
	t_elem_list	*l;

	l = n1->linked.head;
	if (n1 == NULL || n2 == NULL)
		return;
	while (l != NULL)
    {
		if (l->data == n2)
			return;
		l = l->next;
	}
	add_elem(&n1->linked, n2);
	add_elem(&n2->linked, n1);
}

void		unlink_node(t_node *n1, t_node *n2)
{
  t_elem_list	*l;
  t_elem_list	*nxt;

  l = n1->linked.head;
  if (n1 == NULL || n2 == NULL)
    return;
  while (l != NULL)
    {
      nxt = l->next;
      if (l->data == n2)
	{
	  remove_elem(&n1->linked, n2);
	  remove_elem(&n2->linked, n1);
	}
      l = nxt;
    }
}
