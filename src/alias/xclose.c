/*
** xclose.c for xclose in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Sun Dec  1 01:39:05 2013 martelliere
** Last update Mon May 12 16:31:13 2014 martelliere
*/

#include "aliasing.h"

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      printf("42sh: couldn't close this file.\n");
      return ;
    }
}