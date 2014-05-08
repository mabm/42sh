##
## Makefile for  in /home/nicolas/Workspace/42sh
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Mon Apr 28 13:47:00 2014 Nicolas Ades
## Last update Thu May  8 16:57:09 2014 Jeremy Mediavilla
##

CC		=	gcc

RM		=	rm -f

NAME		=	mysh

IFLAGS		=	./includes/

CFLAGS		+=	-W -Wall -Wextra -Werror -pedantic -ansi -g3 -I$(IFLAGS)

D_CORE		=	src/core/

D_ENV		=	src/env/

D_BUILTIN	=	src/builtin/

SRC		=	$(D_CORE)main.c			\
			$(D_CORE)prompt.c		\
			$(D_CORE)gnl.c			\
			$(D_BUILTIN)env.c		\
			$(D_BUILTIN)builtin.c		\
			$(D_CORE)list.c			\

OBJ		=	$(SRC:.c=.o)

LIB		=	./libmy/
L_NAME		=	-lmy

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
