/*
** vec.c for maze in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_maze/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Jun  1 11:24:44 2017 Arthur Baurens
** Last update Thu Jun  1 11:32:46 2017 Arthur Baurens
*/

#include "lib_list.h"
#include "lib_maze.h"

t_vec		vadd(t_vec v1, t_vec v2)
{
	t_vec	r;

	r.x = v1.x + v2.x;
	r.y = v1.y + v2.y;
	return (r);
}

char		in_bound(t_vec v, int max_x, int max_y)
{
	return (v.x >= 0 && v.y >= 0 && v.x < max_x && v.y < max_y);
}

char		in_bound_v(t_vec v, t_vec min, t_vec max)
{
	return (v.x >= min.x && v.y >= min.y && v.x < max.x && v.y < max.y);
}
