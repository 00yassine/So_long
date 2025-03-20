NAME = so_long
 src = src/main.c src/free.c src/reading_map.c src/extention_checker.c src/error.c src/checking_map.c libft/ft_itoa.c \
 		libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
 		libft/ft_strlen.c libft/ft_substr.c src/check_map_path.c src/utils.c src/begin_game.c src/utils2.c src/drawing.c
objf = $(src:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = so_long.h

all:${NAME}

bonus : all

$(NAME): $(objf)
	cc $(CFLAGS) $(objf) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(objf)

fclean:clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY : ${objf}
