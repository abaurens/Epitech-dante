/*
** main.c for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:19:45 2017 Arthur Baurens
** Last update Sun May 14 20:09:46 2017 Arthur Baurens
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "solver.h"
#include "lib_str.h"
#include "lib_list.h"
#include "lib_maze.h"

static void	explore(t_node *n)
{
  t_node	*t;
  t_list	stack;
  t_elem_list	*lnk;

  stack = init_list();
  add_elem(&stack, n);
  n->marked = 1;
  while (stack.size)
    {
      n = stack.head->data;
      remove_elem(&stack, n);
      lnk = n->linked.head;
      while (lnk != NULL)
	{
	  t = lnk->data;
	  if (t->marked == 0)
	    {
	      t->marked = 1;
	      t->parent = n;
	      add_elem(&stack, t);
	    }
	  lnk = lnk->next;
	}
    }
}

static void	backtrack(t_list *path, t_node *n)
{
  if (n && n->parent == NULL)
    return;
  while (n != NULL)
    {
      add_elem(path, n);
      n = n->parent;
    }
}

int		main(int ac, char **av)
{
  int		fd;
  t_list	lst;
  t_list	path;
  t_list	graph;
  t_maze	maze;

  if (ac != 2)
    return (0);
  path = init_list();
  graph = init_list();
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (84);
  lst = get_files_lines(fd);
  close(fd);
  if (get_tab_from_list(&lst, &maze) || check_io(maze.tab, maze.w, maze.h))
    return (84);
  get_maze_graph(&maze, &graph);
  simplify_graph(&graph);
  explore(graph.head->data);
  backtrack(&path, graph.tail->data);
  return (check_solution(&path, &maze, &graph));
}
