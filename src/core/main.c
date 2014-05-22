/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:26 2014 Jeremy Mediavilla
** Last update Thu May 22 13:07:55 2014 Geoffrey Merran
*/

#include "core.h"

int		loading_shell(t_shell **shell)
{
  *shell = my_xmalloc(sizeof(**shell));
  (*shell)->prompt = 1;
  return (xtgetent(NULL, "xterm"));
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;

  (void) ac;
  (void) av;
  if (loading_shell(&shell) == -1)
    return (EXIT_FAILURE);
  get_all_env(list, env);
  if (prompt(list) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
