/*
** redirection.c for  in /home/nicolas/Workspace/Unix/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 00:53:42 2014 Nicolas Ades
** Last update Sat May 24 03:14:34 2014 Nicolas Ades
*/

#include "core.h"

int		simple_right(char *exec, char *file)
{
  int		fd;

  if (fd = xopen(file, O_CREAT) == -1)
    return (-1);
  return (0);
}
