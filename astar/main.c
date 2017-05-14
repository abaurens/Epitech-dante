/*
** main.c for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:19:45 2017 Arthur Baurens
** Last update Sun May 14 22:27:20 2017 Arthur Baurens
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
  astar(&path, graph.head->data, graph.tail->data);
  return (check_solution(&path, &maze, &graph));
}
