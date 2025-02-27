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

int		main(int ac, char **av);
void	ft_error(char *str);
void	ft_ex_checker(char *str);
char	**reading_map(int fd);
void	checking_map(char **map);
void	ft_free(char **s);
int		path_checker(char **map, int n);
void	ft_save_p_cor(t_data *data, char **map);
void	ft_alloc_map(t_data *data, char **map);
void	checking_path(t_data *data, int x_cor, int y_cor, int n);
int		ft_coins_number(char **map);
void	free_data(t_data *data);
int		check_next_move(t_data *data, int y, int x, int n);

#endif
