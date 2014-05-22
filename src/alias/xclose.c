/*
** xclose.c for xclose in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Sun Dec  1 01:39:05 2013 martelliere
** Last update Thu May 22 06:12:53 2014 martelliere
*/

#include "aliasing.h"

int	xclose(int fd)
{
  if (close(fd) == -1)
    {
      printf("42sh: couldn't close this file.\n");
      return (-1);
    }
  return (0);
}
