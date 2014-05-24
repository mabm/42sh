/*
** char2.c for char2 in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 18:29:02 2014 Geoffrey Merran
** Last update Sat May 24 06:50:00 2014 Geoffrey Merran
*/

#include "line_editor.h"

int	delete_lastchar(t_char *c, t_line **line)
{
  (*line)->head = NULL;
  (*line)->tail = NULL;
  (*line)->current = NULL;
  (*line)->size = 0;
  free(c);
  return (0);
}

int	delete_char(t_char *c, t_line **line)
{
  if (c == NULL)
    return (0);
  if (c == (*line)->head && c == (*line)->tail)
    return (delete_lastchar(c, line));
  if (c == (*line)->current)
    {
      c->cursor = 0;
      if (c->next != NULL)
	{
	  c->next->cursor = 1;
	  (*line)->current = c->next;
	}
    }
  if (c == (*line)->head)
    (*line)->head = c->next;
  else
    c->prev->next = c->next;
  if (c == (*line)->tail)
    (*line)->tail = c->prev;
  else
    c->next->prev = c->prev;
  free(c);
  (*line)->size--;
  return (0);
}
