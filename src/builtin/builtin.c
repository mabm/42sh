/*
** builtin.c for  in /home/mediav_j/mabm/42sh/src/builtin
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:12 2014 Jeremy Mediavilla
** Last update Thu May  8 18:31:13 2014 Jeremy Mediavilla
*/

#include "core.h"

int             already_here(t_list *list, char *var, int len)
{
  while (list != NULL)
    {
      if (list->data != NULL)
        if (strncmp(list->data, var, len) == 0)
          {
            memset(list->data, '\0', strlen(list->data));
            list->data = var;
            return (1);
          }
      list = list->next;
    }
  return (0);
}

void		my_unsetenv(t_list *list, char *cmd)
{
  char          *var;
  int           name_len;
  char		**command;

  command = my_strd_to_wordtab(cmd, " \t");
  if (tab_size(command) != 2)
    printf("Unsetenv : wrong number of arguments\n");
  else
    {
      name_len = strlen(command[1]);
      var = init_unsetenv_var(name_len, command);
      while (list != NULL)
	{
	  if (list->data != NULL)
	    if (strncmp(list->data, var, (name_len + 1)) == 0)
	      {
		remove_from_list(list);
		return ;
	      }
	  list = list->next;
	}
      printf("%s : is not an environment variable\n", command[1]);
      free(var);
    }
}

void		my_setenv(t_list *list, char *cmd)
{
  char          *var;
  int           name_len;
  int           value_len;
  char		**command;

  command = my_strd_to_wordtab(cmd, " \t");
  if (tab_size(command) != 3)
    printf("Setenv : wrong number of arguments\n");
  else
    {
      name_len = strlen(command[1]);
      value_len = strlen(command[2]);
      var = my_xmalloc((name_len + value_len + 2) * sizeof(char));
      memset(var, '\0' , (name_len + value_len + 2));
      var = strcat(var, command[1]);
      var = strcat(var, "=");
      var = strcat(var, command[2]);
      if (already_here(list, var, (name_len + 1)) != 1)
	add_to_end(list, var);
    }
}

void		my_cd(t_list *list, char *cmd)
{
  (void)list;
  (void)cmd;
  printf("cd OK\n");
}
