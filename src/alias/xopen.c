/*
** xopen.c for xopen in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Wed Dec  5 04:36:08 2012 martelliere
** Last update Mon May 12 16:31:48 2014 martelliere
*/

#include "aliasing.h"

int	xopen(const char *path, int flags, mode_t mode)
{
  int	ret;

  if ((ret = open(path, flags, mode)) == -1)
    {
      printf("42sh: %s can't be opened.\n", path);
      return (-1);
    }
  return (ret);
}
