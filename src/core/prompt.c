/*
** prompt.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:48:19 2014 Jeremy Mediavilla
** Last update Thu May 15 20:29:28 2014 Geoffrey Merran
*/

#include "core.h"
#include "gnl.h"

void            check_builtin(t_list *list, char *cmd)
{
  char          *mtab[4];
  void          (*which_builtin[4])(t_list *, char *);
  int           i;

  mtab[0] = "env";
  mtab[1] = "unsetenv";
  mtab[2] = "setenv";
  mtab[3] = "cd";
  which_builtin[0] = &aff_env;
  which_builtin[1] = &my_unsetenv;
  which_builtin[2] = &my_setenv;
  which_builtin[3] = &my_cd;
  i = 0;
  while (i < 4)
    {
      if (strncmp(cmd, mtab[i], strlen(mtab[i])) == 0)
        {
          (*which_builtin[i])(list, cmd);
          i = 5;
        }
      i++;
    }
  if (i == 4)
    fprintf(stderr, "%s : n'est pas une commande\n", cmd);
}

int		prompt(t_list *env)
{
  char		*cmd;

  cmd = line_editor();
  if (cmd != NULL)
    {
      if (strncmp(cmd, "exit", 4) == 0)
	return (0);
      check_builtin(env, cmd);
      free(cmd);
    }
  prompt(env);
  return (0);
}
