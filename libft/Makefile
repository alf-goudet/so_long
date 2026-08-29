NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
       ft_uitoa.c ft_ltoa.c ft_ultoa.c ft_uintlen.c ft_ulonglen.c \
       ft_printf.c ft_printf_convs.c ft_printf_convs_long.c ft_printf_utils.c \
       ft_printf_utils_long.c get_next_line.c \
       
OBJS = obj/ft_isalpha.o obj/ft_isdigit.o obj/ft_isalnum.o obj/ft_isascii.o obj/ft_isprint.o \
       obj/ft_strlen.o obj/ft_memset.o obj/ft_bzero.o obj/ft_memcpy.o obj/ft_memmove.o \
       obj/ft_strlcpy.o obj/ft_strlcat.o obj/ft_toupper.o obj/ft_tolower.o obj/ft_strchr.o \
       obj/ft_strrchr.o obj/ft_strncmp.o obj/ft_memchr.o obj/ft_memcmp.o obj/ft_strnstr.o \
       obj/ft_atoi.o obj/ft_calloc.o obj/ft_strdup.o obj/ft_substr.o obj/ft_strjoin.o \
       obj/ft_strtrim.o obj/ft_split.o obj/ft_itoa.o obj/ft_strmapi.o obj/ft_striteri.o \
       obj/ft_putchar_fd.o obj/ft_putstr_fd.o obj/ft_putendl_fd.o obj/ft_putnbr_fd.o  \
       obj/ft_uitoa.o obj/ft_ltoa.o obj/ft_ultoa.o obj/ft_uintlen.o obj/ft_ulonglen.o \
       obj/ft_printf.o obj/ft_printf_convs.o obj/ft_printf_convs_long.o obj/ft_printf_utils.o \
       obj/ft_printf_utils_long.o obj/get_next_line.o \

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

INC = include

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

obj/%.o: ./%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -I$(INC) $< -o $@

clean:
	rm -rf obj $(NAME)
