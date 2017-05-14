/*
** solver.h for solver in /home/baurens/Work/Tek1/Projects/IA/dante/depth/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun May 14 18:04:09 2017 Arthur Baurens
** Last update Sun May 14 18:19:33 2017 Arthur Baurens
*/

#ifndef SOLVER_H_
# define SOLVER_H_

#include "lib_list.h"
#include "lib_maze.h"

char	check_io(char **maze, int w, int h);
int	check_solution(t_list *path, t_maze *maze, t_list *graph);

#endif /* !SOLVER_H_ */
