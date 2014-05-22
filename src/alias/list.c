/*
** list.c for  in /home/mediav_j/piscine/eval_expr
**
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
**
** Started on  Fri Oct 25 13:42:22 2013 Jeremy Mediavilla
** Last update Thu May 22 07:22:32 2014 martelliere
*/

#include "aliasing.h"

t_list		*create_list(char *name, char *content)
{
  t_list	*list;

  list = my_xmalloc(sizeof(*list));
  list->next = NULL;
  list->prev = NULL;
  list->name = my_alloc_init((strlen(name) + 1) * sizeof(char), 0);
  list->name = strcat(list->name, name);
  list->content = my_alloc_init((strlen(content) + 1) * sizeof(char), 0);
  list->content = strcat(list->content, content);
  return (list);
}

void		add_after(t_list *list, char *name, char *content)
{
  t_list	*ptr;

  ptr = create_list(name, content);
  if (list->next != NULL)
    {
      ptr->next = list->next;
      list->next->prev = ptr;
    }
  list->next = ptr;
  ptr->prev = list;
}

void		add_before(t_list *list, char *name, char *content)
{
  t_list	*ptr;

  ptr = create_list(name, content);
  if (list->prev != NULL)
    {
      ptr->prev = list->prev;
      list->prev->next = ptr;
    }
  list->prev = ptr;
  ptr->next = list;
}

void		remove_from_list(t_list *list)
{
  if (!(list->prev == NULL && list->next == NULL))
    {
      if (list->prev != NULL)
	list->prev->next = list->next;
      else
	list->next->prev = NULL;
      if (list->next != NULL)
	list->next->prev = list->prev;
      else
	list->prev->next = NULL;
    }
  if (list != NULL)
    free(list);
}

void		add_to_end(t_list *list, char *name, char *content)
{
  while (list->next != NULL)
    list = list->next;
  add_after(list, name, content);
}