/*
** my_echo.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 16:53:37 2014 Nicolas Ades
** Last update Sat May 24 17:07:11 2014 Nicolas Ades
*/

#include "core.h"

void		print_cmd(char **cmd)
{
  int		i;

  i = 1;
  while (cmd[i] != NULL)
    {
      printf("%s", cmd[i]);
      if (cmd[i] != NULL)
	my_putchar(' ');
      i++;
    }
  printf("\n");
}

int		echo_with_opt();

int		get_opt_e()
{
  return (0);
}

int		get_opt_n()
{
  return (0);
}

int		my_echo(t_shell *shell, char **cmd)
{
  int		i;
  int		*op;

  i = 0;
  op[0] = get_opt_n();
  op[1] = get_opt_e();
  if (op[0] == 1 || op[1] == 1)
    {
      echo_with_opt();
      return (O);
    }
  print_cmd(cmd);
  return (0);
}
