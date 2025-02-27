/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabili- <ykabili-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:02:20 by ykabili-          #+#    #+#             */
/*   Updated: 2025/02/24 13:06:20 by ykabili-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_newline_checker(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		free(str);
		ft_error("⚠️too many newline⚠️\n");
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
			{
				free(str);
				ft_error("⚠️too many newline⚠️\n");
			}
		}
		i++;
	}
}

static char	*ft_getmap(int fd)
{
	char	*buffer;
	char	*line;
	char	*ptr;
	int		i;

	line = NULL;
	buffer = malloc(4 * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read (fd, buffer, (int)5);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		ptr = line;
		line = ft_strjoin(line, buffer);
		free (ptr);
	}
	free(buffer);
	return (line);
}

char	**reading_map(int fd)
{
	char	**map;
	char	*file_content;

	file_content = ft_getmap(fd);
	if (ft_strlen(file_content) == 0)
	{
		free(file_content);
		ft_error("⚠️empty map file.⚠️\n");
	}
	ft_newline_checker(file_content);
	map = ft_split(file_content, '\n');
	if (!map)
		return (NULL);
	free (file_content);
	return (map);
}
