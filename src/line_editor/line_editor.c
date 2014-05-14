/*
** line_editor.c for main in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:13:23 2014 Geoffrey Merran
** Last update Wed May 14 18:13:47 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "line_editor.h"

int	init_term(struct termios *t, struct termios *t_save)
{
  if (xtcgetattr(0, t) == -1)
    return (-1);
  if (xtcgetattr(0, t_save) == -1)
    return (-1);
  if (raw_mode(t) == -1)
    return (-1);
  if (hide_char(t) == -1)
    return (-1);
  if (xtcsetattr(0, 0, t) == -1)
    return (-1);
  if (change_cursor(0) == -1)
    return (-1);
  return (0);
}

char	*reset_term(char *cmd, struct termios *t_save)
{
  if (xtcsetattr(0, 0, t_save) == -1)
    return (NULL);
  if (change_cursor(1) == -1)
    return (NULL);
  return (cmd);
}

int	init_line_editor(struct termios *t, struct termios *t_save, t_line **line)
{
  if (init_term(t, t_save) == -1)
    return (-1);
  if ((*line = my_xmalloc(sizeof(**line))) == NULL)
    return (-1);
  (*line)->head = NULL;
  (*line)->current = NULL;
  (*line)->tail = NULL;
  (*line)->size = 0;
  if (add_char('\0', line) == -1)
    return (-1);
  return (0);
}

int		show_edit_line(t_line *line)
{
  t_char	*tmp;

  my_printf("\r%s", PROMPT);
  tmp = line->head;
  while (tmp)
    {
      if (write_prompt_char(tmp) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

char			*line_editor()
{
  char			*cmd;
  char			buffer[BUFFER_SIZE];
  t_line		*line;
  struct termios	t;
  struct termios	t_save;

  if (init_line_editor(&t, &t_save, &line) == -1)
    return (NULL);
  bzero(buffer, BUFFER_SIZE);
  while (buffer[0] != '\n')
    {
      bzero(buffer, BUFFER_SIZE);
      if (show_edit_line(line) == -1)
	return (NULL);
      read(0, buffer, BUFFER_SIZE - 1);
      if (parser_line_editor(buffer, &line))
	return (NULL);
    }
  my_putchar('\n');
  return (reset_term(strdup("ls"), &t_save));
}
