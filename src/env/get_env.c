/*
** get_env.c for  in /home/nicolas/Workspace/42sh/src/env
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 14:07:47 2014 Nicolas Ades
** Last update Tue Apr 29 09:40:02 2014 Nicolas Ades
*/

#include "env.h"

int	get_path(t_env *i_env)
{
  int	i;

  i = 0;
  while (i_env->env[i] != NULL)
    {
      if (my_strncmp("PATH=", i_env->env[i], 5) == 0)
	{
	  i_env->path = my_strd_to_wordtab(i_env->env[i], ';');
	  return (0);
	}
      i++;
    }
  return (-1);
}

int	check_env(char **envp, t_env *i_env)
{
  if (envp == NULL)
    {
      printf("Env is empty\n");
      return (-1);
    }
  else
    {
      if (get_env(envp, i_env) == -1)
      return (0);
    }
}

int	get_env(char **envp, t_env *i_env)
{
  i_env = malloc(sizeof(*i_env));
  i_env->env = my_strd_to_wordtab(envp, '\n'); 
  if (get_path(i_env) == -1)
    {
      printf("Path is missing\n");
      return (0);
    }
}
