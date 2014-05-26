/*
** do_cd.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue May 13 13:52:59 2014 Nicolas Ades
<<<<<<< HEAD
** Last update Mon May 26 20:54:14 2014 Nicolas Ades
=======
** Last update Wed May 28 12:35:42 2014 Jeremy Mediavilla
>>>>>>> f6d05c87b3dff822d4ebfe449c3054066c2e7726
*/

#include "core.h"

int		xchdir(const char *path)
{
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr, "42sh: cd: %s: permission denied\n", path);
      return (-1);
    }
  if ((chdir(path)) == -1)
    {
      fprintf(stderr, "42sh: cd: Error on chdir with this path : [%s]\n", path);
      return (-1);
    }
  return (0);
}

int		do_cd_bis(t_shell *shell, char *path)
{
  char		*new;
  char		*old;

  if (my_strcmp(path, "-/") == 0)
    {
      if ((old = check_env_var(shell->env, "PWD=", 4)) == NULL)
	return (-1);
      if ((new = check_env_var(shell->env, "OLDPWD=", 7)) == NULL)
	return (-1);
      if ((xchdir(new)) == -1)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
      return (0);
    }
  else
    {
      old = get_env_var("PWD=", 4);
      new = strdup(path);
      if ((xchdir(path)) == -1)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
    }
  return (0);
}

int		do_cd(t_shell *shell, char **cmd)
{
  char		*new;
  char		*old;
  char		*path;

  path = strdup(cmd[1]);
  if ((path = epur_path(path)) == NULL)
    return (-1);
  if ((path = add_slash(path)) == NULL)
    return (-1);
  if (my_strcmp(path, "~/") == 0 || path == NULL)
    {
      if ((old = check_env_var(shell->env, "PWD=", 4)) == NULL)
	return (-1);
      if ((new = check_env_var(shell->env, "HOME=", 5)) == NULL)
	return (-1);
      if ((xchdir(new)) == -1)
	return (-1);
      change_old_pwd(shell, old);
      change_pwd(shell, new);
      return (0);
    }
  if ((do_cd_bis(shell, path)) == -1)
    return (-1);
  return (0);
}
