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
		checking_map(map);
		path_checker(map, 0);
		path_checker(map, 1);
		begin_game(map);
		ft_free(map);
	}
	else
		ft_error("⚠️​too many argument or invalid input⚠️\n​");
}
