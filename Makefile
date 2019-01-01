CC=clang
CFLAGS=-Werror -Wextra -Wall -I libft/includes -I mlx -I includes
LFLAGS=-L libft/ -lft -L mlx/ -lmlx -framework OpenGL -framework AppKit
NAME=fdf
SRC=main.c event.c image.c vector.c reader.c
_SRC=$(SRC:%=src/%)

_OBJ=$(SRC:%.c=%.o)
OBJ=$(_OBJ:%=obj/%)

.PHONY: clean fclean all re norm norme debug

VPATH = src obj libft/includes includes src/str

$(NAME): $(_OBJ)
	@make -C libft
	@make -C mlx 
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo done

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) -g $(CFLAGS) -o obj/$@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@make -C mlx clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

norm:
	norminette $(_SRC) includes/*

norme: norm
