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

static int	check_map_name(char *str)
{
	int (i) = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
		return (1);
	return (0);
}

void	ft_ex_checker(char *str)
{
	if (!check_map_name(str))
		ft_error("Error\n:⚠️​invalid map file, please try another file⚠️.\n");
}
