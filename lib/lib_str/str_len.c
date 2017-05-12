/*
** str_len.c for str in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_str/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri May 12 15:12:05 2017 Arthur Baurens
** Last update Fri May 12 17:05:11 2017 Arthur Baurens
*/

int	str_len(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
