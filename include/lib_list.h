/*
** lib_list.h for list in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 19:20:43 2017 Arthur Baurens
** Last update Fri May 12 19:26:59 2017 Arthur Baurens
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
char	remove_elem(t_list *, t_elem_list *);
char	add_elem(t_list *, void *);

#endif /* !LIB_LIST_H_ */
