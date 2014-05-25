/*
** return_pwd.c for 42 in /home/jobertomeu/Work/42sh/src/builtin
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 19:23:05 2014 Joris Bertomeu
** Last update Sun May 25 21:09:17 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	count_el(char *origin)
{
  int	i;
  int	j;

  j = 0;
  i = (origin[0] == '/') ? 1 : 0;
  while (origin[i])
    {
      if (origin[i] == '/')
	j++;
      i++;
    }
  if (origin[i + 1] != 0)
    j++;
  if (origin[strlen(origin) - 1] == '/')
    j--;
  return (j);
}

char	**fill_tree(int nbr, char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tree;

  i = 0;
  k = 0;
  j = 0;
  tree = malloc(nbr * sizeof(char*));
  tree[j] = malloc(128 * sizeof(char));
  while (str[i])
    {
      if (i != 0 && str[i] == '/')
	{
	  j++;
	  k = 0;
	  tree[j] = malloc(128 * sizeof(char));
	  memset(tree[j], 0, 128);
	}
      else if (str[i] != '/')
	tree[j][k++] = str[i];
      i++;
    }
  return (tree);
}

void	browse_tree(char **tree, char *str, int nbr)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == '.')
	{
	  nbr--;
	  printf("Goes to %s\n", tree[nbr]);
	}
      else if (str[i] == '/' && str[i + 1] != '.')
	{
	  nbr++;
	  printf("Goes to %s\n", tree[nbr]);
	}
      i++;
    }
}

char	*return_pwd(char *origin, char *target)
{
  char	**tree;
  int	nbr_el;

  nbr_el = count_el(origin);
  printf("Nombre de Elements : %d\n", nbr_el);
  tree = fill_tree(nbr_el, origin);
  browse_tree(tree, target, nbr_el - 1);
}

int	main()
{
  char	*pwd;

  pwd = return_pwd("/home/jobertomeu/tamere/current",
		   "../tonfils/../current/../../Documents");
  /* printf("PWD : %s\n", pwd); */
}
