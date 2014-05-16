/*
** build_line.c for build_line in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 19:46:48 2014 Geoffrey Merran
** Last update Thu May 15 20:14:04 2014 Geoffrey Merran
*/

#include "line_editor.h"

char		*build_line(t_line *line)
{
  char		*cmd;
  t_char	*tmp2;
  t_char	*tmp;
  int		i;

  cmd = my_xmalloc(line->size * sizeof(char));
  if (cmd == NULL)
    return (NULL);
  i = 0;
  tmp = line->head;
  while (tmp)
    {
      tmp2 = tmp->next;
      cmd[i++] = tmp->c;
      free(tmp);
      tmp = tmp2;
    }
  my_printf("\r%s%s \n", PROMPT, cmd);
  free(line);
  return (cmd);
}
