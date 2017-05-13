/*
** maze.c for graph in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sat May 13 20:24:44 2017 Arthur Baurens
** Last update Sat May 13 21:15:26 2017 Arthur Baurens
*/

#include <stdlib.h>
#include "lib_str.h"
#include "lib_list.h"
#include "lib_maze.h"

t_list		get_files_lines(const int fd)
{
  char		*line;
  t_list	lst;

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

char	get_tab_from_list(t_list *lst, t_maze *maze)
{
  int	i;

  i = -1;
  maze->tab = NULL;
  if (lst->size == 0 ||
      (maze->tab = malloc(sizeof(char *) * (lst->size + 1))) == NULL)
    return (1);
  maze->h = lst->size;
  maze->tab[lst->size] = NULL;
  maze->w = str_len(lst->head->data);
  while (lst->size)
    {
      if ((str_len(lst->head->data) != maze->w) ||
	  (maze->tab[++i] = my_strncat(lst->head->data, NULL, 0)) == NULL)
	{
	  clear_list(lst);
	  while (--i >= 0)
	    free(maze->tab[i]);
	  free(maze->tab);
	  maze->tab = NULL;
	  return (1);
	}
      remove_elem(lst, lst->head->data);
    }
  return (0);
}
