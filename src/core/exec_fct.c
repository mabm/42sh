/*
** exec_fct.c for  in /home/nicolas/Workspace/Unix/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 16:09:23 2014 Nicolas Ades
** Last update Tue May 27 23:28:50 2014 Geoffrey Merran
*/

#include "core.h"

char		**env_in_tab(t_list *list)
{
  char		**tab;
  int		size;
  int		i;
  int		len;

  i = 0;
  size = list_size(list);
  tab = xmalloc(size * sizeof(char *));
  list = list->next;
  while (list != NULL)
    {
      len = my_strlen(list->data) + 1;
      tab[i] = xmalloc(len * sizeof(char));
      my_memset(tab[i], '\0', len);
      tab[i] = list->data;
      list = list->next;
      i++;
    }
  return (tab);
}
