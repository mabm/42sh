/*
** get_env.c for  in /home/nicolas/Workspace/42sh/src/env
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 14:07:47 2014 Nicolas Ades
** Last update Mon Apr 28 16:02:53 2014 Nicolas Ades
*/

#include "env.h"

int	check_env(char **envp)
{

}

int	get_env(char **envp)
{
  t_env	*i_env;

  i_env = malloc(sizeof(*i_env));
  check_env(envp);
  i_env->env = my_strd_to_wordtab(envp); 

  return (0);
}
