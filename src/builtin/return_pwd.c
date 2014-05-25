/*
** return_pwd.c for 42 in /home/jobertomeu/Work/42sh/src/builtin
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 19:23:05 2014 Joris Bertomeu
** Last update Sun May 25 20:04:03 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "../../include/mysh.h"

char	*return_pwd()
{
  int	pipefd[2];
  char	*tab[] = {"pwd", NULL};
  char	*pwd_return;
  char	*tmp;
  int	i;
  t_shell	*shell;

  i = 0;
  pipe(pipefd);
  if (fork() == 0)
    {
      dup2(pipefd[1], 1);
      execution_without_fork(shell, tab);
    }
  tmp = malloc(256 * sizeof(char));
  memset(tmp, 0, 256);
  read(pipefd[0], tmp, 4096);
  pwd_return = malloc((strlen(tmp) + 1) * sizeof(*pwd_return));
  while (tmp[i] != '\n' && tmp[i])
    {
      pwd_return[i] = tmp[i];
      i++;
    }
  pwd_return[i] = 0;
  free(tmp);
  return (pwd_return);
}

int	main()
{
  char	*pwd;

  pwd = return_pwd();
  printf("PWD : %s\n", pwd);
}
