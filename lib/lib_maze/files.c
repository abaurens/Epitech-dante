/*
** maze.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:24:44 2017 Arthur Baurens
** Last update Mon May 29 13:06:19 2017 Arthur Baurens
*/

#include <stdlib.h>
#include "lib_str.h"
#include "lib_list.h"
#include "lib_maze.h"

t_list					get_files_lines(const int fd)
{
	unsigned long int	size;
	unsigned long int	curr;
	char				*line;
	t_list				lst;

	lst = init_list();
	while ((line = get_next_line(fd)) != NULL)
    {
		if (add_elem(&lst, line))
		{
			free(line);
			clear_list(&lst);
			return (lst);
		}
	}
	return (lst);
}

char	get_tab_from_list(t_list *l, t_maze *maze)
{
	int	i;

	i = -1;
	maze->tab = NULL;
	if (l->size == 0 || !(maze->tab = malloc(sizeof(char *) * (l->size + 1))))
		return (1);
	maze->h = l->size;
	maze->tab[l->size] = NULL;
	maze->w = str_len(l->head->data);
	while (l->size)
    {
		if ((str_len(l->head->data) != maze->w) ||
		(maze->tab[++i] = my_strncat(l->head->data, NULL, 0)) == NULL)
		{
			clear_list(l);
			while (--i >= 0)
				free(maze->tab[i]);
			free(maze->tab);
			maze->tab = NULL;
			return (1);
		}
		free(l->head->data);
		remove_elem(l, l->head->data);
	}
	/*
	for (i = 0; i < maze->h; i++)
	{
		dprintf(2, maze->tab[i]);
		dprintf(2, "\n");
	}
	*/
	return (0);
}
