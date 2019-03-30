CC=clang
CFLAGS=-Werror -Wextra -Wall -g -Ilibft -I. -Imlx -Iincludes -Ofast -finline-functions -fsanitize=address -march=native -pthread
LFLAGS=-L libft/ -lft -L mlx/ -lmlx -framework OpenGL -framework AppKit -pthread -fsanitize=address
NAME=fdf
SRC=$(wildcard src/*)
OBJ=$(SRC:src/%.c=%.o)
SHELL := /bin/bash

.PHONY: clean fclean all re norm norme debug test norman

VPATH = src obj libft/includes include

$(NAME): update $(OBJ)
	@make -C mlx
	@make -C libft
	@$(CC) -o $(NAME) obj/* $(LFLAGS)
	@echo "fdf build complete!"

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C mlx clean
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette src/. includes/.

update:
	@./update.sh

norme: norm

norman:
	-norminette * | grep -iv warning