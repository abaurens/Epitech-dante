/*
** maze.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:32:26 2017 Arthur Baurens
** Last update Thu Jun  1 11:23:30 2017 Arthur Baurens
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
	char	**tab;

	c = 0;
	tab = maze->tab;
	if ((y == 0 && x == 0) || (y == maze->h - 1 && x == maze->w - 1))
    	return (1);
	if (x < 0 || x >= maze->w || y < 0 || y >= maze->h || tab[y][x] != EMPTY)
		return (0);
	if (y + 1 < maze->h && tab[y + 1][x] == EMPTY)
    	c++;
	if (y - 1 >= 0 && tab[y - 1][x] == EMPTY)
    	c++;
	if (x - 1 >= 0 && tab[y][x - 1] == EMPTY)
    	c++;
	if (x + 1 < maze->w && tab[y][x + 1] == EMPTY)
    	c++;
	if (c == 2 && ((y + 1 < maze->h && y - 1 >= 0 && tab[y + 1][x] == EMPTY &&
	tab[y - 1][x] == EMPTY) || (x + 1 < maze->w && x - 1 >= 0 &&
		tab[y][x + 1] == EMPTY && tab[y][x - 1] == EMPTY)))
			return (0);
	return (1);
}

static void		link_nodes(t_maze *mze, t_list *graph)
{
	int			i;
	int			j;
	t_vec		pos;
	t_elem_list	*e;

	e = graph->head;
	dprintf(2, "le laby fait %d de large et %d de haut\n", mze->w, mze->h);
	while (e != NULL)
    {
		i = -1;
		while (++i < 2)
		{
			pos = ((t_node *)e->data)->pos;
			if (!in_bound(vadd(pos, VEC((1 - i), i)), mze->w, mze->h)
				|| mze->tab[pos.y + i][pos.x + (1 - i)] != EMPTY)
				continue;
				/*
				if (pos.y + i >= mze->h || pos.x + (1 - i) >= mze->w ||
				mze->tab[pos.y + i][pos.x + (1 - i)] != EMPTY)
				*/
			j = 0;
			while (++j && pos.x + (1 - i) * j < mze->w && pos.y + i * j < mze->h
					&& !is_cross(mze, pos.x + (1 - i) * j, pos.y + i * j));
			if (pos.y + i * j >= mze->h || pos.x + (1 - i) * j >= mze->w)
				continue;
			dprintf(2, "lien détecté en position x:%d y:%d vers la position x:%d y:%d\n",
				pos.x, pos.y, pos.x + (1 - i) * j, pos.y + i * j);
			/*pos.y = pos.y + i * j;
			pos.x = pos.x + (1 - i) * j;*/
			pos = vadd(pos, VEC((1 - i) * j, i * j));
			link_node(e->data, get_elem(graph, &pos, &cmp_node));
		}
		e = e->next;
	}
}

void				get_maze_graph(t_maze *maze, t_list *graph)
{
	int				l;
	int				x;
	int				y;
	t_node_state	ns;

	l = 0;
	y = -1;
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
			if (is_cross(maze, x, y) && ++l)
				add_elem(graph, new_node(x, y, ns));
		}
	}
	dprintf(2, "\tLinking %d nodes...\n", l);
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
