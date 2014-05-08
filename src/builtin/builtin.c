/*
** builtin.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:12 2014 Jeremy Mediavilla
** Last update Thu May  8 16:58:57 2014 Jeremy Mediavilla
*/

#include "core.h"

void		my_unsetenv(t_list *list, char *cmd)
{
  (void)list;
  (void)cmd;
  printf("unsetenv OK\n");
}

void		my_setenv(t_list *list, char *cmd)
{
  (void)list;
  (void)cmd;
  printf("setenv OK\n");
}

void		my_cd(t_list *list, char *cmd)
{
 (void)list;
  (void)cmd;
  printf("cd OK\n");
}
