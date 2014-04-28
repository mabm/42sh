/*
** prompt.c for  in /home/nicolas/Workspace/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:56:09 2014 Nicolas Ades
** Last update Mon Apr 28 15:08:26 2014 Nicolas Ades
*/

#include "core.h"

int	prompt()
{
  char	cmd;

  while (cmd = get_next_line(0))
    {
      if (strcmp(cmd, "exit") == 1)
	return (O);
      parser(cmd);
    }
}
