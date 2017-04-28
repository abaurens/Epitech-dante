/*
** list.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 10:02:46 2017 Arthur Baurens
** Last update Fri Apr 28 12:13:52 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "gen.h"

int	list_size(t_poslist *list)
{
  int	i;

  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}

t_poslist	*get(t_poslist *list, int i)
{
  if (list == NULL || i >= list_size(list))
    return (NULL);
  while (list != NULL && i > 0)
    {
      i--;
      list = list->next;
    }
  return (list);
}

char		add(t_poslist **list, int x, int y)
{
  t_poslist	*elem;

  if ((elem = malloc(sizeof(t_poslist))) == NULL)
    return (1);
  elem->pos.x = x;
  elem->pos.y = y;
  elem->prev = NULL;
  elem->next = *list;
  if (elem->next != NULL)
    elem->next->prev = elem;
  *list = elem;
  return (0);
}

t_poslist	*delete(t_poslist **list, t_poslist *elem)
{
  t_poslist	*next;

  next = elem->next;
  if (elem == *list)
    *list = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  free(elem);
  return (next);
}

t_vec	pop(t_poslist **list, t_poslist *elem)
{
  t_vec	pos;

  pos = elem->pos;
  if (elem == *list)
    *list = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  free(elem);
  return (pos);
}
