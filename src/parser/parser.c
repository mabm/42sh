/*
** parser.c for parser in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 28 02:53:09 2014 Geoffrey Merran
** Last update Wed May 28 02:56:13 2014 Geoffrey Merran
*/

#include "parser.h"

int		wait_father(pid_t pid)
{
  int		status;

  while (pid != wait4(pid, &status, WNOHANG, 0))
    {
    }
  return (status);
}

void	choose_exec(char **cmd1, int sep, char **cmd2, int j, int **pipefd, t_shell *shell)
{
  int	pipefd2[2];
  char	tmp[4096];
  int	t;

  if (cmd1 != NULL && cmd2 != NULL)
    {
      pipe(*pipefd);
      if (fork() == 0)
	{
	  dup2((*pipefd)[1], 1);
	  if (check_builtin(shell, cmd2) == -2)
	    if (my_exec_without_fork(shell, cmd2) == -1)
	      exit(0);
	}
      wait(NULL);
    }
  t = read((*pipefd)[0], tmp, 4096);
  close((*pipefd)[1]);
  close((*pipefd)[0]);
  pipe(pipefd2);
  pipe(*pipefd);
  write((*pipefd)[1], tmp, t);
  close((*pipefd)[1]);
  if (fork() == 0)
    {
      dup2((*pipefd)[0], 0);
      dup2(pipefd2[1], 1);
      if (check_builtin(shell, cmd2) == -2)
	if (my_exec_without_fork(shell, cmd2) == -1)
	  exit(0);
    }
  wait(NULL);
  t = read(pipefd2[0], tmp, 4096);
  close(pipefd2[0]);
  close(pipefd2[1]);
  pipe(*pipefd);
  write((*pipefd)[1], tmp, t);
  close((*pipefd)[1]);
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
  int		*pipefd;
  char		**cmd1;
  char		**cmd2;
  char		tmps[4096];
  int		pid;

  i = 0;
  tmp = list;
  j = 0;
  pipefd = malloc(2 * sizeof(int));
  if (tmp->next != NULL && tmp->type == -1)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      cmd1 = NULL;
      cmd2 = NULL;
      if (tmp->type == 0)
	{
	  cmd1 = get_cmd(tmp);
	  while (tmp && tmp->type == 0)
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
	  while (tmp && tmp->type == 0)
	    tmp = tmp->next;
	}
      if (cmd2 == NULL)
	{
	  pipe(pipefd);
	  if ((pid = fork()) == 0)
	    {
	      close(pipefd[0]);
	      dup2(pipefd[1], 1);
	      if (check_builtin(shell, cmd1) == -2)
		if (my_exec_without_fork(shell, cmd1) == -1)
		  exit(0);
	    }
	  wait_father(pid);
	  break;
	}
      choose_exec(cmd1, sep, cmd2, j, &pipefd, shell);
      /* tmp = tmp->next; */
      i++;
    }
  memset(tmps, 0, 4096);
  read(pipefd[0], tmps, 4096);
  close(pipefd[0]);
  close(pipefd[1]);
  write(1, tmps, 4096);
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
