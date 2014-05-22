/*
** history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:49:56 2014 martelliere
** Last update Thu May 22 15:22:05 2014 Geoffrey Merran
*/

#include "history.h"

char    *get_user_path()
{
  char  *user;
  char  *path;

  if ((user = getenv("USER")) == NULL)
    {
      fprintf(stderr, "42sh: can't get username to access history.\n");
      return (NULL);
    }
  path = my_alloc_init((22 + strlen(user)) * sizeof(char), 0);
  if (path == NULL)
    return (NULL);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".mabmm_history");
  return (path);
}

t_history      *init_history()
{
  t_history	*history;

  history = my_xmalloc(sizeof(*history));
  if ((history->path = get_user_path()) == NULL)
    return (NULL);
  get_history(history->list, history->path);
  history->current = NULL;
  return (history);
}
