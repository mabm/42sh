/*
** my_echo.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 16:53:37 2014 Nicolas Ades
** Last update Wed May 28 04:52:36 2014 Geoffrey Merran
*/

#include "core.h"

void		print_cmd(char **cmd)
{
  int		i;

  i = go_to_arg(cmd);
  while (cmd[i] != NULL)
    {
      printf("%s", cmd[i]);
      if (cmd[i] != NULL)
	my_putchar(' ');
      i++;
    }
  printf("\n");
}

int		echo_with_opt(int n, int e, char **cmd)
{
  int		i;

  i = go_to_arg(cmd);
  if (e == 1)
    if (print_with_opt(i, cmd) == -1)
      return (-1);
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

int		get_opt_n(char *s1, char *s2)
{
  if (s1[0] == '-' && (s1[1] == 'n' || s1[2] == 'n'))
    return (1);
  if (s2[0] == '-' && (s2[1] == 'n' || s2[2] == 'n'))
    return (1);
  return (0);
}

int		my_echo(t_shell *shell, char **cmd)
{
  int		op[1];

  (void)shell;
  op[0] = get_opt_n(cmd[1], cmd[2]);
  op[1] = get_opt_e(cmd[1], cmd[2]);
  if (op[0] == 1 || op[1] == 1)
    {
      if (echo_with_opt(op[0], op[1], cmd) == -1)
	return (-1);
      return (0);
    }
  print_cmd(cmd);
  return (0);
}
