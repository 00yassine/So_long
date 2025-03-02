/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:54:08 by ykabili-          #+#    #+#             */
/*   Updated: 2025/03/01 18:54:11 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_xpm(void *s, t_game *game)
{
	if (!s)
	{
		if (game->img1)
			mlx_destroy_image(game->mlx, game->img1);
		if (game->img2)
			mlx_destroy_image(game->mlx, game->img2);
		if (game->img3)
			mlx_destroy_image(game->mlx, game->img3);
		if (game->img4)
			mlx_destroy_image(game->mlx, game->img4);
		if (game->img5)
		{
			mlx_destroy_image(game->mlx, game->img5);
		}
		ft_error("cannot open file xpm try again !!\n");
	}
}

void	free_data_map(t_data *data, char **map)
{
		free_data(data);
	    ft_free(map);
		ft_error("Error: Map large than your screen\n");
}

int func_hook(t_game *game)
{
    destroy_game(game);
    exit (1);
    return (0);
}

void	destroy_game(t_game *game)
{
	if (game->img1)
		mlx_destroy_image(game->mlx, game->img1);
	if (game->img2)
		mlx_destroy_image(game->mlx, game->img2);
	if (game->img3)
		mlx_destroy_image(game->mlx, game->img3);
	if (game->img4)
		mlx_destroy_image(game->mlx, game->img4);
	if (game->img5)
	{
		mlx_destroy_image(game->mlx, game->img5);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_free(game->map_ptr);
	exit(0);
}

void	ft_save_p_cor_game(t_game *game, char **map)
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
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
