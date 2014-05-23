/*
** history.h for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:50:11 2014 martelliere
** Last update Fri May 23 14:57:08 2014 Joris Bertomeu
*/

#ifndef		HISTORY_H_
# define	HISTORY_H_
# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	"mysh.h"
# include	"gnl.h"
# include	"my.h"

/*
** History
*/

t_history	*init_history(t_shell *shell);
int		delete_cmd(t_hlist *list, char *name);
int		add_cmd(t_history *history, char *name);
int		save_history(t_history *history, t_shell *shell);
int		get_history(t_history *history, t_shell *shell);
void		*my_alloc_init(int size, char c);
char		*get_user_path();

/*
** Xfunction
*/

void		xclose(int fd);
int		xopen(const char *path, int flags, mode_t mode);

/*
** Histo list
*/

t_hlist		*create_hlist(char *name, char *date);
void		add_tailh(t_history *history, char *name, char *date);

#endif		/* HISTORY_H_ */
