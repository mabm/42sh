/*
** line_editor.h for line_editor in /home/merran_g/work/c_elem/42sh/src/line_editor
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed May 14 15:12:40 2014 Geoffrey Merran
** Last update Sun May 25 04:45:26 2014 Geoffrey Merran
*/

#ifndef LINE_EDITOR_
# define LINE_EDITOR_
# define PROMPT "\033[1;31mMABMM[42sh] : \033[1;00m"
# define BUFFER_SIZE 20
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include "mysh.h"
# include "gnl.h"
# include "my.h"
# include "my_printf.h"

/*
** Cheat
**
** UP		27 [A
** DOWN		27 [B
** RIGHT        27 [C
** LEFT		27 [D
**
** DEL		^?
** SUPPR	^[[3~
** CTRL+D	^D
*/

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
  char		*save;
  int		size;
  int		size_max;
}		t_line;

enum e_dir
  {
    RIGHT, LEFT, UP, DOWN
  };

/*
** Line Editor main functions
*/

char	*line_editor(t_shell *shell);
int    	new_line_edit(t_line **line);
void   	delete_line_edit(t_line *line);
char   	*build_line(t_line *line);
int	init_line_editor(struct termios *t, struct termios *t_save, t_line **line);
int	init_term(struct termios *t, struct termios *t_save);
char	*reset_term(char *cmd, struct termios *t_save);
int    	show_edit_line(t_line *line);

/*
** Parser
*/

int	parser_line_editor(char *buffer, t_line **line, t_shell *shell);
void	parse_delete(char *buffer, t_line **line, int size);
int	parse_arrow(char *buffer, t_line **line, int size, t_shell *shell);

/*
** Parsing Interpretation
*/

int	move_history(int way, t_line **line, t_shell *shell);
int	move_history_up(t_line **line, t_shell *shell);
int	move_history_down(t_line **line, t_shell *shell);
int	load_history_line(t_hlist *hline, t_line **line);
void	move_cursor(int direction, t_line **line);


/*
** Char manipulation
*/

int    	add_char(char c, t_line **line);
int	delete_char(t_char *c, t_line **line);
int	write_prompt_char(t_char *c);
int	rev_mode(char c);

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
