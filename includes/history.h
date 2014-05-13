/*
** history.h for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:50:11 2014 martelliere
** Last update Sat May 10 16:32:05 2014 martelliere
*/

#ifndef		HISTORY_H_
# define	HISTORY_H_

# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	"get_next_line.h"

typedef	struct	s_cmd
{
  char		*name;
  struct s_cmd	*next;
  struct s_cmd	*prev;
}		t_cmd;

typedef struct	s_cmdl
{
  t_cmd		*first;
}		t_cmdl;

void	add_cmd(t_cmdl *history, char *cmd);
void	save_history(t_cmdl *history);
void	*my_xmalloc(int size);
void	*my_alloc_init(int size, char c);
t_cmdl	*init_history(t_cmdl *history);

#endif		/* HISTORY_H_ */
