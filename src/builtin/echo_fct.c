/*
** echo_fct.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 17:58:13 2014 Nicolas Ades
** Last update Mon May 26 18:41:18 2014 Nicolas Ades
*/

#include "core.h"

int		do_echo_with_e(char **cmd)
{
  int		i;

  i = go_to_arg(cmd);
  while (cmd[i] != NULL)
    i++;
  return (0);
}
