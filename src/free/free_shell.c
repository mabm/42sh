/*
** free_history.c for free_history in /home/merran_g/work/c_elem/42sh/src/free
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 22 23:41:57 2014 Geoffrey Merran
** Last update Sat May 24 16:56:08 2014 Geoffrey Merran
*/

#include "free_shell.h"

void		free_history(t_history *history)
{
  t_hlist	*tmp;

  while (history->head)
    {
      tmp = history->head->next;
      free(history->head->name);
      free(history->head->date);
      history->head = tmp;
      history->size--;
    }
  free(history->path);
  free(history);
}

void		free_env(t_list	*env)
{
  t_list	*tmp;
  t_list	*save;

  tmp = env;
  while (tmp)
    {
      save = tmp->next;
      if (tmp->data != NULL)
	free(tmp->data);
      free(tmp);
      tmp = save;
    }
}

void		free_shell(t_shell *shell)
{
  free_history(shell->history);
  free_env(shell->env);
  free(shell);
}
