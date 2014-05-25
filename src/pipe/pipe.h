typedef struct		s_pipe
{
  int			i;
  char			buff[4096];
  int			status;
  int			pipefd[2];
  int			pipefd2[2];
  char			t[4096];
  int			pid;
  int			tmp;
  char			***cmds;
  int			total;
}			t_pipe;
