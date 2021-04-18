/*
** lib_str.h for str in /home/baurens/Work/Tek1/Projects/IA/dante/lib/lib_str/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri May 12 15:10:16 2017 Arthur Baurens
** Last update Fri May 12 16:15:00 2017 Arthur Baurens
*/

#ifndef LIB_STR_H_
# define LIB_STR_H_
# define READ_SIZE (5)

int		str_len(const char *);
char	*get_next_line(const int fd);
char	*my_strncat(const char *, const char *, int);

#endif /* !LIB_STR_H_ */
