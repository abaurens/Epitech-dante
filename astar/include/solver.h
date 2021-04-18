/*
** solver.h for solver in /home/baurens/Work/Tek1/Projects/IA/dante/depth/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Sun May 14 18:04:09 2017 Arthur Baurens
** Last update Sun May 14 23:36:27 2017 Arthur Baurens
*/

#ifndef SOLVER_H_
# define SOLVER_H_

#include "lib_list.h"
#include "lib_maze.h"

# define EMPTY ' '
# define PATH 'o'

typedef struct		s_astar
{
  struct s_astar	*next;
  struct s_astar	*prev;
  struct s_astar	*from;
  t_node		*node;
  int			dist;
  float			total;
}			t_astar;

int	get_heur(int dist, t_node *n, t_node *s);
void	add_astar(t_astar **list, t_node *n, t_node *s, t_astar *from);
void	link_astar(t_astar **list, t_astar *elem);
t_astar	*pop_astar(t_astar **list, t_astar *elem);
t_astar	*find_astar(t_astar *list, t_node *elem);

void	astar(t_list *, t_node *, t_node *);

char	check_io(char **maze, int w, int h);
int	check_solution(t_list *path, t_maze *maze, t_list *graph);
int	get_dist(t_node *n1, t_node *n2);

#endif /* !SOLVER_H_ */
