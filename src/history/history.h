/*
** history.h for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:50:11 2014 martelliere
** Last update Thu May 22 08:16:56 2014 martelliere
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
# include	"my_list.h"

void	history();
int	delete_cmd(t_list *list, char *name);
int	save_history(t_list *list, char *path);
int	get_history(t_list *list, char *path);
void	*my_xmalloc(int size);
void	*my_alloc_init(int size, char c);
char	*get_user_path();

#endif		/* HISTORY_H_ */
