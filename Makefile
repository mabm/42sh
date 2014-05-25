##
## Makefile for Makefile in /home/merran_g/work/c_elem/42sh
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sat May 24 01:20:58 2014 Geoffrey Merran
## Last update Sat May 24 21:51:42 2014 Geoffrey Merran
##

CC		=	gcc

RM		=	rm -f

NAME		=	42sh

IFLAGS		=	./includes/

CFLAGS		+=	-W -Wextra -Wall -g3 -I$(IFLAGS) -I./mysql/include

D_CORE		=	src/core/
D_ENV		=	src/env/
D_BUILTIN	=	src/builtin/
D_HISTORY	=	src/history/
D_LINE_EDITOR	=	src/line_editor/
D_CONF		=	src/conf/
D_FREE		=	src/free/
D_ONLINE	=	src/online/
D_ALIAS		=	src/alias/

SRC		=	$(D_CORE)main.c				\
			$(D_CORE)prompt.c			\
			$(D_CORE)gnl.c				\
			$(D_CORE)tab_functions.c		\
			$(D_BUILTIN)env.c			\
			$(D_BUILTIN)builtin.c			\
			$(D_CORE)list.c				\
			$(D_CORE)init.c				\
			$(D_LINE_EDITOR)line_editor.c		\
			$(D_LINE_EDITOR)xfunction.c		\
			$(D_LINE_EDITOR)term_fct.c		\
			$(D_LINE_EDITOR)char.c			\
			$(D_LINE_EDITOR)char2.c			\
			$(D_LINE_EDITOR)parser_line_editor.c	\
			$(D_LINE_EDITOR)build_line.c		\
			$(D_LINE_EDITOR)history_interaction.c	\
			$(D_HISTORY)histo_list.c		\
			$(D_HISTORY)history.c			\
			$(D_HISTORY)manage_history.c		\
			$(D_HISTORY)my_alloc_init.c		\
			$(D_HISTORY)xfunction.c			\
			$(D_ALIAS)aliasing.c			\
			$(D_ALIAS)load_alias.c			\
			$(D_ALIAS)manage_alias.c		\
			$(D_CONF)conf.c				\
			$(D_CONF)default.c				\
			$(D_FREE)free_shell.c			\
			$(D_ONLINE)curse.c			\

OBJ		=	$(SRC:.c=.o)

LIB		=	./libmy/
L_NAME		=	-lmy -lncurses -lmysqlclient

all		:	libs $(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) `mysql_config --libs`  $(L_NAME) -L$(LIB)

libs		:
			make -C $(LIB)

clean		:
			(cd $(LIB); make clean)
			$(RM) $(OBJ)

fclean		:	clean
			(cd $(LIB); make fclean)
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re libs
