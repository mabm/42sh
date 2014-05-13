/*
** manage_history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Mon May 12 16:40:05 2014 martelliere
*/

#include "aliasing.h"

t_aliasl	*init_aliasing(t_aliasl *alias)
{
  alias = my_xmalloc(sizeof(t_aliasl));
  alias->first = NULL;
  return (alias);
}

void		add_alias(t_aliasl *alias, char *name, char *content)
{
  t_alias	*new;
  t_alias	*tmp;

  if (alias == NULL || name == NULL || content == NULL)
    return ;
  new = my_xmalloc(sizeof(t_alias));
  new->name = my_alloc_init((strlen(name) + 1) * sizeof(char), 0);
  new->content = my_alloc_init((strlen(content) + 1) * sizeof(char), 0);
  new->name = strcat(new->name, name);
  new->content = strcat(new->content, content);
  if (alias->first == NULL)
    {
      new->next = NULL;
      alias->first = new;
    }
  else
    {
      tmp = alias->first;
      new->next = tmp;
      alias->first = new;
    }
}

char		*find_alias(t_aliasl *alias, char *name)
{
  char		*content;
  t_alias	*tmp;

  tmp = alias->first;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, name) == 0)
	return (tmp->content);
      tmp = tmp->next;
    }
  return (NULL);
}

void		display_alias(t_aliasl *alias)
{
  t_alias	*tmp;

  tmp = alias->first;
  while (tmp != NULL)
    {
      printf("Name: %s\nContent:%s\n", tmp->name, tmp->content);
      tmp = tmp->next;
    }
}
