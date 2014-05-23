/*
** cd_fct.c for  in /home/nicolas/Workspace/Unix/test
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed May 21 06:05:57 2014 Nicolas Ades
** Last update Thu May 22 05:00:07 2014 Nicolas Ades
*/

#include <stdlib.h>
#include <string.h>

int	find_and_replace(t_list *list, char *var, char *new)
{
  if (list == NULL)
    {
      fprintf(stderr, "var is not in the env\n");
      return (-1);
    }
  if (strncmp(list->data, var, strlen(var)) == 0)
    {
      list->data = strcpy(list->data ,new);
      return (0);
    }
  list = list->next;
  find_and_replace(list, var, new);
  return (0);
}

int	change_old_pwd(t_list *list, char *new)
{
  char	*var;
  if (is_in_env(list, OLDPWD=) != 1)
    {
      printf(stderr, "Error: missing OLD_PWD in env\n");
      return (-1);
    }
  var = malloc((strlen(new) + 8) * sizeof(*new));
  memset(var, 0, (strlen(new) + 8));
  var = strcat(var, "OLDPWD=");
  var = strcat(var, new);
  find_and_replace(list, "OLDPWD=", var);
  return (0);
}

int	change_pwd(t_list *list, char *new)
{
  if (is_in_env(list, PWD=) != 1)
    {
      printf(stderr, "Error: missing PWD in env\n");
      return (-1);
    }
  var = malloc((strlen(new) + 5) * sizeof(*new));
  memset(var, 0, (strlen(new) + 5));
  var = strcat(var, "PWD=");
  var = strcat(var, new);
  find_and_replace(list, "PWD=", var);
  return (0);
}

char	*epur_path(char *path)
{
  char	*new;
  int	j;
  int	i;

  i = 0;
  j = 0;
  new = malloc((strlen(path) + 1) * sizeof(*new));
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
  new = malloc((i + 3) * sizeof(*path));
  memset(new, 0, (i + 3));
  new = strcpy(new, path);
  i++;
  new[i] = '/';
  return (new);
}
