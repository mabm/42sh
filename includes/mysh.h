/*
** mysh.h for mysh in /home/merran_g/work/c_elem/42sh/src/history
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 22 11:35:41 2014 Geoffrey Merran
** Last update Sat May 24 23:24:47 2014 Geoffrey Merran
*/

#ifndef MYSH_
# define MYSH_
# include <string.h>
# include "my_list.h"

typedef struct		s_hlist
{
  char			*name;
  char			*date;
  struct s_hlist	*next;
  struct s_hlist	*prev;
}			t_hlist;

typedef	struct		s_alist
{
  char			*name;
  char			*content;
  struct s_alist	*next;
}			t_alist;

typedef struct	s_history
{
  t_hlist	*head;
  t_hlist	*current;
  t_hlist	*tail;
  int		size;
  char		*path;
}		t_history;

typedef	struct	s_online
{
  int		active;
  char		*pseudo;
  int		is_history;
  int		is_alias;
  int		num_hist;
  int		is_prompt;
  char		**history;
}		t_online;

typedef struct	s_alias
{
  t_alist	*list;
  char		*path;
}		t_alias;

typedef struct	s_shell
{
  t_history	*history;
  t_alias	*alias;
  t_list	*env;
  t_online	*online;
  int		prompt;
  int		error;
  int		end;
}		t_shell;

#endif /* MYSH_ */
