/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:37:37 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 16:55:27 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_coins_number(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_save_p_cor_data(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->x_cor = j;
				data->y_cor = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_alloc_map_data(t_data *data, char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
		i++;
	data->map_ptr = malloc((i + 1) * sizeof(char *));
	if (!data->map_ptr)
		return ;
	i = 0;
	while (map && map[i])
	{
		data->map_ptr[i] = ft_strdup(map[i]);
		i++;
	}
	data->map_ptr[i] = NULL;
}

int	check_next_move(t_data *data, int y, int x, int n)
{
	if (n == 0)
	{
		if (data->map_ptr[y][x] == '1' || data->map_ptr[y][x] == 'E')
			return (0);
		else if (data->map_ptr[y][x] == 'C')
		{
			data->map_ptr[y][x] = '0';
			data->coins--;
		}
	}
	else if (n == 1)
	{
		if (data->map_ptr[y][x] == '1')
			return (0);
		if (data->map_ptr[y][x] == 'E')
		{
			data->map_ptr[y][x] = '0';
			data->exit = 0;
		}
	}
	return (1);
}

void	checking_path(t_data *data, int x_cor, int y_cor, int n)
{
	if (y_cor > data->nb_lines || x_cor > data->line_len)
		return ;
	if (y_cor < 0 || x_cor < 0)
		return ;
	data->map_ptr[y_cor][x_cor] = '1';
	if (check_next_move(data, y_cor, x_cor + 1, n) != 0)
		checking_path(data, y_cor, x_cor + 1, n);
	if (check_next_move(data, y_cor, x_cor - 1, n) != 0)
		checking_path(data, y_cor, x_cor - 1, n);
	if (check_next_move(data, y_cor + 1, x_cor, n) != 0)
		checking_path(data, y_cor + 1, x_cor, n);
	if (check_next_move(data, y_cor - 1, x_cor, n) != 0)
		checking_path(data, y_cor - 1, x_cor, n);
}
