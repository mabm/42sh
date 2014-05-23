/*
** do_cd.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Tue May 13 13:52:59 2014 Nicolas Ades
** Last update Fri May 23 08:44:55 2014 Nicolas Ades
*/

#include "core.h"

int		xchdir(const char *path)
{
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
      old = get_env_var("PWD=", 4);
      new = get_env_var("OLDPWD=", 7);
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
      old = get_env_var("PWD=", 4);
      new = get_env_var("HOME=", 5);
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
