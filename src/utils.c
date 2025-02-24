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

void	ft_save_p_cor(t_data *data, char **map)
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

void	ft_alloc_map(t_data *data, char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
		i++;
	data->heapptr_map = malloc((i + 1) * sizeof(char *));
	if (!data->heapptr_map)
		return ;
	i = 0;
	while (map && map[i])
	{
		data->heapptr_map[i] = ft_strdup(map[i]);
		i++;
	}
	data->heapptr_map[i] = NULL;
}

void	checking_path(t_data, data->x_cor, data->y_cor, n)
{

}
