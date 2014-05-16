/*
** parser_line_editor.c for parser_line_editor in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 18:05:01 2014 Geoffrey Merran
** Last update Thu May 15 19:39:55 2014 Geoffrey Merran
*/

#include "line_editor.h"

void	move_cursor(int direction, t_line **line)
{
  if (direction == RIGHT)
    {
      if ((*line)->current->next != NULL)
	{
	  (*line)->current->cursor = 0;
	  (*line)->current = (*line)->current->next;
	  (*line)->current->cursor = 1;
	}
    }
  else
    {
      if ((*line)->current->prev != NULL)
	{
	  (*line)->current->cursor = 0;
	  (*line)->current = (*line)->current->prev;
	  (*line)->current->cursor = 1;
	}
    }
}

int	parse_arrow(char *buffer, t_line **line, int size)
{
  if (size == 3)
    {
      if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'C')
	move_cursor(RIGHT, line);
      else if (buffer[0] == 27 && buffer[1] == '[' && buffer[2] == 'D')
	move_cursor(LEFT, line);
    }
  return (0);
}

void	parse_delete(char *buffer, t_line **line, int size)
{
  if (size == 1 && buffer[0] == 127)
    {
      if ((*line)->current->prev != NULL && (*line)->current->prev->c != '\0')
        delete_char((*line)->current->prev, line);
    }
  if (size == 4 && buffer[0] == 27 && buffer[1] == '['
      && buffer[2] == '3' && buffer[3] == '~')
    {
      if ((*line)->current != NULL && (*line)->current->c != '\0')
        delete_char((*line)->current, line);
    }
}

int	parser_line_editor(char *buffer, t_line **line)
{
  int	size;

  size = strlen(buffer);
  if (my_isprintable(buffer[0]) && size == 1)
    return (add_char(buffer[0], line));
  if (parse_arrow(buffer, line, size) == -1)
    return (-1);
  parse_delete(buffer, line, size);
  return (0);
}
