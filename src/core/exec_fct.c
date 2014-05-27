/*
** exec_fct.c for env in /home/jobertomeu/Work/42sh
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Tue May 27 23:33:01 2014 Joris Bertomeu
** Last update Tue May 27 23:40:17 2014 Joris Bertomeu
*/

#include "core.h"

int		list_size(t_list *list)
{
  int		i;
  t_list	*tmp;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char		**env_in_tab(t_list *list)
{
  char		**mtab;
  int		size;
  int		i;
  int		len;

  i = 0;
  size = list_size(list);
  mtab = my_xmalloc(size * sizeof(char *));
  list = list->next;
  while (list != NULL)
    {
      len = strlen(list->data) + 1;
      mtab[i] = my_xmalloc(len * sizeof(char));
      memset(mtab[i], '\0', len);
      mtab[i] = list->data;
      list = list->next;
      i++;
    }
  return (mtab);
}
