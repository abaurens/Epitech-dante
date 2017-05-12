/*
** main.c for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:19:45 2017 Arthur Baurens
** Last update Fri May 12 20:25:11 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "lib_str.h"
#include "lib_list.h"
#include "file_loader.h"

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
      remove_elem(lst, lst->head);
    }
  return (0);
}

t_node		*new_node(int x, int y, t_node_state s)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos.x = x;
  node->pos.y = y;
  node->state = s;
  node->linked = NULL;
  return (node);
}

char	is_cross(t_maze *maze, int x, int y)
{
  int	c;
  char	**tab;

  c = 0;
  tab = maze->tab;
  if ((y == 0 && x == 0) || (y == maze->h - 1 && x == maze->w - 1))
    return (1);
  if (tab[y][x] != '*')
    return (0);
  if (y + 1 < maze->h && (tab[y + 1][x] == '*' || tab[y + 1][x] == 'o'))
    c++;
  if (y - 1 >= 0 && (tab[y - 1][x] == '*' || tab[y - 1][x] == 'o'))
    c++;
  if (x - 1 >= 0 && (tab[y][x - 1] == '*' || tab[y][x - 1] == 'o'))
    c++;
  if (x + 1 < maze->w && (tab[y][x + 1] == '*' || tab[y][x + 1] == 'o'))
    c++;
  if ((c == 2 && y + 1 < maze->h && y - 1 >= 0 &&
       (tab[y + 1][x] == '*' || tab[y + 1][x] == 'o') &&
       (tab[y - 1][x] == '*' || tab[y - 1][x] == 'o')) ||
     (c == 2 && x + 1 < maze->w && x - 1 >= 0 &&
      (tab[y][x + 1] == '*' || tab[y][x + 1] == 'o') &&
      (tab[y][x - 1] == '*' || tab[y][x - 1] == 'o')))
    return (0);
  return (1);
}

void	get_maze_graph(t_maze *maze, t_list *lst)
{
  int	x;
  int	y;

  y = -1;
  while (++y < maze->h)
    {
      x = -1;
      while (++x < maze->w)
	{
	  if (is_cross(maze, x, y))
	    maze->tab[y][x] = 'o';
	}
    }
}

int		main(int ac, char **av)
{
  int		fd;
  int		lol;
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
  for (fd = 0; fd < maze.h + 2; fd++)
    printf("X");
  printf("\n");
  for (fd = 0; fd < maze.h; fd++)
    {
      printf("X");
      for (lol = 0; lol < maze.w; lol++)
	{
	  if (maze.tab[fd][lol] == '*')
	    printf(" ");
	  else
	    printf("%c", maze.tab[fd][lol]);
	}
      printf("X\n");
    }
    for (fd = 0; fd < maze.h + 2; fd++)
      printf("X");
    printf("\n");
  return (0);
}
