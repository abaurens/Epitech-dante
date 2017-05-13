/*
** elements.c for list in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 19:19:48 2017 Arthur Baurens
** Last update Sat May 13 22:16:28 2017 Arthur Baurens
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "lib_str.h"
#include "lib_list.h"

char	add_elem(t_list *lst, void *data)
{
  t_elem_list	*elem;

  if (lst == NULL || data == NULL)
    return (1);
  elem = NULL;
  if (!(elem = malloc(sizeof(t_elem_list))))
    {
      free(elem);
      return (1);
    }
  elem->data = data;
  elem->next = NULL;
  elem->prev = lst->tail;
  if (lst->size > 0)
    lst->tail->next = elem;
  else
    lst->head = elem;
  lst->tail = elem;
  lst->size++;
  return (0);
}

void		*get_elem(t_list *lst, void *sch, void *fct)
{
  t_elem_list	*e;
  char		(*cmp)(void *, void *);

  cmp = fct;
  e = lst->head;
  if (cmp == NULL)
   return (NULL);
  while (e != NULL)
    {
      if (cmp(e->data, sch))
	return (e->data);
      e = e->next;
    }
  return (NULL);
}

char		remove_elem(t_list *lst, void *elem)
{
  t_elem_list	*tmp;

  if (elem == NULL || lst == NULL)
    return (0);
  tmp = lst->head;
  while (tmp != NULL && tmp->data != elem)
    tmp = tmp->next;
  if (lst->size <= 0 || tmp == NULL)
    return (1);
  if (tmp->next != NULL)
    tmp->next->prev = tmp->prev;
  if (tmp->prev != NULL)
    tmp->prev->next = tmp->next;
  if (tmp == lst->head)
    lst->head = tmp->next;
  if (tmp == lst->tail)
    lst->tail = tmp->prev;
  free(tmp);
  lst->size--;
  return (0);
}
