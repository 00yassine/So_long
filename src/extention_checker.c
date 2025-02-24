/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:34:44 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 10:01:49 by ykabili-         ###   ########.fr       */
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
			put_error("⚠️​Error⚠️​ : invalid map file extention");
	j = 0;
	dot = 0;
	while (str[j++])
	{
		if (str[j] == '.')
			dot++;
	}
	if (dot > 1)
		put_error("⚠️​too many \".\" in the file name⚠️​");
}
