#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <42sh.h>

void	call_child(int *p, t_cmds *tree)
{
  int	ret;

  close(p[0]);
  dup2(p[1], 1);
  close(p[1]);
  if (ft_redir_right(tree) || ft_redir_left(tree))
    exit(-1);
  ret = implemented_function(get_env()->datas, tree->cmd);
  if (ret == 0)
    execution(tree);
  if (ret == 1)
    exit(0);
  if (ret == -1)
    exit(0);
}

void	call_father(int *p, t_cmds *tree)
{
  close(p[1]);
  dup2(p[0], 0);
  close(p[0]);
  exec_tree(tree);
  exit(0);
}

int	grand_father(int *p, t_cmds *tree, int pid)
{
  wait(&pid);
  if (!ft_strcmp(tree->right->cmd[0], "exit"))
    ft_exit(get_env()->datas, ft_atoi(tree->right->cmd[1]));
  pid = fork();
  if (pid == -1)
    {
      ft_putstr_fd("42sh : fork failed\n", 2);
      return (-1);
    }
  if (pid == 0)
    call_father(p, tree->right);
  else
    {
      close(p[0]);
      close(p[1]);
      wait(&pid);
    }
  return (0);
}

int	ft_pipe(t_cmds *tree)
{
  pid_tpid;
  intp[2];

  if (pipe(p) == -1)
    {
      printf("Pipe failed\n");
      return (-1);
    }
  pid = fork();
  if (pid == -1)
    {
      printf("Fork Failed\n");
      return (-1);
    }
  if (pid == 0)
    call_child(p, tree->left);
  else if (grand_father(p, tree, pid))
    return (-1);
  return (0);
}