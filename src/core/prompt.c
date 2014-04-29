/*
** prompt.c for  in /home/nicolas/Workspace/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:56:09 2014 Nicolas Ades
** Last update Tue Apr 29 09:55:40 2014 Nicolas Ades
*/

#include "core.h"

int	prompt(t_env *i_env)
{
  char	cmd;

  while (cmd = get_next_line(0))
    {
      my_putstr("42sh--> ");
      if (strcmp(cmd, "exit") == 1)
	return (O);
      parser(cmd);
    }
}
