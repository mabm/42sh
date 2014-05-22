##
## Makefile for  in /home/nicolas/Workspace/42sh
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Mon Apr 28 13:47:00 2014 Nicolas Ades
## Last update Thu May 22 14:32:43 2014 Geoffrey Merran
##

CC		=	gcc

RM		=	rm -f

NAME		=	mysh

IFLAGS		=	./includes/

CFLAGS		+=	-W -Wall -Wextra -pedantic -ansi -g3 -I$(IFLAGS)

D_CORE		=	src/core/
D_ENV		=	src/env/
D_BUILTIN	=	src/builtin/
D_HISTORY	=	src/history/
D_LINE_EDITOR	=	src/line_editor/
D_CONF		=	src/conf/

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
			$(D_HISTORY)histo_list.c		\
			$(D_HISTORY)history.c			\
			$(D_HISTORY)manage_history.c		\
			$(D_HISTORY)my_alloc_init.c		\
			$(D_HISTORY)xfunction.c			\
			$(D_CONF)conf.c				\


OBJ		=	$(SRC:.c=.o)

LIB		=	./libmy/
L_NAME		=	-lncurses -lmy

all		:	libs $(NAME)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(L_NAME) -L$(LIB)

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
