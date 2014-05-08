/*
** core.h for  in /home/nicolas/Workspace/42sh/includes
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:04 2014 Nicolas Ades
** Last update Thu May  8 14:13:30 2014 Nicolas Ades
*/

#ifndef CORE_H_
# define CORE_H_

# include "main.h"
# include "my_list.h"
# include "my.h"

/* fonctions dans env.c */
void		get_all_env(t_list *, char **);
void		aff_env(t_list *);

/* fonctions dans prompt.c */

int		prompt(t_list *);

#endif /* CORE_H_ */
