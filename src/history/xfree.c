/*
** xfree.c for libmy in /home/martel_c/rendu/CPE_2014_corewar/my
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri Apr  4 14:11:56 2014 martelliere
** Last update Fri May  9 21:45:08 2014 martelliere
*/

#include "history.h"

void	xfree(char *s)
{
  if (s == NULL)
    {
      printf("42sh: history: %s doesn't exist. Can't free it.\n", s);
      return ;
    }
  free(s);
}
