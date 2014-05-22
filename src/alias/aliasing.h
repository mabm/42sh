/*
** aliasing.h for aliasing in /home/martel_c/rendu/42sh/aliasing
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Mon May 12 16:06:42 2014 martelliere
** Last update Thu May 22 06:17:34 2014 martelliere
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
# include		"my_list.h"

void			add_alias(t_list *list, char *name, char *content);
void			display_alias(t_list *list);
void			aliasing(t_list *list);
void			*my_xmalloc(int size);
void			*my_alloc_init(int size, char c);
char			*get_user_path_alias();
char			*find_alias(t_list *list, char *name);
char			**my_str_to_wordtab(char *str);
char			**my_str_to_wordtab2(char *str);
int			delete_alias(t_list *list, char *name);
int			write_alias(t_list *list, char *path);
int			xwrite(int fd, void *buf, int nbytes);
int			xopen(const char *path, int flags, mode_t mode);
int			xclose(int fd);
int			xfree(void *s);

#endif			/* _ALIASING_H_ */
