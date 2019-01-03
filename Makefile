CC=clang
CFLAGS=-Werror -Wextra -Wall -I libft/includes -I mlx -I includes
LFLAGS=-L libft/ -lft -L mlx/ -lmlx -framework OpenGL -framework AppKit
NAME=fdf
SRC=main.c event.c image.c vector.c reader.c map.c

OBJ=$(SRC:%.c=%.o)

.PHONY: clean fclean all re norm norme debug

VPATH = src obj libft/includes includes

$(NAME): $(OBJ)
	@make -C libft
	@make -C mlx 
	@$(CC) -o $(NAME) obj/* $(LFLAGS)
	@echo done

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) -g $(CFLAGS) -o obj/$@ -c $<

clean:
	@rm -rf obj/
	@make -C libft clean
	@make -C mlx clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

norm:
	norminette src/. includes/*

norme: norm
