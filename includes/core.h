/*
** core.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:04 2014 Nicolas Ades
** Last update Wed May 28 02:45:21 2014 Geoffrey Merran
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

int		my_cd(t_shell *shell, char **cmd);
int		check_builtin(t_shell *shell, char **cmd);

/*
** Builtin Env
*/

char		*init_unsetenv_var(int, char **);
int		my_echo(t_shell *, char **);
int		my_setenv(t_shell *, char **);
int		my_unsetenv(t_shell *, char **);
void		get_all_env(t_list *, char **);
int		aff_env(t_shell *, char **);
int		is_in_env(t_list *, char *);
char		*get_env_var(char *, int);
char		*check_env_var(t_list *, char *, int);
t_online	*online_mode();
char		**env_in_tab(t_list *list);

/*
** Prompt
*/

int		prompt(t_shell *shell);

#endif /* CORE_H_ */
