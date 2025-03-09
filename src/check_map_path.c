/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:54:45 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 16:32:25 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_checker(char **map, int n)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->coins = ft_coins_number(map);
	data->exit = 1;
	ft_save_p_cor_data(data, map);
	ft_alloc_map_data(data, map);
	data->line_len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
		i++;
	data->nb_lines = i;
	checking_path(data, data->y_cor, data->x_cor, n);
	if ((n == 1 && data->exit == 0) || (n == 0 && data->coins == 0))
		return (free_data(data), 0);
	free_data(data);
	ft_free(map);
	ft_error("Error\n:⚠️​The Path is not valid.⚠️\n​");
	return (0);
}
