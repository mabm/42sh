/*
** jobcontrol.h for jobcontrol in /home/merran_g/work/c_elem/42sh/src/jobcontrol
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue May 27 15:36:16 2014 Geoffrey Merran
** Last update Tue May 27 23:13:42 2014 Jeremy Mediavilla
*/

#ifndef JOBCONTROL_
# define JOBCONTROL_
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include "mysh.h"
# include "my.h"

/*
** Built in
*/

int    	builtin_fg(t_shell *shell, char **cmd);
int    	builtin_jobs(t_shell *shell, char **cmd);

/*
** Jobs
*/

int	init_jobcontrol(t_shell **shell);
int    	add_job(int pid, char **cmd, t_bg **bg);
int    	restaure_jobs(t_bg *bg, t_blist *job);

#endif /* JOBCONTROL_ */
