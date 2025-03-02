/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:57:47 by yassine           #+#    #+#             */
/*   Updated: 2025/02/24 16:51:26 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <mlx.h>
# include "minilibx-linux/mlx.h"

typedef struct a_data
{
	char	**map_ptr;
	int		x_cor;
	int		y_cor;
	int		coins;
	int		exit;
	int		nb_lines;
	int		line_len;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;
	int		nb_m;
	int		coins;
	char	**map_ptr;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;

}	t_game;

int		main(int ac, char **av);
void	ft_error(char *str);
void	ft_ex_checker(char *str);
char	**reading_map(int fd);
void	checking_map(char **map);
void	ft_free(char **s);
int		path_checker(char **map, int n);
void	ft_save_p_cor_data(t_data *data, char **map);
void	ft_save_p_cor_game(t_game *game, char **map);
void	ft_alloc_map_data(t_data *data, char **map);
void	ft_alloc_map_game(t_game *game, char **map);
void	checking_path(t_data *data, int x_cor, int y_cor, int n);
int		ft_coins_number(char **map);
void	free_data(t_data *data);
int		check_next_move(t_data *data, int y, int x, int n);
void    begin_game(char **map);
void    set_img_to_window(t_game *game, char **map, int x, int y);
void    set_image(t_game *game);
void	save_position(t_game *game, char **map);
void	ft_alloc_map_game(t_game *game, char **map);
void	check_xpm(void *s, t_game *game);
void	free_data_map(t_data *data, char **map);
int 	func_hook(t_game *game);
void	destroy_game(t_game *game);
int		keyhook(int keycode, t_game *game);
int		collec_check(t_game *game);
void	print_move(t_game *game);
void	func_move(int keycode, int x, int y, t_game *game);

#endif
