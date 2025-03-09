/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:56:56 by yassine           #+#    #+#             */
/*   Updated: 2025/02/24 10:01:25 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_long(char **map)
{
	int	i;
	int	j;

	i = ft_strlen(map[0]);
	j = 0;
	while(map[j])
		j++;
	if(i > 72 || j > 33)
	{
		ft_free(map);
		ft_error("map too big\n");
	}
}
int	main(int ac, char **av)
{
	char	**map;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error("⚠️​The map cannot be open.⚠️​\n");
		ft_ex_checker(av[1]);
		map = reading_map(fd);
		check_long(map);
		checking_map(map);
		path_checker(map, 0);
		path_checker(map, 1);
		begin_game(map);
		ft_free(map);
	}
	else
		ft_error("⚠️​too many argument or invalid input⚠️\n​");
}
