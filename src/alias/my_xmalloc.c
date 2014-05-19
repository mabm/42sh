/*
** my_xmalloc.c for libmy in /home/martel_c/rendu/Piscine-C-lib/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Sat Oct 19 19:59:49 2013 martelliere
** Last update Mon May 12 16:31:33 2014 martelliere
*/

#include "aliasing.h"

void            *my_xmalloc(int size)
{
  void		*str;

  str = malloc(size);
  if (str == NULL)
    {
      printf("42sh: can't perform malloc.\n");
      return (NULL);
    }
  return (str);
}