/*
** elements.c for list in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 19:19:48 2017 Arthur Baurens
** Last update Fri May 12 19:28:33 2017 Arthur Baurens
*/

#include <unistd.h>
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

char	remove_elem(t_list *lst, t_elem_list *elem)
{
  if (elem == NULL || lst == NULL)
    return (0);
  if (lst->size <= 0)
    return (1);
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  if (elem == lst->head)
    lst->head = elem->next;
  free(elem->data);
  free(elem);
  lst->size--;
  return (0);
}
