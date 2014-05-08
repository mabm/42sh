/*
** core.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:04 2014 Nicolas Ades
** Last update Thu May  8 16:13:42 2014 Jeremy Mediavilla
*/

#ifndef CORE_H_
# define CORE_H_

# include "my.h"
# include "main.h"
# include "my_list.h"

/* fonctions dans env.c */
void		get_all_env(t_list *, char **);
void		aff_env(t_list *);
int		is_in_env(t_list *, char *);
char		*get_env_var(char *, int);
char		*check_env_var(t_list *, char *, int);

/* fonctions dans prompt.c */

int		prompt(t_list *);

#endif /* CORE_H_ */
