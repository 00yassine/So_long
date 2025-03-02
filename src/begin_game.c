/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:03:37 by ykabili-          #+#    #+#             */
/*   Updated: 2025/03/02 12:03:45 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_alloc_map_game(t_game *game, char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
		i++;
	game->map_ptr = malloc((i + 1) * sizeof(char *));
	if (!game->map_ptr)
		return ;
	i = 0;
	while (map && map[i])
	{
		game->map_ptr[i] = ft_strdup(map[i]);
		i++;
	}
	game->map_ptr[i] = NULL;
}

void	save_position(t_game *game, char **map)
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

void    begin_game(char **map)
{
    t_game  game;
    int i;
    int j;

    j = 0;
    ft_alloc_map_game(&game, map);
    ft_save_p_cor_game(&game, map);
    game.mlx = mlx_init();
    game.nb_m = 0;
    while (map && map[0])
        i++;
    i = ft_strlen(map[0]);
    game.mlx_win = mlx_new_window(game.mlx, i * 64, j * 64, "SO_LONG");
    path_image(&game);
    put_to_window(&game, map, 0, 0);
    ft_free(map);
    mlx_hook(game.mlx_win, 17, 0, func_hook, &game);
    mlx_key_hook(game.mlx_win, keyhook, &game);
    mlx_loop(game.mlx);
}
