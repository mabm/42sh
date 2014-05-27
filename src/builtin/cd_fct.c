/*
** cd_fct.c for  in /home/nicolas/Workspace/Unix/test
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed May 21 06:05:57 2014 Nicolas Ades
** Last update Mon May 26 14:11:13 2014 Nicolas Ades
*/

#include <stdlib.h>
#include <string.h>

int	find_and_replace(t_shell *shell, char *var, char *new)
{
  t_list	*tmp;

  tmp = shell->env;
  while (tmp)
    {
      if (tmp == NULL)
	{
	  fprintf(stderr, "%s is not int the env\n", var);
	  return (-1);
	}
      if (strncmp(tmp->data, var, strlen(var)) == 0)
	{
	  tmp->data = strcpy(tmp->data ,new);
	  return (0);
	}
      tmp->env = tmp->next;
    }
  return (0);
}

int	change_old_pwd(t_shell *shell, char *new)
{
  char	*var;

  if (is_in_env(shell->env, "OLDPWD=") != 1)
    {
      if (create_oldpwd(shell->env, new) == -1)
	return (-1);
      return (0);
    }
  if (var = my_xmalloc((strlen(new) + 8) * sizeof(*new)) == NULL)
    return (-1);
  memset(var, 0, (strlen(new) + 8));
  var = strcat(var, "OLDPWD=");
  var = strcat(var, new);
  find_and_replace(shell->env, "OLDPWD=", var);
  return (0);
}

int	change_pwd(t_shell *shell, char *new)
{
  new = modif_path(check_env_var(shell->env, "PWD=", 4), new);
  if (is_in_env(shell->env, "PWD=") != 1)
    {
      if (create_pwd(shell->env, new) == -1)
	return (-1);
      return (0);
    }
  if (var = my_xmalloc((strlen(new) + 5) * sizeof(*new)) == NULL)
    return (-1);
  memset(var, 0, (strlen(new) + 5));
  var = strcat(var, "PWD=");
  var = strcat(var, new);
  find_and_replace(shell->env, "PWD=", var);
  return (0);
}

char	*epur_path(char *path)
{
  char	*new;
  int	j;
  int	i;

  i = 0;
  j = 0;
  if (new = malloc((strlen(path) + 1) * sizeof(*new)) == NULL)
    return (-1);
  memset(new, 0, (strlen(path) + 1));
  while (path[i] != '\0')
    {
      if (path[i] == '/' && path[i + 1] == "." && path[i + 2] == "/")
	i += 2;
      new[j] = path[i];
      i++;
    }
  return (new);
}

char	*add_slash(char *path)
{
  char *new;
  int	i;

  i = strlen(path) - 1;
  if (path[i] == '/')
    return (path);
  if (new = malloc((i + 3) * sizeof(*path)) == NULL)
    return (-1);
  memset(new, 0, (i + 3));
  new = strcpy(new, path);
  i++;
  new[i] = '/';
  return (new);
}
