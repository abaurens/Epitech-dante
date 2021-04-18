/*
** graph.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:49:36 2017 Arthur Baurens
** Last update Sun May 14 16:10:33 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_list.h"
#include "lib_maze.h"

void		remove_useless_nodes(t_list *graph)
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
	{
	  remove_elem(graph, cur);
	  free(cur);
	}
      lst = nxt;
    }
}

void			simplify_graph(t_list *graph)
{
	t_node		*n;
	t_node		*t;
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

void		draw_ascii_line(char **tab, t_vec from, t_vec to)
{
	char		c;

	if (from.x > to.x || from.y > to.y)
		return;
	c = '-';
	while (from.x != to.x && ++from.x < to.x)
		tab[from.y][from.x] = c;
	c = '|';
	while (from.y != to.y && ++from.y < to.y)
		tab[from.y][from.x] = c;
}

void			display_graph(t_list *graph, const int w, const int h)
{
	int			i;
	int			j;
	char		**tab;
	t_node		*n;
	t_node		*l;
	t_elem_list	*t;
	t_elem_list *lst;

	i = 0;
	lst = graph->head;
	tab = malloc(sizeof(char *) * h);
	for (i = 0; i < h; i++)
		tab[i] = malloc(w);
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			tab[i][j] = ' ';
	while (lst != NULL)
	{
		n = lst->data;
		t = n->linked.head;
		while (t != NULL)
		{
			l = t->data;
			tab[n->pos.y][n->pos.x] = PATH;
			draw_ascii_line(tab, n->pos, l->pos);
			tab[l->pos.y][l->pos.x] = PATH;
			t = t->next;
		}
		tab[n->pos.y][n->pos.x] = PATH;
		lst = lst->next;
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
			dprintf(2, "%c", tab[i][j]);
		free(tab[i]);
		dprintf(2, "\n");
	}
	free(tab);
}

void		clear_graph(t_list *graph)
{
  t_node	*cur;

  while (graph->size)
    {
      cur = graph->head->data;
      clear_list(&cur->linked);
      remove_elem(graph, cur);
      free(cur);
    }
}
