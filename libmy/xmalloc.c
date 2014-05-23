/*
** xmalloc.c for xmalloc.c in /home/merran_g/work/c_elem/Bistro
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun Nov 10 14:28:36 2013 Geoffrey Merran
** Last update Fri May 23 02:07:31 2014 Geoffrey Merran
*/

#include <stdlib.h>
#include "my.h"

void	*my_xmalloc(int size)
{
  void	*m;

  m = malloc(size);
  if (m == NULL)
    {
      my_puterr("malloc error couldnt alloc\n");
      return (NULL);
    }
  return (m);
}
