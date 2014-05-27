/*
** prompt.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:48:19 2014 Jeremy Mediavilla
** Last update Tue May 27 22:56:59 2014 Geoffrey Merran
*/

#include "core.h"
#include "gnl.h"

t_builtin	builtin[] =
  {
    {"env", aff_env},
    {"unsetenv", my_unsetenv},
    {"setenv", my_setenv},
    {"alias", builtin_alias},
    {"history", builtin_history},
    {"cd", my_cd}
  };

/*
** Ajouter des built-in seulement de la forme
**	int	my_builtin(t_shell *shell, char **cmd);
**
*/

int            check_builtin(t_shell *shell, char **cmd)
{
  int           i;

  i = 0;
  while (i < 6)
    {
      if (strncmp(cmd[0], builtin[i].name, strlen(builtin[i].name)) == 0)
	return (builtin[i].fptr(shell, cmd));
      i++;
    }
  return (1);
}

int		prompt(t_shell *shell)
{
  char		*cmd;

  cmd = line_editor(shell);
  if (cmd != NULL)
    {
      if (shell->end == 1)
	{
	  free(cmd);
	  return (0);
	}
      my_lexer(cmd);
      /* check_builtin(shell->env, cmd); */
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
