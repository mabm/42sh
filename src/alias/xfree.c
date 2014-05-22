/*
** xfree.c for libmy in /home/martel_c/rendu/CPE_2014_corewar/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri Apr  4 14:11:56 2014 martelliere
** Last update Thu May 22 06:15:52 2014 martelliere
*/

#include "aliasing.h"

int	xfree(void *s)
{
  if (s == NULL)
    {
      printf("42sh: Error on free.\n");
      return (-1);
    }
  free(s);
  return (0);
}
