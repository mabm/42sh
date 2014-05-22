/*
** manage_history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Fri May 23 00:09:13 2014 Geoffrey Merran
*/

#include "history.h"

int     add_cmd(t_history *history, char *name)
{
  char  *date;

  date = "00:00";
  if (history->head == NULL)
    {
      history->head = create_hlist(name, date);
      history->tail = history->head;
    }
  else
    add_tailh(history, name, date);
  history->size++;
  return (0);
}

int		save_history(t_history *history)
{
  int		fd;
  int		i;
  t_hlist	*tmp;

  if (history->tail == NULL)
    return (-1);
  fd = xopen(history->path, O_WRONLY | O_CREAT | O_TRUNC, 00600);
  i = -1;
  tmp = history->tail;
  while (tmp->prev != NULL && ++i < 1000)
    tmp = tmp->prev;
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	{
	  write(fd, tmp->name, strlen(tmp->name));
	  write(fd, "\n", 1);
	}
      tmp = tmp->next;
    }
  xclose(fd);
  return (0);
}

int	get_history(t_history *history)
{
  int	fd;
  char	*s;

  if (history->path == NULL)
    return (-1);
  if (access(history->path, F_OK) == -1)
    {
      fprintf(stderr, "42sh: can't access %s\n", history->path);
      return (-1);
    }
  if (access(history->path, R_OK) == -1)
    {
      fprintf(stderr,"42sh: can't read history file. Check your rights.\n");
      return (-1);
    }
  if ((fd = open(history->path, O_RDONLY)) == -1)
    return (-1);
  while ((s = get_next_line(fd)) != NULL)
    {
      add_cmd(history, s);
      free(s);
    }
  xclose(fd);
  return (0);
}
