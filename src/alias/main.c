/*
** main.c for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 14:46:50 2014 martelliere
** Last update Mon May 12 16:38:55 2014 martelliere
*/

#include "aliasing.h"

int		main()
{
  int		fd;
  t_aliasl	*alias;

  alias = init_aliasing(alias);
  aliasing(alias);
  display_alias(alias);
  return (0);
}
