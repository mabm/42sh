/*
** prompt.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:48:19 2014 Jeremy Mediavilla
** Last update Thu May  8 14:42:58 2014 Nicolas Ades
*/

#include "core.h"
#include "gnl.h"

int		prompt(t_list *env)
{
  char		*cmd;

  my_putstr("\033[1;31mMABM[42sh] : \033[1;00m");
  cmd = get_next_line(0);
  if (strcmp(cmd, "exit") == 0)
    return (0);
  /* fonction parsing et edition de ligne */
  prompt(env);
  return (0);
}
