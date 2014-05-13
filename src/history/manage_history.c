/*
** manage_history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:54:07 2014 martelliere
** Last update Sat May 10 16:37:53 2014 martelliere
*/

#include "history.h"

t_cmdl	*init_history(t_cmdl *history)
{
  history = my_xmalloc(sizeof(t_cmdl));
  history->first = NULL;
  return (history);
}

void	add_cmd(t_cmdl *history, char *cmd)
{
  t_cmd	*new;
  t_cmd	*tmp;


  if (history == NULL || cmd == NULL)
    return ;
  new = my_xmalloc(sizeof(t_cmd));
  new->name = my_alloc_init((strlen(cmd) + 1) * sizeof(char), 0);
  new->name = strcat(new->name, cmd);
  if (history->first == NULL)
    {
      new->prev = NULL;
      new->next = NULL;
      history->first = new;
    }
  else
    {
      tmp = history->first;
      tmp->prev = new;
      new->next = tmp;
      new->prev = NULL;
      history->first = new;
    }
}

void	save_history(t_cmdl *history)
{
  t_cmd	*tmp;
  int	fd;

  if (history == NULL)
    {
      printf("42sh: history: wrong history list.\n");
      return ;
    }
  fd = xopen("/home/martel_c/cmd_history",
	     O_WRONLY | O_CREAT | O_APPEND, 00600);
  tmp = my_xmalloc(sizeof(t_cmd));
  tmp = history->first;
  while (tmp != NULL)
    {
      puts("toto");
      xwrite(fd, tmp->name, strlen(tmp->name));
      xwrite(fd, "\n", 1);
      tmp = tmp->next;
    }
}

void	get_history(t_cmdl *history)
{
  int	fd;
  char	*s;

  if (access("/home/martel_c/cmd_tmp", F_OK) == -1)
    {
      printf("No history file saved. Restarting an empty history.\n");
      return ;
    }
  if (access("/home/martel_c/cmd_tmp", R_OK) == -1)
    {
      printf("Can't read the history file. Check your rights and session.\n");
      return ;
    }
  fd = xopen("/home/martel_c/cmd_tmp", O_RDONLY);
  while ((s = get_next_line(fd)) != NULL)
    {
      puts("tata");
      add_cmd(history, s);
    }
}
