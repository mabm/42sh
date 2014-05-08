/*
** main.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:26 2014 Jeremy Mediavilla
** Last update Thu May  8 16:10:06 2014 Jeremy Mediavilla
*/

#include "core.h"

int		main(int ac, char **av, char **env)
{
  t_list	*list;

  (void)ac;
  (void)av;
  list = create_list(NULL);
  get_all_env(list, env);
  /* printf("%i\n", is_in_env(list, "PWD=")); */
  /* printf("%s\n", check_env_var(list, "PWD=", 4)); */
  /* prompt(list); */
  return (0);
}
