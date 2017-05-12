/*
** my_strncat.c for str in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_str/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri May 12 15:09:12 2017 Arthur Baurens
** Last update Fri May 12 17:19:39 2017 Arthur Baurens
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib_str.h"

char	*my_strncat(const char *s1, const char *s2, int n)
{
  char	*ret;
  int	len;
  int	i;
  int	j;

  i = 0;
  j = -1;
  len = str_len(s1) + str_len(s2);
  if (len > n && n > 0)
    len = n;
  if (len <= 0 || (ret = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  ret[len] = '\0';
  while (s1 && s1[i] && i < len)
    {
      ret[i] = s1[i];
      i++;
    }
  while (s2 && s2[++j] && i + j < len)
    ret[i + j] = s2[j];
  return (ret);
}
