/*
** return_pwd.c for 42 in /home/jobertomeu/Work/42sh/src/builtin
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 19:23:05 2014 Joris Bertomeu
** Last update Mon May 26 15:56:25 2014 Joris Bertomeu
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
  tree = malloc((nbr + 10) * sizeof(char*));
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

char	**do_place(char **tree, int nbr, int save)
{
  int	i;

  i = save + 1;
  tree[i] = malloc(128 * sizeof(char));
  while (i >= nbr)
    {
      strcpy(tree[i], tree[i - 1]);
      i--;
    }
  return (tree);
}

void	browse_tree(char **tree, char *str, int nbr)
{
  int	i;
  int	j;
  char	*tmp;
  char	**tree2;
  int	svnb;
  int	flag;

  i = 0;
  svnb = nbr;
  tmp = malloc(128 * sizeof(char));
  tree2 = malloc(20 * sizeof(char*));
  while (str[i])
    {
      if (str[i] == '.' && str[i + 1] == '.')
	{
	  nbr--;
	  flag = 1;
	  printf("-Goes to %s (%d)\n", tree[nbr], nbr);
	}
      else if (str[i] == '/' && str[i + 1] != '.')
	{
	  j = 0;
	  i++;
	  memset(tmp, 0, 128);
	  while (str[i] && str[i] != '/')
	    tmp[j++] = str[i++];
	  printf("+Goes to %s -> %s (%d)\n", tree[nbr], tmp, nbr);
	  if (flag == 1)
	    {
	      tree = do_place(tree, nbr, svnb);
	      strcpy(tree[nbr], tmp);
	      printf("Placed to %s\n", tree[nbr]);
	      flag = 0;
	    }
	}
      /* else */
      /* 	{ */
      /* 	  j = 0; */
      /* 	  memset(tmp, 0, 128); */
      /* 	  while (str[i] && str[i] != '/') */
      /* 	    tmp[j++] = str[i++]; */
      /* 	  printf("+Goes to %s -> %s (%d)\n", tree[nbr], tmp, nbr); */
      /* 	  tree[nbr + 1] = malloc(128 * sizeof(char)); */
      /* 	  strcpy(tree[nbr + 1], tmp); */
      /* 	  nbr++; */
      /* 	} */
      i++;
    }
  int	l = 0;
  while (l <= nbr)
    printf("/%s", tree[l++]);
  printf("\n");
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
		   "../tonfils");
  /* printf("PWD : %s\n", pwd); */
}
