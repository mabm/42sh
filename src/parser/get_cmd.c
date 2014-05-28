/*
** get_cmd.c for get_cmd in /home/merran_g/work/c_elem/42sh/src/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue May 27 21:59:27 2014 Geoffrey Merran
** Last update Wed May 28 01:49:00 2014 Joris Bertomeu
*/

#include "parser.h"

char		**get_cmd(t_link *start)
{
  char		**cmd;
  int		i;
  t_link	*tmp;

  tmp = start;
  i = 0;
  while (tmp && tmp->type == 0)
    {
      printf("Dedans get cmd : %s\n", tmp->data);
      i++;
      tmp = tmp->next;
    }
  if (i == 0)
    return (NULL);
  cmd = my_xmalloc((i + 1) * sizeof(char *));
  tmp = start;
  i = 0;
  while (tmp && tmp->type == 0)
    {
      cmd[i++] = strdup(tmp->data);
      tmp = tmp->next;
    }
  cmd[i] = NULL;
  return (cmd);
}
