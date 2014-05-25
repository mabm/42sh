##
## Makefile for  in /home/mediav_j/mabm/42sh/src/parser
## 
## Made by Jeremy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Wed May 14 10:59:00 2014 Jeremy Mediavilla
## Last update Sun May 25 11:54:59 2014 Jeremy Mediavilla
##

CC		=	gcc

RM		=	rm -f

NAME		=	parser

IFLAGS		=	../../includes/

CFLAGS		+=	-W -Wall -Wextra -pedantic -ansi -g3 -I$(IFLAGS)

SRC		=	parser.c	\
			list2.c		\
			tree.c		\
			access.c	\
			type.c		\
			remove.c	\
			token.c		\
			token2.c	\
			parser_tools.c	\
			parser_tools2.c	\

OBJ		=	$(SRC:.c=.o)

LIB		=	../../libmy/
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
