/*
** main.c for perfect in /home/baurens/Work/Tek1/Projects/IA/dante/generator/perfect_dir/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Apr 20 18:31:37 2017 Arthur Baurens
** Last update Sun May 14 18:41:32 2017 Arthur Baurens
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "gen.h"

char	print_usage(const char *name)
{
  dprintf(2, "%s x y [perfect]\n", name);
  return (84);
}

char	parse_args(const char *name, const char *arg)
{
  int	i;

  i = -1;
  while (arg[++i])
    {
      if (arg[i] == 'h')
	return (print_usage(name));
      else
	return (arg[i]);
    }
  return (0);
}

int	main(int ac, char **av)
{
  int		i;
  char		*e;
  t_maze	maze;

  i = 0;
  srand(time(NULL) * getpid() * getppid());
  memset(&maze, 0, sizeof(maze));
  e = "Grid size has to be positives values";
  if (ac < 3 || (maze.w = atoi(av[1])) <= 0 || (maze.h = atoi(av[2])) <= 0)
    {
      dprintf(2, "%s: Invalid argument(s). %s.\n", av[0], e);
      return (print_usage(av[0]));
    }
  if (ac == 4 && !(maze.perfect = !strcmp(av[3], "perfect")))
    {
      dprintf(2, "%s: Unknown argument '%s'.\n", av[0], av[3]);
      return (print_usage(av[0]));
    }
  if (ac > 4)
    {
      dprintf(2, "%s: To many arguments.\n", av[0]);
      return (print_usage(av[0]));
    }
  gen_maze(&maze);
  return (0);
}
