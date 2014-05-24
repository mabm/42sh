#include <unistd.h>

int	*do_pipe(char *cmd1, char *cmd2, int *pipefd)
{
  pid_t	pid;
  int	pipefd2[2];
  char	buff[4096];

  pipe(pipefd2);
  if ((pid = fork()) == 0) // FILS
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	return;
      execlp("/bin/sh", "sh", "-c", cmd1);
    }
  else //PERE
    {
      close(pipefd[1]);
      if (dup2(pipefd[0], 0) == -1)
	return;

      close(pipefd2[0]);
      if (dup2(pipefd2[1], 1) == -1)
	return;

      execlp("/bin/sh", "sh", "-c", cmd2);

   }
  read(pipefd2[0], buff, 4096);
  printf(">> %s\n", buff);
  return (pipefd);
}

int	main(int ac, char *argv[])
{
  int	*pipefd;

  pipefd = malloc(2 * sizeof(*pipefd));
  pipe(pipefd);
  pipefd = do_pipe("env", "grep -e \"HOME\"", pipefd);
}
