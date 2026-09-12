NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft
MLX = mlx

INC = include

SRCS = src/error_exit.c src/utils.c src/load_images.c src/render_map.c src/flood_fill.c src/validate_map.c src/read_map.c \
	   src/close_game.c src/main.c 
OBJS = obj/error_exit.o obj/utils.o obj/load_images.o obj/render_map.o obj/flood_fill.o obj/validate_map.o obj/read_map.o \
       obj/close_game.o obj/main.o



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
