/*
** lib_list.h for list in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 19:20:43 2017 Arthur Baurens
** Last update Sat May 13 21:14:01 2017 Arthur Baurens
*/

#ifndef LIB_LIST_H_
# define LIB_LIST_H_

typedef struct		s_elem_list
{
  struct s_elem_list	*next;
  struct s_elem_list	*prev;
  void			*data;
}			t_elem_list;

typedef struct		s_list
{
  int			size;
  struct s_elem_list	*head;
  struct s_elem_list	*tail;
}			t_list;
/*
** instancier.c
*/
t_list	init_list();
char	clear_list(t_list *);

/*
** elements.c
*/
void	*get_elem(t_list *lst, void *sch, void *);
char	remove_elem(t_list *, void *);
char	add_elem(t_list *, void *);
void	display_list(t_list *lst);

#endif /* !LIB_LIST_H_ */
