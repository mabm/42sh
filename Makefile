##
## Makefile for  in /home/nicolas/Workspace/42sh
## 
## Made by Nicolas Ades
## Login   <nicolas@epitech.net>
## 
## Started on  Mon Apr 28 13:47:00 2014 Nicolas Ades
## Last update Mon Apr 28 14:44:55 2014 Nicolas Ades
##

CC		=	gcc

RM		=	rm -f

NAME		=	mysh

IFLAGS		=	-I./includes/

CFLAGS		+=	-W -Wall -Wextra -Werror -pedantic -ansi $(IFLAGS)

D_CORE		=	src/core/

D_ENV		=	src/env/

D_BUILTIN	=	src/builtin/

SRC		=	$(D_CORE)main.c			\
			$(D_CORE)prompt.c		\
			$(D_ENV)get_env.c		\

OBJ		=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re