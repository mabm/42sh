/*
** execution_without_fork.c for 42 in /home/jobertomeu/Work/42sh
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 19:50:58 2014 Joris Bertomeu
<<<<<<< HEAD
** Last update Wed May 28 00:55:43 2014 Jeremy Mediavilla
=======
** Last update Wed May 28 00:56:17 2014 Geoffrey Merran
>>>>>>> 796667ce78049abe42dc9a594b02f133e680d7f1
*/

#include "core.h"

int		do_fork_bis2(char **envp, char **cmd)
{
  execve(cmd[0], cmd, envp);
  return (0);
}

int		do_fork2(char **envp, char **cmd, char *path)
{
  execve(path, cmd, envp);
  return (0);
}

char		*is_cmd_exist2(char **cmd, char **path)
{
  int		i;
  char		*tmp;

  i = 0;
  while (path[i] != NULL)
    {
      if ((tmp = my_xmalloc((strlen(path[i]) + 2) *sizeof(*path))) == NULL)
	return (NULL);
      memset(tmp, 0, (strlen(path[i]) + 2));
      tmp = strcat(tmp, path[i]);
      tmp = strcat(tmp, "/");
      tmp = strcat(tmp, cmd[0]);
      if (access(tmp, F_OK) != -1)
	{
	  if (access(tmp, X_OK) == -1)
	    {
	      fprintf(stderr, "%s : Permission denied\n", cmd[0]);
	      return (NULL);
	    }
	  return (tmp);
	}
      i++;
    }
  fprintf(stderr, "%s : Command not found\n", cmd[0]);
  return (NULL);
}

int		my_exec_without_fork(t_shell *shell, char **cmd)
{
  char		**envp;
  char		**path;
  char		*tmp;
  char		*tmp2;

  envp = env_in_tab(shell->env);
  if (strstr(cmd[0], "/") != NULL)
    {
      if (do_fork_bis2(envp, cmd) == -1)
	return (-1);
      return (0);
    }
  if ((tmp = check_env_var(shell->env, "PATH=", 5)) == NULL)
    return (-1);
  path = my_strd_to_wordtab(tmp, ":");
  if ((tmp2 = is_cmd_exist2(cmd, path)) == NULL)
    return (-1);
  if (do_fork2(envp, cmd, tmp2) == -1)
    return (-1);
  return (0);
}
