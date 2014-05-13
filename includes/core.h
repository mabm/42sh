/*
** core.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:04 2014 Nicolas Ades
** Last update Tue May 13 15:44:39 2014 Nicolas Ades
*/

#ifndef		CORE_H_
# define	CORE_H_

# include "main.h"
# include "my_list.h"
# include "my.h"

/* fonctions dans init.c */
char		*init_unsetenv_var(int, char **);

/* fonctions dans tab_functions.c */
int		tab_size(char **);
void		print_tab(char **);

/* fonctions dans builtin.c */
void		my_setenv(t_list *, char *);
void		my_unsetenv(t_list *, char *);
void		my_cd(t_list *, char *);

/* fonctions dans env.c */
void		get_all_env(t_list *, char **);
void		aff_env(t_list *, char *);
int		is_in_env(t_list *, char *);
char		*get_env_var(char *, int);
char		*check_env_var(t_list *, char *, int);

/* fonctions dans prompt.c */
int		prompt(t_list *);

#endif /* CORE_H_ */
