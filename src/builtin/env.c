/*
** env.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:45:44 2014 Jeremy Mediavilla
** Last update Wed May  7 18:11:07 2014 Jeremy Mediavilla
*/

#include "core.h"

void		aff_env(t_list *list)
{
  while (list != NULL)
    {
      if (list->data != NULL)
	printf("%s\n", list->data);
      list = list->next;
    }
}

void		get_all_env(t_list *list, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      add_to_end(list, env[i]);
      i++;
    }
}
