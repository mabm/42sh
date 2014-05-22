/*
** history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:49:56 2014 martelliere
** Last update Thu May 22 08:22:48 2014 martelliere
*/

#include "history.h"

char    *get_user_path()
{
  char  *user;
  char  *path;

  if ((user = getenv("USER")) == NULL)
    {
      printf("42sh: can't get username to access history.\n");
      return (NULL);
    }
  path = my_alloc_init((22 + strlen(user)) * sizeof(char), 0);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".mabmm_history");
  return (path);
}

void		history()
{
  t_list	*list;
  char		*path;

  path = get_user_path();
  get_history(list, path);
  save_history(list, path);
}
