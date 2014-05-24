/*
** execution.c for  in /home/nicolas/Workspace/Unix/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 24 08:06:43 2014 Nicolas Ades
** Last update Sat May 24 08:48:08 2014 Nicolas Ades
*/

#include "core.h"

/* cmd[0] correspond au nom de la commande que je concat avec le path */

int		do_fork()
{
  pid_t		ptr;
  
  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "Error with fork\n");
      return (-1);
    }
  if (pid == 0)
    execve(path, cmd, shell->env);
  else
    wait(NULL);
  return (0);
}

int		is_cmd_exist(t_shell *shell, char **cmd, char **path)
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
      if (access(tmp, X_OK) != -1)
	return (i);
      i++;
    }
  return (-1);
}

int		my_exec(t_shell *shell, char **cmd)
{
  int		pos;
  char		**path;

  if ((path = check_env_var(shell->env, "PATH=", 5)) == NULL)
    return (-1);
  if ((pos = is_cmd_exist(shell, cmd, path)) == -1)
    return (-1);
  if (do_fork() == -1)
    return (-1);
  return (0);
}
