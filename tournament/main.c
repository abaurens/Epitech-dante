/*
** main.c for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:19:45 2017 Arthur Baurens
** Last update Mon May 29 13:24:34 2017 Arthur Baurens
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
  dprintf(2, "Opening file...\n");
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (84);
  dprintf(2, "Getting file lines...\n");
  lst = get_files_lines(fd);
  /*display_list(&lst);*/
  dprintf(2, "Closing file\n");
  close(fd);
  dprintf(2, "Converting to maze...\n");
  if (get_tab_from_list(&lst, &maze) || check_io(maze.tab, maze.w, maze.h))
    return (84);
  dprintf(2, "Converting to graph...\n");
  get_maze_graph(&maze, &graph);
  display_graph(&graph, maze.w, maze.h);
  dprintf(2, "Symplifying graph...\n");
  simplify_graph(&graph);
  display_graph(&graph, maze.w, maze.h);
  dprintf(2, "Looking for solutions...\n");
  astar(&path, graph.head->data, graph.tail->data);
  dprintf(2, "Displaying solution :\n");
  return (check_solution(&path, &maze, &graph));
}
