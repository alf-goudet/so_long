NAME = so_long

MLX_PATH = mlx_linux
LIBFT_PATH = libft

LIB = libsolong.a
LIBFT = $(LIBFT_PATH)/libft.a
 
SRCS = test.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Required dependency linkings
LINK_SL = -L. -lsolong
LINK_FT = -Llibft -lft
LINK_MLX = -Lmlx_linux -lmlx
LINK_STD = -lX11 -lXext -lbsd -lm
LINKS = $(LINK_SL) $(LINK_MLX) $(LINK_STD) $(LINK_FT)

LIBS = $(LIB) 

all: sub-mods $(NAME)

sub-mods:
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(MLX_PATH)

# To compile all sources into objects
# ---
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(LIB) $^
	$(CC) $(CFLAGS) $(LINKS) -o $@

clean:
	$(MAKE) $@ -C $(MLX_PATH)
	$(MAKE) $@ -C $(LIBFT_PATH)
	rm -f $(OBJS) $(LIB)

# Note: There is no fclean rule in mlx
fclean: clean
	rm -f $(NAME)
	
re: fclean all
