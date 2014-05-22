/*
** mysh.h for mysh in /home/merran_g/work/c_elem/42sh/src/history
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 22 11:35:41 2014 Geoffrey Merran
** Last update Thu May 22 13:04:48 2014 Geoffrey Merran
*/

#ifndef MYSH_
# define MYSH_
# include "my_list.h"

typedef struct	s_history
{
  t_list	*list;
  char		*path;
}		t_history;

typedef struct	s_shell
{
  t_history	*history;
  int		prompt;
}		t_shell;

#endif /* MYSH_ */
