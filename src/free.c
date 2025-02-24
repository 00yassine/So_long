/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:57 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 16:31:12 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_ptr[i])
	{
		free (data->map_ptr[i])
		i++;
	}
	free (data->map_ptr);
	free (data);
}
