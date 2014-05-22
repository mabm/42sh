/*
** manage_histor.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Thu May 22 06:52:43 2014 martelliere
*/

#include "aliasing.h"

void		display_alias(t_list *list)
{
  while (list != NULL)
    {
      printf("alias %s='%s'\n",
	     list->name,
	     list->content);
      list = list->next;
    }
}

char		*find_alias(t_list *list, char *name)
{
  if (name == NULL)
    {
      printf("Error on alias name. Try again.\n");
      return (NULL);
    }
  while (list != NULL)
    {
      if (list->name == NULL)
	return (NULL);
      if (strcmp(list->name, name) == 0)
	return (list->content);
      list = list->next;
    }
  return (NULL);
}

int		delete_alias(t_list *list, char *name)
{
  if (name == NULL)
    {
      printf("Error on alias name. Try again.\n");
      return (-1);
    }
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

int		write_alias(t_list *list, char *path)
{
  int		fd;

  fd = xopen(path, O_WRONLY | O_TRUNC | O_CREAT, 00644);
  while (list != NULL)
    {
      xwrite(fd, "alias ", 6);
      xwrite(fd, list->name, strlen(list->name));
      xwrite(fd, "='", 2);
      xwrite(fd, list->content, strlen(list->content));
      xwrite(fd, "'\n", 2);
      list = list->next;
    }
  return (0);
}
