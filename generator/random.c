/*
** random.c for gen in /home/baurens/Work/Tek1/Projects/IA/dante/generator/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Apr 28 10:31:37 2017 Arthur Baurens
** Last update Fri Apr 28 11:04:46 2017 Arthur Baurens
*/

#include <stdlib.h>

int		gen_rand(int min, int max)
{
  double	rd;


  rd = rand();
  rd /= (RAND_MAX + 1.0);
  rd *= (max - min);
  rd += min;
  return (rd);
}
