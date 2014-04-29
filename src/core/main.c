/*
** main.c for  in /home/nicolas/Workspace/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:55 2014 Nicolas Ades
** Last update Tue Apr 29 09:54:40 2014 Nicolas Ades
*/

#include "main.h"

int	main(int ac, char **av, char **envp)
{
  t_env	*i_env;

  (void)ac;
  (void)av;
  if (check_env(envp, i_env) == -1)
    return (-1);
  if (prompt(i_env) == 0)
    return (O);
}
