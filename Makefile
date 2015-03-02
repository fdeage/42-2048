#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/29 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/03/01 22:22:23 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	game_2048

SRC 		=	main.c	\
				reinit_color.c	\
				new_tile.c	\
				run.c	\
				compute.c	\
				display.c	\
				redim.c	\
				get_color.c	\
				exit.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I ./includes -I ./libft/includes
LINK		=	-L./libft -lft -lncurses

FLAGS		=	$(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -Wno-unneeded-internal-declaration \
				-Wno-unused-function
P			=	-pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes	\
				-Qunused-arguments -g3

CC			=	$(CLANG)
GCC			=	/usr/local/bin/gcc
CLANG		=	/usr/bin/clang
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ./libft
				$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
				make -C ./libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
