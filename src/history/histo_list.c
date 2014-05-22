/*
** list.c for  in /home/mediav_j/piscine/eval_expr
**
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
**
** Started on  Fri Oct 25 13:42:22 2013 Jeremy Mediavilla
** Last update Thu May 22 14:44:07 2014 Geoffrey Merran
*/

#include "history.h"

t_hlist		*create_hlist(char *name, char *date)
{
  t_hlist	*list;

  list = my_xmalloc(sizeof(*list));
  list->next = NULL;
  list->prev = NULL;
  list->name = my_alloc_init((strlen(name) + 1) * sizeof(char), 0);
  list->name = strcat(list->name, name);
  list->date = my_alloc_init((strlen(date) + 1) * sizeof(char), 0);
  list->date = strcat(list->date, date);
  return (list);
}

void		add_afterh(t_hlist *list, char *name, char *date)
{
  t_hlist	*ptr;

  ptr = create_hlist(name, date);
  if (list->next != NULL)
    {
      ptr->next = list->next;
      list->next->prev = ptr;
    }
  list->next = ptr;
  ptr->prev = list;
}

void		add_beforeh(t_hlist *list, char *name, char *date)
{
  t_hlist	*ptr;

  ptr = create_hlist(name, date);
  if (list->prev != NULL)
    {
      ptr->prev = list->prev;
      list->prev->next = ptr;
    }
  list->prev = ptr;
  ptr->next = list;
}

void		remove_from_hlist(t_hlist *list)
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

void		add_to_endh(t_hlist *list, char *name, char *date)
{
  while (list->next != NULL)
    list = list->next;
  add_afterh(list, name, date);
}
