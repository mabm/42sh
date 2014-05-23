/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:26 2014 Jeremy Mediavilla
** Last update Wed May 21 16:54:25 2014 Joris Bertomeu
*/

#include "core.h"

int		loading_terminal()
{
  return (xtgetent(NULL, "xterm"));
}

int		main(int ac, char **av, char **env)
{
  t_list	*list;
  int		online;

  (void) ac;
  (void) av;
  online = online_mode();
  if (loading_terminal() == -1)
    return (EXIT_FAILURE);
  list = create_list(NULL);
  get_all_env(list, env);
  if (prompt(list, online) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
