/*
** my_xmalloc.c for libmy in /home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Sat Oct 19 19:59:49 2013 martelliere
** Last update Fri May  9 21:59:00 2014 martelliere
*/

#include "history.h"

void            *my_xmalloc(int size)
{
  void		*str;

  str = malloc(size);
  if (str == NULL)
    {
      printf("42sh: history: Can't perform malloc.\n");
      return (NULL);
    }
  return (str);
}
