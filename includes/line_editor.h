/*
** line_editor.h for line_editor in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:12:40 2014 Geoffrey Merran
** Last update Thu May 15 17:10:20 2014 Nicolas Ades
*/

#ifndef LINE_EDITOR_
# define LINE_EDITOR_
# define PROMPT "\033[1;31mMABM[42sh] : \033[1;00m"
# define BUFFER_SIZE 20
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>
# include "gnl.h"
# include "my.h"
# include "my_printf.h"

/*
** Line Editor Structs
*/

typedef struct	s_char
{
  char		c;
  int		cursor;
  struct s_char	*next;
  struct s_char	*prev;
}		t_char;

typedef	struct	s_line
{
  t_char	*head;
  t_char	*current;
  t_char	*tail;
  int		size;
}		t_line;

/*
** Line Editor main functions
*/

char	*line_editor();
int	init_line_editor(struct termios *t, struct termios *t_save, t_line **line);
int	init_term(struct termios *t, struct termios *t_save);
char	*reset_term(char *cmd, struct termios *t_save);
int    	show_edit_line(t_line *line);

/*
** Parser
*/

int	parser_line_editor(char *buffer, t_line **line);


/*
** Char manipulation
*/

int    	add_char(char c, t_line **line);
int	write_prompt_char(t_char *c);
int	rev_mode(char *str);

/*
** Termcaps
*/

int    	change_cursor(int visibility);
int	xtcsetattr(int fd, int option, struct termios *t);
int	xtcgetattr(int fd, struct termios *termios_p);
int	xtgetent(char *bp, char *name);
char	*xtgetstr(char *id, char **area);
int	raw_mode(struct termios *t);
int	hide_char(struct termios *t);


#endif /* LINE_EDITOR_ */
