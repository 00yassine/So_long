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

void	ft_ex_checker(char *str)
{
	size_t	i;
	char	*exten;

	int (j), (dot);
	exten = ".ber";
	i = ft_strlen(str);
	if (i <= 4)
		ft_error("⚠️​Error⚠️​ : invalid map file, please try another file");
	j = i - 4;
	i = 0;
	while (str[j] && exten[i])
		if (str[j++] != exten[i++])
			ft_error("⚠️​Error⚠️​ : invalid map file extention");
	j = 0;
	dot = 0;
	while (str[j++])
	{
		if (str[j] == '.')
			dot++;
	}
	if (dot > 1)
		ft_error("⚠️​too many \".\" in the file name⚠️​");
}
