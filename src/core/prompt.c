/*
** prompt.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:48:19 2014 Jeremy Mediavilla
** Last update Sat May 24 16:05:01 2014 Geoffrey Merran
*/

#include "core.h"
#include "gnl.h"

void            check_builtin(t_list *list, char *cmd)
{
  char          *mtab[5];
  void          (*which_builtin[5])(t_list *, char *);
  int           i;

  mtab[0] = "env";
  mtab[1] = "unsetenv";
  mtab[2] = "setenv";
  mtab[3] = "cd";
  mtab[4] = "echo";
  which_builtin[0] = &aff_env;
  which_builtin[1] = &my_unsetenv;
  which_builtin[2] = &my_setenv;
  which_builtin[3] = &my_cd;
  which_builtin[4] = &my_echo;
  i = 0;
  while (i < 5)
    {
      if (strncmp(cmd, mtab[i], strlen(mtab[i])) == 0)
        {
          (*which_builtin[i])(list, cmd);
          i = 5;
        }
      i++;
    }
  if (i == 5)
    fprintf(stderr, "%s : n'est pas une commande\n", cmd);
}

int		prompt(t_shell *shell)
{
  char		*cmd;

  cmd = line_editor(shell);
  if (cmd != NULL)
    {
      if (strncmp(cmd, "exit", 4) == 0)
	{
	  free(cmd);
	  return (0);
	}
      check_builtin(shell->env, cmd);
      add_cmd(shell->history, cmd);
      free(cmd);
      shell->error = 0;
    }
  else
    shell->error++;
  if (shell->error == 10)
    return (my_error("42sh: critical errors: too much error, \
can't continue. Exiting\n"));
  prompt(shell);
  return (0);
}
