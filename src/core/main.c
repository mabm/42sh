/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:26 2014 Jeremy Mediavilla
** Last update Sat May 24 05:39:56 2014 Geoffrey Merran
*/

#include "core.h"

int		loading_shell(t_shell **shell, char **env)
{
  *shell = my_xmalloc(sizeof(**shell));
  (*shell)->env = create_list(NULL);
  get_all_env((*shell)->env, env);
  (*shell)->online = online_mode();
  (*shell)->history = init_history(*shell);
  (*shell)->alias = init_aliasing(*shell);
  (*shell)->prompt = 1;
  return (xtgetent(NULL, "xterm"));
}

int		main(int ac, char **av, char **env)
{
  t_shell	*shell;

  (void) ac;
  (void) av;
  if (loading_shell(&shell, env) == -1)
    return (EXIT_FAILURE);
  if (prompt(shell) == -1)
    return (EXIT_FAILURE);
  save_history(shell->history, shell);
  if (shell->online->active == 1)
    modify_active(shell->online->pseudo, "0");
  free_shell(shell);
  return (EXIT_SUCCESS);
}
