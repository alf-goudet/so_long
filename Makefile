NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft

INC = include

SRCS = src/print_error.c src/main.c 
OBJS = obj/print_error.o obj/main.o 

all: sub-mods $(NAME)

sub-mods:
	$(MAKE) -C $(LIBFT)
	@if [ ! -d obj ]; then mkdir obj; fi

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(LIBFT) -L$(LIBFT) -lft -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -I$(INC) -I$(LIBFT)/$(INC) $< -L$(LIBFT) -lft -o $@

clean:
	$(MAKE) $@ -C $(LIBFT)
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all
