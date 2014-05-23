/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:26 2014 Jeremy Mediavilla
** Last update Fri May 23 14:15:18 2014 Joris Bertomeu
*/

#include "core.h"

int		loading_shell(t_shell **shell, char **env)
{
  *shell = my_xmalloc(sizeof(**shell));
  (*shell)->env = create_list(NULL);
  get_all_env((*shell)->env, env);
  (*shell)->online = online_mode();
  (*shell)->history = init_history(*shell);
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
  save_history(shell->history);
  free_shell(shell);
  return (EXIT_SUCCESS);
}
