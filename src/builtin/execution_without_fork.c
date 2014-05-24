/*
** execution_without_fork.c for 42 in /home/jobertomeu/Work/42sh
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 19:50:58 2014 Joris Bertomeu
** Last update Sun May 25 19:58:27 2014 Joris Bertomeu
*/

#include "core.h"

int		do_fork_bis2(char **envp, char **cmd)
{
  execve(cmd[0], cmd, envp);
  return (0);
}

int		do_fork2(char **envp, char **cmd, char **path, int pos)
{
  execve(path[pos], cmd, envp);
  return (0);
}

int		is_cmd_exist2(char **cmd, char **path)
{
  int		i;
  char		*tmp;

  i = 0;
  while (path[i] != NULL)
    {
      if ((tmp = my_xmalloc((strlen(path[i]) + 1) *sizeof(*path))) == NULL)
	return (-1);
      memset(tmp, 0, (strlen(path[i]) + 1));
      tmp = strcat(tmp, path[i]);
      tmp = strcart(tmp, cmd[0]);
      if (access(tmp, F_OK) != -1)
	{
	  if (access(tmp, X_OK) == -1)
	    {
	      fprintf(stderr, "%s: Permission denied\n", cmd[0]);
	      return (-1);
	    }
	  return (i);
	}
      i++;
    }
  fprintf(stderr, "%: Command not found\n", cmd[0]);
  return (-1);
}

int		my_exec_without_fork(t_shell *shell, char **cmd)
{
  int		pos;
  char		**envp;
  char		**path;

  envp = env_in_tab(shell->env);
  if (strstr(cmd[0], "/") != NULL)
    {
      if (do_fork_bis2(envp, cmd) == -1)
	return (-1);
      return (0);
    }
  if ((path = check_env_var(shell->env, "PATH=", 5)) == NULL)
    return (-1);
  if ((pos = is_cmd_exist2(cmd, path)) == -1)
    return (-1);
  if (do_fork2(envp, cmd, path, pos) == -1)
    return (-1);
  return (0);
}
