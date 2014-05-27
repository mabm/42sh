/*
** my_exit.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon May 26 07:11:03 2014 Nicolas Ades
** Last update Mon May 26 07:13:23 2014 Nicolas Ades
*/

#include "core.h"

int		my_exit(t_shell *shell, char **cmd)
{
  int		val;

  val = my_getnbr(cmd[1]);
  shell->end = 1;
  return (val);
}
