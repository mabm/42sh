/*
** core.h for core in /home/merran_g/work/c_elem/42sh
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 28 02:52:45 2014 Geoffrey Merran
** Last update Wed May 28 04:54:10 2014 Geoffrey Merran
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

int		check_builtin(t_shell *shell, char **cmd);
int		my_exit(t_shell *, char **);
int		do_cd(t_shell *, char **);
int		my_echo(t_shell *, char **);
int		my_setenv(t_shell *, char **);
int		my_unsetenv(t_shell *, char **);
int		aff_env(t_shell *, char **);

/*
** Builtin Env
*/

char		*init_unsetenv_var(int, char **);
int		do_cd_bis(t_shell *, char *);
int		xchdir(const char *);
int		create_oldpwd(t_shell *, char *);
int		create_pwd(t_shell *, char *);
int		find_and_replace(t_shell *, char *, char *);
int		change_old_pwd(t_shell *, char *);
int		change_pwd(t_shell *, char *);
int		print_with_opt(int, char **);
void		get_all_env(t_list *, char **);
void		*my_xrealloc(char *, int);
void		print_cmd(char **);
void		dircat(char *, char *);
int		go_to_arg(char **);
int		get_opt_n(char *, char *);
int		get_opt_e(char *, char *);
int		echo_with_opt(int, int, char **);
int		dirlen(char *);
int		is_in_env(t_list *, char *);
char		*modif_path(char *, char *);
char		*epur_path(char *);
char		*epur_pwd(char *);
char		*add_slash(char *);
char		*get_env_var(char *, int);
char		*check_env_var(t_list *, char *, int);
t_online	*online_mode();
char		**env_in_tab(t_list *list);

/*
** Prompt
*/

int		prompt(t_shell *shell);

#endif /* CORE_H_ */
