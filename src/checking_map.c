/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:59:05 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 13:07:51 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_chars(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			if (!ft_strchr("01ECP", map[i][j]))
			{
				ft_free(map);
				ft_error("⚠️Error: invalid character in map⚠️ \n");
			}
			j++;
		}
		i++;
	}
	return (count);
}

static static void	check_hori_walls(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_free(map);
			ft_error("⚠️invalid wall⚠️\n");
		}
		i++;
	}
}

static void	check_verti_walls(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(map[i]) - 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_free(map);
			ft_error("⚠️invalid wall⚠️\n");
		}
		i++;
	}
	i--;
	while (j >= 0)
	{
		if (map[i][j] != '1')
		{
			ft_free(map);
			ft_error("⚠️invalid wall⚠️\n");
		}
		j--;
	}
}

void	checking_map(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_free(map);
			ft_error("⚠️too many newline⚠️\n");
		}
		i++;
	}
	check_hori_walls(map);
	check_verti_walls(map);
	if (check_map_chars(map, 'C') < 1 || check_map_chars(map, 'P') != 1)
	{
		ft_free(map);
		put_error("⚠️characters Error : fix ur map.⚠️\n");
	}
	if (check_map_chars(map, 'E') != 1)
	{
		ft_free(map);
		put_error("⚠️characters Error : fix ur map.⚠️\n");
	}
}
