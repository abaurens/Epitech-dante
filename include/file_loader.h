/*
** file_loader.h for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:31:18 2017 Arthur Baurens
** Last update Fri May 12 19:53:39 2017 Arthur Baurens
*/

#ifndef LIB_MAZE_H_
# define LIB_MAZE_H_

typedef struct	s_maze
{
  int		w;
  int		h;
  char		**tab;
}		t_maze;

typedef struct	s_vec
{
  int		x;
  int		y;
}		t_vec;

typedef enum	e_node_state
{
  INPUT,
  MIDLE,
  OUTPUT
}		t_node_state;

typedef struct s_node_list	t_node_list;

typedef struct s_node
{
  t_vec		pos;
  t_node_list	*linked;
  t_node_state	state;
}		t_node;

struct		s_node_list
{
  struct s_node_list	*next;
  struct s_node_list	*prev;
  t_node		*data;
};


#endif /* !LIB_MAZE_H_ */
