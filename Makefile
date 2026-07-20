NAME = so_long

MLX_PATH = minilibx-linux
FTPRINTF_PATH = ft_printf
LIBFT_PATH = libft

LIB = libsolong.a
LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(FTPRINTF_PATH)/libftprintf.a
LIBMLX = $(MLX_PATH)/libmlx.a

LIBS = $(LIB) $(LIBMLX) $(LIBFTPRINTF) $(LIBFT) 
SRCS = main.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: sub-mods $(NAME)

sub-mods:
	$(MAKE) -C $(FTPRINTF_PATH)
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS)
	ar rcs $(LIB) $^
	$(CC) $(CFLAGS) $(LIBS) -o $@

clean:
	$(MAKE) $@ -C $(MLX_PATH)
	$(MAKE) $@ -C $(FTPRINTF_PATH)
	$(MAKE) $@ -C $(LIBFT_PATH)
	rm -f $(OBJS) $(LIB)

# Note: There is no fclean rule in mlx
fclean: clean
	$(MAKE) $@ -C $(FTPRINTF_PATH)
	$(MAKE) $@ -C $(LIBFT_PATH)
	rm -f $(NAME)
	
re: fclean all
