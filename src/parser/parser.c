/*
** parser.c for  in /home/mediav_j/mabm/42sh/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Wed May  7 17:42:35 2014 Jeremy Mediavilla
** Last update Sun May 25 18:28:05 2014 Geoffrey Merran
*/

#include "parser.h"

int		my_parser(t_link *list)
{
  t_link	*tmp;

  tmp = list;
  if (tmp->next != NULL && tmp->type == -1)
    tmp = tmp->next;
  while (tmp != NULL)
    {
      printf("--->[%s][%i]\n", tmp->data, tmp->type);
      tmp = tmp->next;
    }
  return (0);
}

int		my_parser_check(t_link *list, char *cmd)
{
  t_tree	*tree;
  t_link	*tmp;

  tmp = list;
  printf("\n%s\n\n", cmd);
  if ((tree = init_access()) == NULL)
    return (-1);
  while (tmp != NULL)
    {
      if (tmp != NULL && (int)tmp->type != -1)
	if (check_token_succession(tmp, tree) == -1)
	  remove_unvalid_links(&tmp);
      if (tmp != NULL)
	tmp = tmp->next;
    }
  tmp = list;
  remove_old_links(&tmp, &list);
  aff_my_list(list);
  my_parser(list);
  return (0);
}

int		my_lexer(char *cmd)
{
  int		i;
  int		len;
  t_link	*list;

  if (cmd == NULL)
    {
      my_puterr("Lexer error : param is equal to NULL\n");
      return (-1);
    }
  if ((list = init_list(NULL, -1)) == NULL)
    return (-1);
  i = 0;
  len = strlen(cmd);
  while (i < len)
    {
      if (cmd[i] == ' ' || cmd[i] == '\n' || cmd[i] == '\t')
	i++;
      else
	if (check_token(cmd, &i, list) == -1)
	  return (-1);
    }
  if (my_parser_check(list, cmd) == -1)
    return (-1);
  return (0);
}
