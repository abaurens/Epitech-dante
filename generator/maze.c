/*
** maze.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 09:29:42 2017 Arthur Baurens
** Last update Sun May 14 18:44:05 2017 Arthur Baurens
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "gen.h"

static char	**alloc_tab(int w, int h)
{
  int		i;
  char		**res;

  i = -1;
  if ((res = malloc(sizeof(char *) * (h + 1))) == NULL)
    return (NULL);
  res[h] = NULL;
  while (++i < h)
    {
      if ((res[i] = malloc(sizeof(char) * (w + 1))) == NULL)
	{
	  while (--i >= 0)
	    free(res[i]);
	  free(res);
	  return (NULL);
	}
      memset(res[i], WALL, w);
      res[i][w] = '\0';
    }
  return (res);
}

t_vec		chose_dir(t_vec pos, t_maze *maze)
{
  t_vec		fpos;
  t_poslist	*di;
  t_poslist	*tmp;

  di = NULL;
  memset(&fpos, 0, sizeof(fpos));
  if (add(&di, 2, 0) || add(&di, 0, 2) || add(&di, -2, 0) || add(&di, 0, -2))
    return (fpos);
  tmp = di;
  while (tmp != NULL)
    {
      fpos = v_add(pos, tmp->pos);
      if (fpos.x < 0 || fpos.x >= maze->w || fpos.y < 0 || fpos.y >= maze->h ||
	  maze->grid[fpos.y][fpos.x] == PATH)
	tmp = delete(&di, tmp);
      else
	tmp = tmp->next;
    }
  tmp = get(di, gen_rand(0, list_size(di)));
  memset(&fpos, 0, sizeof(fpos));
  fpos = (tmp == NULL ? fpos : tmp->pos);
  while (di != NULL)
    delete(&di, di);
  return (fpos);
}

static char	generate(t_maze *maze)
{
  t_vec		dir;
  t_vec		pos;
  t_vec		tmp;
  t_poslist	*list;

  list = NULL;
  pos = v_set(NULL, 0, 0);
  if ((maze->grid = alloc_tab(maze->w, maze->h)) == NULL)
    return (1);
  add(&list, pos.x, pos.y);
  while (list != NULL)
    {
      if ((dir = chose_dir(pos, maze)).x == 0 && dir.y == 0)
	pos = pop(&list, list);
      else
	{
	  maze->grid[pos.y][pos.x] = PATH;
	  maze->grid[pos.y + dir.y][pos.x + dir.x] = PATH;
	  maze->grid[pos.y + dir.y / 2][pos.x + dir.x / 2] = PATH;
	  if ((tmp = chose_dir(pos, maze)).x != 0 || tmp.y != 0)
	    add(&list, pos.x, pos.y);
	  pos = v_add(pos, dir);
	}
    }
  return (0);
}

char	gen_maze(t_maze *maze)
{
  int	x;
  int	y;
  char	ret;

  y = -1;
  ret = generate(maze);
  while (!maze->perfect && ++y < maze->h)
    {
      x = -1;
      while (++x < maze->w)
	{
	  if ((x + y) % 2 == 1 && rand() % 5 == 0)
	    maze->grid[y][x] = PATH;
	}
    }
  maze->grid[0][0] = PATH;
  maze->grid[maze->h - 1][maze->w - 1] = PATH;
  if (maze->w % 2 == 0 && maze->h % 2 == 0)
    maze->grid[maze->h - 1][maze->w - 2] = PATH;
  display_maze(maze);
  return (ret);
}
