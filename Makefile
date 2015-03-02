#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/29 16:38:06 by fdeage            #+#    #+#              #
#    Updated: 2015/03/02 15:34:40 by fdeage           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	game_2048

DIR_SRC		=	srcs
SRC 		=	main.c	\
				reinit_color.c	\
				new_tile.c	\
				run.c	\
				compute.c	\
				display.c	\
				redim.c	\
				get_color.c	\
				exit.c

#OBJ			=	$(addprefix $(DIR_SRC)/, $(SRC:.c=.o))
OBJ			=	$(SRC:.c=.o)

INC			=	-I ./includes -I ./libft/includes
LINK		=	-L./libft -lft -lncurses

FLAGS		=	$(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-function
P			=	-pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes	\
				-Qunused-arguments -g3

CC			=	$(CLANG)
GCC			=	/usr/local/bin/gcc
CLANG		=	/usr/bin/clang
RM			=	/bin/rm -v
MAKE		=	/usr/bin/make

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(MAKE) -C ./libft
				$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
				$(MAKE) -C ./libft clean
				$(RM) $(DIRC_SRC)/$(OBJ)

fclean		:	clean
				$(MAKE) -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

#%.o			:	$(DIR_SRC)/%.c
%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY		:	all clean fclean re extra
