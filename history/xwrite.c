/*
** xwrite.c for xwrite in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Sun Dec  1 01:39:05 2013 martelliere
** Last update Mon May 12 14:17:57 2014 martelliere
*/

#include "history.h"

int	xwrite(int fd, void *buf, int nbytes)
{
  int	nb;

  if ((nb = write(fd, buf, nbytes)) == -1)
    printf("42sh: can't write in this file.\n");
  return (nb);
}