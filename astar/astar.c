/*
** astar.c for astar in /home/baurens/Work/Tek1/Projects/IA/dante/astar/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun May 14 20:17:57 2017 Arthur Baurens
** Last update Sun May 14 23:36:46 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "solver.h"
#include "lib_maze.h"
#include "lib_list.h"

void		swap(t_astar *p1, t_astar *p2)
{
  int		dist;
  int		total;
  t_node	*node;
  t_astar	*from;

  dist = p1->dist;
  total = p1->total;
  node = p1->node;
  from = p1->from;
  p1->dist = p2->dist;
  p1->total = p2->total;
  p1->node = p2->node;
  p1->from = p2->from;
  p2->dist = dist;
  p2->total = total;
  p2->node = node;
  p2->from = from;
}

void		sort_list(t_astar *list)
{
  char		loop;
  t_astar	*cur;

  loop = 1;
  while (loop)
    {
      loop = 0;
      cur = list;
      while (cur)
	{
	  if (cur && cur->next && cur->dist > cur->next->dist)
	    {
	      swap(cur, cur->next);
	      loop = 1;
	    }
	  cur = cur->next;
	}
    }
}

void		aply_for_child(t_astar **s, t_astar *b, t_astar *c, t_node *o)
{
  int		dis;
  int		heu;
  t_astar	*t;
  t_elem_list	*lnk;

  lnk = c->node->linked.head;
  while (lnk != NULL)
    {
      t = find_astar(*s, lnk->data);
      dis = c->dist + get_dist(c->node, lnk->data);
      heu = get_heur(dis, lnk->data, o);
      if (t == NULL && find_astar(b, lnk->data) == NULL)
	add_astar(s, lnk->data, o, c);
      else if (t != NULL && t->total > heu)
	{
	  t->dist = dis;
	  t->total = heu;
	  t->from = c;
	}
      lnk = lnk->next;
    }
}

void		astar(t_list *path, t_node *n, t_node *s)
{
  t_astar	*stack;
  t_astar	*backup;
  t_astar	*cur;

  stack = NULL;
  backup = NULL;
  add_astar(&stack, n, s, NULL);
  while (stack != NULL)
    {
      link_astar(&backup, cur = pop_astar(&stack, stack));

      if (cur->node == s)
	{
	  while (cur != NULL)
	    {
	      add_elem(path, cur->node);
	      cur = cur->from;
	    }
	  return;
	}
      aply_for_child(&stack, backup, cur, s);
      sort_list(stack);
    }
}
