/*
** gen.h for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 09:00:37 2017 Arthur Baurens
** Last update Sun May 14 18:38:42 2017 Arthur Baurens
*/

#ifndef GEN_H_
# define GEN_H_

# define WALL 'X'
# define PATH '*'

typedef struct	s_vec
{
  int		x;
  int		y;
}		t_vec;

typedef struct		s_poslist
{
  struct s_poslist	*next;
  struct s_poslist	*prev;
  t_vec			pos;
}			t_poslist;

typedef struct	s_maze
{
  int		w;
  int		h;
  char		**grid;
  char		perfect;
}		t_maze;

char	gen_maze(t_maze *maze);

int		list_size(t_poslist *);
t_poslist	*get(t_poslist *, int);
char		add(t_poslist **, int, int);
t_vec		pop(t_poslist **, t_poslist *);
t_poslist	*delete(t_poslist **, t_poslist *);

void	display_maze(t_maze *);

int	gen_rand(int min, int max);

t_vec	v_add(t_vec, t_vec);
t_vec	v_set(t_vec *, int, int);
#endif /* !GEN_H_ */
