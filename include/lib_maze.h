/*
** lib_maze.h for lib_maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 17:31:18 2017 Arthur Baurens
** Last update Sun May 14 19:58:11 2017 Arthur Baurens
*/

#ifndef LIB_MAZE_H_
# define LIB_MAZE_H_

# define EMPTY ' '
# define WALL 'X'
# define PATH 'o'

# define ABS(x) ((x) < 0 ? (-(x)) : (x))
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
}				t_vec;

# define VEC(x, y) ((t_vec){(x), (y)})

typedef struct 	test
{
  t_vec		vec;
}		t_test;

typedef enum	e_node_state
{
  NS_INPUT,
  NS_MIDLE,
  NS_OUTPUT
}				t_node_state;

typedef struct s_node_list	t_node_list;

typedef struct s_node
{
  struct s_node	*parent;
  t_vec			pos;
  char			marked;
  t_list		linked;
  t_node_state	state;
}				t_node;

t_node	*new_node(int, int, t_node_state);
void	unlink_node(t_node *, t_node *);
void	link_node(t_node *, t_node *);

t_list	get_files_lines(const int);
char	get_tab_from_list(t_list *, t_maze *);

void	get_maze_graph(t_maze *, t_list *);
void	display_graph(t_list *, const int, const int);
void	clear_graph(t_list *);

void	remove_useless_nodes(t_list *graph);
void	simplify_graph(t_list *);
void	delete_maze(t_maze *);

t_vec	vadd(t_vec, t_vec);
char	in_bound(t_vec, int, int);
char	in_bound_v(t_vec, t_vec, t_vec);

#endif /* !LIB_MAZE_H_ */
