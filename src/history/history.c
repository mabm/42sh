/*
** history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:49:56 2014 martelliere
** Last update Sat May 24 06:47:47 2014 Geoffrey Merran
*/

#include "history.h"

char    *get_user_path()
{
  char  *user;
  char  *path;

  if ((user = getenv("USER")) == NULL)
    {
      fprintf(stderr, "42sh: history: can't get username to access history.\n");
      return (NULL);
    }
  path = my_alloc_init((22 + strlen(user)) * sizeof(char), 0);
  if (path == NULL)
    return (NULL);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".bash_history");
  return (path);
}

void		show_history(t_history *history)
{
  t_hlist	*tmp;
  int		i;

  tmp = history->head;
  i = 1;
  while (tmp)
    {
      printf("%d %s\n", i, tmp->name);
      i++;
      tmp = tmp->next;
    }
}

t_history	*init_history(t_shell *shell)
{
  t_history	*history;

  history = my_xmalloc(sizeof(*history));
  if ((history->path = get_user_path()) == NULL)
    return (NULL);
  history->head = NULL;
  history->current = NULL;
  history->tail = NULL;
  history->size = 0;
  get_history(history, shell);
  return (history);
}
