/*
** vectors.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 12:14:57 2017 Arthur Baurens
** Last update Fri Apr 28 12:25:27 2017 Arthur Baurens
*/

#include <unistd.h>
#include "gen.h"

t_vec	v_set(t_vec *v, int x, int y)
{
  t_vec	buf;

  buf.x = x;
  buf.y = y;
  if (v != NULL)
    *v = buf;
  return (buf);
}

t_vec	v_add(t_vec v1, t_vec v2)
{
  v1.x += v2.x;
  v1.y += v2.y;
  return (v1);
}
