/*
** cd_fct_bis.c for  in /home/nicolas/Workspace/Unix/42sh/src/builtin
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Wed May 21 08:37:45 2014 Nicolas Ades
** Last update Sat May 24 15:54:13 2014 Nicolas Ades
*/

int		create_oldpwd(t_shell *shell, char *new)
{
  char		tmp;

  if (is_in_env(shell->env, "PWD=") == 0)
    {
      fprintf(stderr, "CD : PWD missing, can't create OLDPWD\n");
      return (-1);
    }
  if (tmp = get_env_var("PWD=", 4) == NULL)
    return (-1);
  while (shell->env != NULL)
    {
      shell->env = shell->env->next;
    }
  if (tmp = my_xmalloc((strlen(new) + 8) * sizeof(*tmp) == NULL))
    return (-1);
  memset(tmp, 0, (strlen(new) + 8));
  tmp = strcat(tmp, "OLDPWD=");
  tmp = strcat(tmp, new);
  add_to_end(shell->env, tmp);
  return (0);
}

int		create_pwd(t_shell *shell, char *new)
{
  char		tmp;

  while (shell->env != NULL)
    {
      shell->env = shell->env->next;
    }
  if (tmp = my_xmalloc((strlen(new) + 5) * sizeof(*tmp) == NULL))
    return (-1);
  memset(tmp, 0, (strlen(new) + 5));
  tmp = strcat(tmp, "PWD=");
  tmp = strcat(tmp, new);
  add_to_end(shell->env, tmp);
  return (0);
}

char		*concat_pwd(char *pwd)
{
  int		i;
  char		*new;

  i = 0;
  if (new = my_xmalloc(strlen(pwd) *sizeof(*new)) == NULL)
    return (NULL);
  memset(strlen(pwd) *sizeof(*new));
  while (pwd[i] != '\0')
    {
      /*Petit algo pour rendre le pwd propre apres des ../ bonne nuit mon chou  */
      i++;
    }
  return (new);
}

char		*epur_pwd(char *path)
{
  char		*tmp;
  char		*tmp2;
  char		*tmp3;

  if (tmp2 = get_env_var("PWD=", 4) == NULL)
    return (NULL);
  if (tmp = my_xmalloc((strlen(path) + 5)) == NULL)
    return (NULL);
  memset(tmp, 0, (strlen(path) + 5));
  tmp = strcat(tmp, "PWD=");
  if (tmp3 = concat_pwd(tmp2) == NULL)
    return (NULL);
  tmp = strcat(tmp, tmp3);
  return (tmp);
}
