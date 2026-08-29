NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft
MLX = mlx

INC = include

SRCS = src/error_exit.c src/main.c 
OBJS = obj/error_exit.o obj/main.o



all: sub-mods $(NAME)

sub-mods:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -Lmlx -lmlx -lX11 -lXext -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -I$(INC) -I$(LIBFT)/$(INC) -I$(MLX) $< -L$(LIBFT) -lft -o $@

clean:
	$(MAKE) $@ -C $(LIBFT)
	$(MAKE) $@ -C $(MLX)
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all sub-mods clean fclean re
