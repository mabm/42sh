/*
** xclose.c for xclose in /home/martel_c/rendu/Piscine-C-lib/my/
**
** Made by martelliere
** Login   <martel_c@pc-martel_c>
**
** Started on  Sun Dec  1 01:39:05 2013 martelliere
** Last update Fri May  9 21:40:24 2014 martelliere
*/

#include "history.h"

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      printf("42sh: history: couldn't close this file.\n");
      return ;
    }
}
