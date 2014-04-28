/*
** main.c for  in /home/nicolas/Workspace/42sh/src/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Mon Apr 28 13:51:55 2014 Nicolas Ades
** Last update Mon Apr 28 13:55:56 2014 Nicolas Ades
*/

#include "main.h"

int	main(int ac, char **av, char **envp)
{
  (void)ac;
  (void)av;
  if (get_env(envp) == -1)
    return (-1);
  if (prompt == 0)
    return (O);
}
