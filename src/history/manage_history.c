/*
** manage_history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Thu May 22 15:20:03 2014 Geoffrey Merran
*/

#include "history.h"

int     add_cmd(t_hlist *list, char *name)
{
  char  *date;

  date = "lol";
  if (list == NULL)
    create_hlist(name, date);
  else
    add_beforeh(list, name, date);
  return (0);
}

int	delete_cmd(t_hlist *list, char *name)
{
  while (list != NULL)
    {
      if (list->name == NULL)
	return (-1);
      if (strcmp(list->name, name) == 0)
	{
	  remove_from_hlist(list);
	  return (0);
	}
      list = list->next;
    }
  return (-1);
}

int	save_history(t_hlist *list, char *path)
{
  int	fd;
  int	i;

  if (list == NULL)
    return (-1);
  fd = xopen(path, O_WRONLY | O_CREAT | O_TRUNC, 00600);
  i = 0;
  while (list != NULL && i < 1000)
    {
      if (list->name == NULL)
	return (-1);
      write(fd, list->name, strlen(list->name));
      write(fd, "\n", 1);
      list = list->next;
    }
  xclose(fd);
  return (0);
}

int	get_history(t_hlist *list, char *path)
{
  int	fd;
  char	*s;

  if (access(path, F_OK) == -1)
    return (-1);
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr,
	      "42sh: can't read history file. Check your rights/session.\n");
      return (-1);
    }
  if ((fd = open(path, O_RDONLY)) == -1)
    return (-1);
  while ((s = get_next_line(fd)) != NULL)
    add_cmd(list, s);
  xclose(fd);
  return (0);
}
