/*
** aliasing.h for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 16:06:42 2014 martelliere
** Last update Sat May 24 17:14:54 2014 Joris Bertomeu
*/

#ifndef ALIASING_H_
# define ALIASING_H_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "mysh.h"
# include "gnl.h"
# include "my.h"

/*
** Built in Alias
*/

int 	add_alias(t_alias *alias, char *name, char *content);
int	display_alias(t_alias *alias, char *name);
int    	display_all_alias(t_alias *alias);

/*
** Parsing & Initialisation alias
*/

int    	get_alias(t_alias *alias, t_shell *shell);
int    	get_alias_content(char *alias, char **content);
int    	get_alias_things(char *alias, char **name, char **content);
int    	load_alias(t_alias *alias, int fd, t_shell *shell, int active);
t_alias	*init_aliasing(t_shell *shell);

#endif /* _ALIASING_H_ */
