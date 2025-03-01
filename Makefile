NAME = so_long
 src = src/main.c src/free.c src/reading_map.c src/extention_checker.c src/error.c src/checking_map.c libft/ft_itoa.c \
 		libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
 		libft/ft_strlen.c libft/ft_substr.c src/check_map_path.c src/utils.c
objf = $(src:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -g3
HEADER = so_long.h

all:${NAME}

bonus : all

$(NAME): $(objf)
	cc $(CFLAGS) $(objf) -o $(NAME)

src/%.o: src/%.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(objf)

fclean:clean
	rm -rf $(NAME)

re: fclean all