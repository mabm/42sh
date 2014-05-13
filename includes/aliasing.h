/*
** aliasing.h for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 16:06:42 2014 martelliere
** Last update Mon May 12 16:35:28 2014 martelliere
*/

#ifndef		ALIASING_H_
# define	ALIASING_H_

# include		<stdio.h>
# include		<stdlib.h>
# include		<string.h>
# include		<sys/types.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		"get_next_line.h"

typedef struct		s_alias
{
  char			*name;
  char			*content;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_aliasl
{
  t_alias		*first;
}			t_aliasl;

void			add_alias(t_aliasl *alias, char *name, char *content);
void			display_alias(t_aliasl *alias);
void			aliasing(t_aliasl *alias);
void			*my_xmalloc(int size);
void			*my_alloc_init(int size, char c);
t_aliasl		*init_aliasing(t_aliasl *alias);
char			*get_user_path();
char			*find_alias(t_aliasl *alias, char *name);
char			**my_str_to_wordtab(char *str);
char			**my_str_to_wordtab2(char *str);

#endif			/* _ALIASING_H_ */
