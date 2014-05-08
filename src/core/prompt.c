/*
** prompt.c for  in /home/mediav_j/mabm/42sh/src/core
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:48:19 2014 Jeremy Mediavilla
** Last update Thu May  8 17:03:01 2014 Jeremy Mediavilla
*/

#include "core.h"
#include "gnl.h"

void            check_builtin(t_list *list, char *cmd)
{
  char          *tab[4];
  void          (*which_builtin[4])(t_list *, char *);
  int           i;

  tab[0] = "env";
  tab[1] = "unsetenv";
  tab[2] = "setenv";
  tab[3] = "cd";
  which_builtin[0] = &aff_env;
  which_builtin[1] = &my_unsetenv;
  which_builtin[2] = &my_setenv;
  which_builtin[3] = &my_cd;
  i = 0;
  while (i < 4)
    {
      if (strncmp(cmd, tab[i], strlen(tab[i])) == 0)
        {
          (*which_builtin[i])(list, cmd);
          i = 5;
        }
      i++;
    }
  if (i == 4)
    printf("%s : n'est pas une commande\n", cmd);
}

int		prompt(t_list *env)
{
  char		*cmd;

  my_putstr("\033[1;31mMABM[42sh] : \033[1;00m");
  cmd = get_next_line(0);
  if (strcmp(cmd, "exit") == 0)
    return (0);
  /* fonction parsing et edition de ligne */
  check_builtin(env, cmd);
  free(cmd);
  prompt(env);
  return (0);
}
