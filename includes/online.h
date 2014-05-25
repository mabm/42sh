/*
** online.h for online in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 24 05:46:56 2014 Geoffrey Merran
** Last update Sat May 24 21:54:33 2014 Geoffrey Merran
*/

#ifndef ONLINE_
# define ONLINE_
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <mysql.h>
# include <my_global.h>
# include <time.h>
# include <termios.h>
# include "mysh.h"
# include "aliasing.h"

# define modeCANON    0
# define modeNonCANON 1

int    	add_alias_from_bdd(t_alias *alias, t_shell *shell);
void	connection(t_online *sys);
void   	add_cmd_history_mysql(t_shell *shell, char *cmd);
void	modify_active(char *user, char *active);

#endif /* ONLINE_ */
