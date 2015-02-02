##
## Makefile for robby in /home/nguye_1//projects/prog_elem_c/robby
## 
## Made by alexandre1 nguyen
## Login   <nguye_1@epitech.net>
## 
## Started on  Thu Jun 20 16:20:01 2013 alexandre1 nguyen
## Last update Fri Jun 28 00:01:25 2013 alexandre1 nguyen
##

NAME=		robby

SRCS=		src/main.c			\
		src/telephone.c			\
		src/telephone_dictionnary.c	\
		src/aspirateur.c		\
		src/aspirateur_parsing.c	\
		src/aspirateur_algorithm.c	\
		src/cuisine.c			\
		src/error_msg.c			\
		src/basic_tools.c

OBJS=		$(SRCS:.c=.o)

CC=		gcc

RM=		rm -f

CFLAGS=		-W -Wall -Werror -Wextra -g -g3

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)