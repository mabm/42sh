/*
** env.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:45:44 2014 Jeremy Mediavilla
** Last update Fri May 23 09:58:32 2014 Nicolas Ades
*/

#include "core.h"

/* A utiliser de avec le '=' après le nom de la variable d'environnement recherchée */
/* exemple : */
/* utiliser is_in_env(list, "PWD=") et pas is_in_env(list, "PWD") */

int             is_in_env(t_list *list, char *var)
{
  int           size;

  size = strlen(var);
  while (list != NULL)
    {
      if (list->data != NULL)
        if (strncmp(list->data, var, size) == 0)
          return (1);
      list = list->next;
    }
  return (0);
}

char            *get_env_var(char *var, int len)
{
  char          *value;
  int           size;
  int           i;

  if (is_in_env(list, var) == 0)
    return (NULL);
  i = 0;
  size = strlen(var);
  if (value = my_xmalloc((size - len + 1) * sizeof(char)) == NULL)
    return (NULL);
  memset(value, '\0', (size - len + 1));
  while (var[len])
    {
      value[i] = var[len];
      len++;
      i++;
    }
  return (value);
}

/* a utiliser de cette manière : check_env_var(list, "PWD=", 4) */

char            *check_env_var(t_list *list, char *name, int len)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data != NULL)
        if (strncmp(tmp->data, name, len) == 0)
	  return (get_env_var(tmp->data, len));
      tmp = tmp->next;
    }
  return ("\0");
}

void		aff_env(t_list *list, char *cmd)
{
  t_list	*tmp;

  (void) cmd;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data != NULL)
	printf("%s\n", tmp->data);
      tmp = tmp->next;
    }
}

void		get_all_env(t_list *list, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      add_to_end(list, env[i]);
      i++;
    }
}
