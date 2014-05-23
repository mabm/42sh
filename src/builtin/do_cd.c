/*
** do_cd.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue May 13 13:52:59 2014 Nicolas Ades
** Last update Fri May 23 10:47:34 2014 Nicolas Ades
*/

#include "core.h"

int		xchdir(const char *path)
{
  if (access(path, R_OK) == -1)
    {
      fprintf(stderr, "%s: permission denied\n");
      return (-1);
    }
  if ((chdir(path)) == -1)
    {
      fprintf(stderr, "Error on chdir with this path : [%s]\n", path);
      return (-1);
    }
  return (0);
}

int		do_cd_bis(t_list *list, char *path)
{
  char		*new;
  char		*old;

  if (my_strcmp(path, "-/") == 0)
    {
      if (old = check_env_var(list, "PWD=", 4) == NULL)
	return (-1);
      if (new = check_env_var(list, "OLDPWD=", 7) == NULL)
	return (-1);
      if ((xchdir(new)) == -1)
	return (-1);
      change_old_pwd(old);
      change_pwd(new);
      return (0);
    }
  else
    {
      old = get_env_var("PWD=", 4);
      new = strdup(path);
      if ((xchdir(path)) == -1)
	return (-1);
      change_old_pwd(old);
      change_pwd(new);
    }
  return (0);
}

int		do_cd(t_list *list, char *path)
{
  char		*new;
  char		*old;

  path = epur_path(path);
  path = add_slash(path);
  if (is_env_ok(list) == -1)
      return (-1);
  if (my_strcmp(path, "~/") == 0 || path == NULL)
    {
      if (old = check_env_var(list, "PWD=", 4) == NULL)
	return (-1);
      if (new = check_env_var(list, "HOME=", 5) == NULL)
	return (-1);
      if ((xchidr(new)) == -1)
	return (-1);
      change_old_pwd(old);
      change_pwd(new);
      return (0);
    }
  if ((do_cd_bis(list, path)) == -1)
    return (-1);
  return (0);
}
