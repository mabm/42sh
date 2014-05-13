/*
** aliasing.c for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 15:16:12 2014 martelliere
** Last update Mon May 12 16:57:50 2014 martelliere
*/

#include "aliasing.h"

char    *get_user_path()
{
  char  *user;
  char  *path;

  if ((user = getenv("USER")) == NULL)
    {
      printf("42sh: can't get username to access history.\n");
      return ;
    }
  path = my_alloc_init((15 + strlen(user)) * sizeof(char), 0);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".bashrc");
  return (path);
}

void	aliasing(t_aliasl *alias)
{
  int	fd;
  char	*path;
  char	*s;
  char	**tab;
  char	**tab2;

  path = get_user_path();
  fd = xopen(path, O_RDONLY);
  while ((s = get_next_line(fd)) != NULL)
    {
      if (s[0] != '\0')
	{
	  tab = my_str_to_wordtab(s);
	  if (strcmp(tab[0], "alias") == 0)
	    {
	      printf("tab[1] : %s\n", tab[1]);
	      tab2 = my_str_to_wordtab2(s);
	      printf("tab2[1]: %s\n", tab2[1]);
	      add_alias(alias, tab[1], tab2[1]);
	    }
	}
    }
  xclose(fd);
}
