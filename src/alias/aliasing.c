/*
** aliasing.c for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 15:16:12 2014 martelliere
** Last update Thu May 22 07:29:18 2014 martelliere
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
  path = my_alloc_init((16 + strlen(user)) * sizeof(char), 0);
  strcat(path, "/home/");
  strcat(path, user);
  strcat(path, "/");
  strcat(path, ".mabmmrc");
  return (path);
}

void	aliasing(t_list *list)
{
  int	fd;
  char	*path;
  char	*s;
  char	**tab;
  char	**tab2;

  path = get_user_path_alias();
  fd = xopen(path, O_RDONLY, 00644);
  while ((s = get_next_line(fd)) != NULL)
    {
      if (s[0] != '\0')
      	{
	  tab = my_str_to_wordtab(s);
	  if (tab[0] != NULL)
	    {
	      if (strcmp(tab[0], "alias") == 0)
		{
		  tab2 = my_str_to_wordtab2(s);
		  if (list == NULL)
		    list = create_list(tab[1], tab[2]);
		  else
		    add_after(list, tab[1], tab2[1]);
		}
	    }
	}
    }
  xclose(fd);
  delete_alias(list, "toto");
  write_alias(list, path);
}
