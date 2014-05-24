/*
** aliasing.c for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 15:16:12 2014 martelliere
** Last update Sat May 24 17:01:14 2014 Joris Bertomeu
*/

#include "aliasing.h"

char    *get_user_path_alias()
{
  char  *user;
  char  *path;

  if ((user = getenv("USER")) == NULL)
    {
      printf("42sh: can't get username env variable to access history.\n");
      return (NULL);
    }
  path = my_xmalloc((16 + strlen(user)) * sizeof(char));
  bzero(path, (16 + strlen(user)));
  if (path == NULL)
    return (NULL);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".bashrc");
  return (path);
}

int		get_alias(t_alias *alias, t_shell *shell)
{
  int		fd;

  if (shell->online->active == 0)
    {
      if (alias->path == NULL)
	return (-1);
      if (access(alias->path, F_OK) == -1)
	{
	  fprintf(stderr, "42sh: alias: can't access %s\n", alias->path);
	  return (-1);
	}
      if (access(alias->path, R_OK) == -1)
	{
	  fprintf(stderr,"42sh: alias: can't read alias file. \
Check your rights.\n");
	  return (-1);
	}
      if ((fd = open(alias->path, O_RDONLY)) == -1)
	return (-1);
      return (load_alias(alias, fd, shell, 0));
    }
  return (load_alias(alias, fd, shell, 1));
}

t_alias		*init_aliasing(t_shell *shell)
{
  t_alias	*alias;

  (void) shell;
  alias = my_xmalloc(sizeof(*alias));
  if (alias == NULL)
    return (NULL);
  alias->path = get_user_path_alias();
  alias->list = NULL;
  get_alias(alias, shell);
  return (alias);
}
