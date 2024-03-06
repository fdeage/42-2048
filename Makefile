NAME=2048

CC=gcc
FLAGS=-Wall -Wextra -Werror
EXTRAFLAGS=-pedantic -Weverything -Wno-missing-prototypes

LIBFT=./libft.a
SRC_DIR=./src
INCLUDE_DIR=./include

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(SRC:.c=.o)

COL_B=\033[1;34m
COL_G=\033[1;32m
COL_RES=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lncurses libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	-@rm $(OBJ)

fclean : clean
	@rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
