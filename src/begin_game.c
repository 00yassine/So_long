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

void    set_image(t_game *game)
{
    int x;
    int y;

    game->img1 = mlx_xpm_file_to_image (game->mlx,
			"./textures/stone.xpm", &x, &y);
	check_xpm(game->img1, game);
	game->img2 = mlx_xpm_file_to_image (game->mlx,
			"./textures/sand.xpm", &x, &y);
	check_xpm(game->img2, game);
	game->img3 = mlx_xpm_file_to_image (game->mlx,
			"./textures/steve.xpm", &x, &y);
	check_xpm(game->img3, game);
	game->img4 = mlx_xpm_file_to_image (game->mlx,
			"./textures/diamond.xpm", &x, &y);
	check_xpm(game->img4, game);
	game->img5 = mlx_xpm_file_to_image (game->mlx,
			"./textures/exit.xpm", &x, &y);
	check_xpm(game->img5, game);
}

void    set_img_to_window(t_game *game, char **map, int x, int y)
{
    while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img1,
					x * 50, y * 50);
			if (map[y][x] == '0')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img2,
					x * 50, y * 50);
			if (map[y][x] == 'P')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img3,
					x * 50, y * 50);
			if (map[y][x] == 'C')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img4,
					x * 50, y * 50);
			if (map[y][x] == 'E')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img5,
					x * 50, y * 50);
			x++;
		}
		y++;
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
    while (map && map[j])
        j++;
    i = ft_strlen(map[0]);
    game.mlx_win = mlx_new_window(game.mlx, i * 50, j * 50, "SO_LONG");
    set_image(&game);
	printf("here\n\n\n\n");
    set_img_to_window(&game, map, 0, 0);
    ft_free(map);
    mlx_hook(game.mlx_win, 17, 0, func_hook, &game);
    mlx_key_hook(game.mlx_win, keyhook, &game);
    mlx_loop(game.mlx);
}
