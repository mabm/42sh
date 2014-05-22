/*
** manage_history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Thu May 22 08:23:59 2014 martelliere
*/

#include "history.h"

int     add_cmd(t_list *list, char *name)
{
  char  *date;

  date = "lol";
  if (list == NULL)
    create_list(name, date);
  else
    add_before(list, name, date);
}

int	delete_cmd(t_list *list, char *name)
{
  while (list != NULL)
    {
      if (list->name == NULL)
	return (-1);
      if (strcmp(list->name, name) == 0)
	{
	  remove_from_list(list);
	  return (0);
	}
      list = list->next;
    }
  return (-1);
}

int	save_history(t_list *list, char *path)
{
  int	fd;

  if (list == NULL)
    {
      printf("42sh: cannot find history to save.\n");
      return (-1);
    }
  fd = xopen(path, O_WRONLY | O_CREAT | O_APPEND, 00600);
  while (list != NULL)
    {
      if (list->name == NULL)
	return (-1);
      xwrite(fd, list->name, strlen(list->name));
      xwrite(fd, "\n", 1);
      list = list->next;
    }
  xclose(fd);
}

int	get_history(t_list *list, char *path)
{
  int	fd;
  char	*s;

  if (access(path, F_OK) == -1)
    {
      printf("42sh: no history file saved. Restarting an empty history.\n");
      return (-1);
    }
  if (access(path, R_OK) == -1)
    {
      printf("42sh: can't read history file. Check your rights/session.\n");
      return (-1);
    }
  fd = xopen(path, O_RDONLY);
  while ((s = get_next_line(fd)) != NULL)
    add_cmd(list, s);
  xclose(fd);
}
