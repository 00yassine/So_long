/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:34:44 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 13:05:18 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_map_slash(char *str)
{
	int		i;
	char	*path;

	path = "maps/";
	i = 0;
	while (str[i] != path[i])
	{
		if (str[i] != path[i])
			ft_error("Error\n:⚠️maps/ is not found⚠️.\n");
		i++;
	}
}

void	ft_ex_checker(char *str)
{
	size_t	i;
	char	*exten;

	int (j), (dot);
	check_map_slash(str);
	exten = ".ber";
	i = ft_strlen(str);
	if (i - 5 <= 4)
		ft_error("Error\n:⚠️​invalid map file, please try another file⚠️.\n");
	j = i - 4;
	i = 0;
	while (str[j] && exten[i])
		if (str[j++] != exten[i++])
			ft_error("Error\n:⚠️ invalid map file extention⚠️.\n");
	j = 0;
	dot = 0;
	while (str[j++])
	{
		if (str[j] == '.')
			dot++;
	}
	if (dot > 1)
		ft_error("Error\n:⚠️​too many \".\" in the file name⚠️.\n​");
}
