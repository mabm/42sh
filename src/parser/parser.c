/*
** parser.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:35 2014 Jeremy Mediavilla
** Last update Tue May 27 22:56:31 2014 Jeremy Mediavilla
*/

#include "parser.h"

void	choose_exec(char *cmd1, int sep, char *cmd2, int j, int **pipefd, t_shell *shell)
{
  int	pipefd2[2];
  char	tmp[4096];

  if (cmd1 != NULL && cmd2 != NULL)
    {
      pipe(*pipefd);
      dup2((*pipefd)[1], 1);
      if (sep == 11)
	do_pipe(cmd1, cmd2, 2);
      else if (sep == 13)
	do_redirect();
    }
  else if (cmd1 == NULL)
    {
      pipe(pipefd2[1], 1);
      dup2((*pipefd)[0], 0);
      dup2(pipefd2[1], 1);
      if (sep == 11)
	exec_without_fork(shell, cmd2);
      close((*pipefd)[1]);
      close((*pipefd)[0]);
      pipe(*pipefd);
      read(pipefd2[0], tmp, 4096);
      write((*pipefd)[1], tmp, 4096);
      close(pipefd2[0]);
      close(pipefd2[1]);
    }
}

int		my_parser(t_link *list, t_shell *shell)
{
  t_link	*tmp;
  int		**my_tab;
  int		priority;
  int		i;
  int		j;
  int		**priority_tab;
  int		sep;
  int		pipefd[2];
  char		**cmd1;
  char		**cmd2;
  char		tmp[4096];

  i = 0;
  tmp = list;
  j = 0;
  if (tmp->next != NULL && tmp->type == -1)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      cmd1 = NULL;
      cmd2 = NULL;
      if (tmp->type == 0)
	{
	  cmd1 = get_cmd(tmp);
	  while (tmp->type == 0 && tmp)
	    tmp = tmp->next;
	}
      if (tmp && tmp->type != 0)
	{
	  sep = tmp->type;
	  tmp = tmp->next;
	  j++;
	}
      if (tmp && tmp->type == 0)
	{
	  cmd2 = get_cmd(tmp);
	  while (tmp->type == 0 && tmp)
	    tmp = tmp->next;
	}
      choose_exec(cmd1, sep, cmd2, j, pipefd, shell);
      /* tmp = tmp->next; */
      i++;
    }
  read(pipefd[0], tmp, 4096);
  write(1, tmp, 4096);
  close(pipefd[0]);
  close(pipefd[1]);
  return (0);
}

int		my_parser_check(t_link *list, char *cmd, t_shell *shell)
{
  t_tree	*tree;
  t_link	*tmp;

  tmp = list;
  printf("\n%s\n\n", cmd);
  if ((tree = init_access()) == NULL)
    return (-1);
  while (tmp != NULL)
    {
      if (tmp != NULL && (int)tmp->type != -1)
	if (check_token_succession(tmp, tree) == -1)
	  remove_unvalid_links(&tmp);
      if (tmp != NULL)
	tmp = tmp->next;
    }
  free_tree(tree);
  tmp = list;
  remove_old_links(&tmp, &list);
  aff_my_list(list);
  my_parser(list, shell);
  return (0);
}

int		my_lexer(char *cmd, t_shell *shell)
{
  int		i;
  int		len;
  t_link	*list;

  if (cmd == NULL)
    {
      my_puterr("Lexer error : param is equal to NULL\n");
      return (-1);
    }
  if ((list = init_list(NULL, -1)) == NULL)
    return (-1);
  i = 0;
  len = strlen(cmd);
  while (i < len)
    {
      if (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t')
	i++;
      else
	if (check_token(cmd, &i, list) == -1)
	  return (-1);
    }
  if (my_parser_check(list, cmd, shell) == -1)
    return (-1);
  return (0);
}
