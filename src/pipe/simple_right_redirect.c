/*
** simple_right.c for 42 in /home/jobertomeu/Work/42sh/src/pipe
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sun May 25 05:58:25 2014 Joris Bertomeu
** Last update Sun May 25 06:12:08 2014 Joris Bertomeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	start_right_redirect(char **cmd)
{
  int	fd;
  int	pipefd[2];
  int	i;
  char	*tab[] = {"ls", "-l", NULL};
  char	*s;
  char	buff[4096];

  i = 0;
  pipe(pipefd);
  if (fork() == 0)
    {
      dup2(pipefd[1], 1);
      execvp("/bin/ls", tab);
      perror("Error : ");
      close(pipefd[0]);
    }
  else
    wait(NULL);
  if ((fd = open(cmd[1], O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    perror("Erreur : ");
  read(pipefd[0], buff, 4096);
  close(pipefd[0]);
  write(fd, buff, strlen(buff));
}

int	main()
{
  char	**cmd;

  cmd = malloc(2 * sizeof(char*));
  cmd[0] = malloc(128 * sizeof(char));
  cmd[1] = malloc(128 * sizeof(char));
  strcpy(cmd[0], "ls -l");
  strcpy(cmd[1], "result");
  start_right_redirect(cmd);
}
