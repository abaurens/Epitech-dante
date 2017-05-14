/*
** instancier.c for list in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_list/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu May 11 19:04:35 2017 Arthur Baurens
** Last update Sun May 14 15:07:08 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_list.h"

t_list		init_list()
{
  t_list	ret;

  ret.size = 0;
  ret.head = NULL;
  ret.tail = NULL;
  return (ret);
}

char	clear_list(t_list *lst)
{
  while (lst->size)
    {
      remove_elem(lst, lst->head->data);
    }
  return (0);
}
