/*
** echo_fct.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 17:58:13 2014 Nicolas Ades
** Last update Wed May 28 04:55:39 2014 Geoffrey Merran
*/

#include "core.h"

int		print_with_opt(int i, char **cmd)
{
  int		k;
  int		j;
  char		*pr;

  k = 0;
  while (cmd[k] != NULL)
    {
      j = 0;
      while (cmd[k][j] != '\0')
	{
	  if (cmd[k][j] == '\\' && cmd[k][j + 2] == ' ')
	    {
	      if ((pr = my_xmalloc(4 * sizeof(*pr))) == NULL)
		return (-1);
	      memset(pr, 0, 4);
	      pr = strncpy(pr, &cmd[k][j], 1);
	      my_putstr(pr);
	      j += 2;
	    }
	  else
	    my_putchar(cmd[k][j]);
	  j++;
	}
      k++;
    }
  return (0);
}

int		go_to_arg(char **cmd)
{
  int		i;

  while (cmd[i] != NULL)
    {
      if (cmd[i][0] == '-' && (cmd[i][1] == 'e' || cmd[i][1] == 'n'))
	i++;
      else
	return (i);
    }
  return (1);
}
