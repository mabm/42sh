/*
** tab_functions.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Thu May  8 17:19:33 2014 Jeremy Mediavilla
** Last update Thu May  8 18:27:29 2014 Jeremy Mediavilla
*/

#include "core.h"

void		print_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int		tab_size(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
