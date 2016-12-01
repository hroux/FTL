##
## Makefile for  in /home/hugues/DEVC/my_ftl
## 
## Made by ROUX Hugues
## Login   <roux_a@etna-alternance.net>
## 
## Started on  Mon Nov  7 09:18:12 2016 ROUX Hugues
## Last update Sat Nov 12 10:06:02 2016 ROUX Hugues
##

CC		=	gcc

NAME		=	my_ftl

SRC		=	main.c \
			air_shed.c \
			container.c \
			system_control.c \
			system_repair.c \
			my_string.c \
			readline.c \
			fnc_main.c \
			actions.c \
			ennemy.c \
			my_put_nbr.c \
			actions_bis.c \
			fnc_SDL.c \
			sound.c

OBJS		=	$(SRC:%.c=%.o)

RM		=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

LDFLAGS		=	-lSDL -lSDL_mixer

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean		:
			$(RM) $(OBJS)
			$(RM) $(NAME_LIB)

fclean		:	clean
			$(RM) $(NAME)

.PHONY		:	fclean all

re		:	fclean all
