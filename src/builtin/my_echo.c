/*
** my_echo.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 16:53:37 2014 Nicolas Ades
** Last update Sat May 24 17:38:07 2014 Nicolas Ades
*/

#include "core.h"

void		print_cmd(char **cmd)
{
  int		i;

  i = 1;
  while (cmd[i] != NULL)
    {
      if (cmd[i][0] == '-' && i <= 3)
      printf("%s", cmd[i]);
      if (cmd[i] != NULL)
	my_putchar(' ');
      i++;
    }
  printf("\n");
}

int		echo_with_opt(int n, int e, char **cmd);
{
  if (e == 1)
    {}
  print_cmd(cmd);
  if (n == 0)
    printf("\n");
  return (0);
}

int		get_opt_e(char *s1, char *s2)
{
  if (s1[0] == '-' && (s1[1] == 'e' || s1[2] == 'e'))
    return (1);
  if (s2[0] == '-' && (s2[1] == 'e' || s2[2] == 'e'))
    return (1);
  return (0);
}

int		get_opt_n()
{
  if (s1[0] == '-' && (s1[1] == 'e' || s1[2] == 'e'))
    return (1);
  if (s2[0] == '-' && (s2[1] == 'e' || s2[2] == 'e'))
    return (1);
  return (0);
}

int		my_echo(t_shell *shell, char **cmd)
{
  int		i;
  int		op[1]

  i = 0;
  op[0] = get_opt_n();
  op[1] = get_opt_e();
  if (op[0] == 1 || op[1] == 1)
    {
      echo_with_opt(op[0], op[1], cmd);
      return (O);
    }
  print_cmd(cmd);
  return (0);
}
