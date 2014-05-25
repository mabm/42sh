/*
** core.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:04 2014 Nicolas Ades
** Last update Sat May 24 16:06:20 2014 Nicolas Ades
*/

#ifndef	CORE_H_
# define CORE_H_
# include "mysh.h"
# include "history.h"
# include "main.h"
# include "my.h"
# include "line_editor.h"
# include "conf.h"
# include "free_shell.h"
# include "aliasing.h"
# include "signal.h"
# include "online.h"
# include "parser.h"

/*
** Print tabs
*/

int		tab_size(char **);
void		print_tab(char **);

/*
** Built in
*/

void		my_cd(t_list *, char *);

/*
** Builtin Env
*/

char		*init_unsetenv_var(int, char **);
void		my_echo(t_shell *, char **);
void		my_setenv(t_list *, char *);
void		my_unsetenv(t_list *, char *);
void		get_all_env(t_list *, char **);
void		aff_env(t_list *, char *);
int		is_in_env(t_list *, char *);
char		*get_env_var(char *, int);
char		*check_env_var(t_list *, char *, int);
t_online	*online_mode();

/*
** Prompt
*/

int		prompt(t_shell *shell);

#endif /* CORE_H_ */
