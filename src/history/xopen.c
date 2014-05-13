/*
** xopen.c for xopen in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Wed Dec  5 04:36:08 2012 martelliere
** Last update Fri May  9 21:56:48 2014 martelliere
*/

#include "history.h"

int	xopen(const char *path, int flags, mode_t mode)
{
  int	ret;

  if ((ret = open(path, flags, mode)) == -1)
    {
      printf("42sh: history: %s can't be opened.\n", path);
      return (-1);
    }
  return (ret);
}
