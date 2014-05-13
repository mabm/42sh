/*
** history.c for history 42sh in /home/martel_c/rendu/42sh
**
** Made by martelliere
** Login   <martel_c@epitech.net>
**
** Started on  Fri May  9 15:49:56 2014 martelliere
** Last update Sat May 10 16:30:02 2014 martelliere
*/

#include "history.h"

void		history()
{
  t_cmdl	*history;

  history = init_history(history);
  get_history(history);
  save_history(history);
}
