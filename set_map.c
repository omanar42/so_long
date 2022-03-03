/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:34:10 by omanar            #+#    #+#             */
/*   Updated: 2022/02/15 18:09:20 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_dimensions(char **argv, t_game *map)
{
	int		fd;
	char	*str;
	char	*s;

	s = ft_strrchr(argv[1], '.');
	fd = open(argv[1], O_RDONLY);
	if (!s)
		return (1);
	if (ft_strncmp(".ber", s, 10) || fd < 0)
		return (1);
	map->height = 0;
	str = get_next_line(fd);
	map->width = ft_strlen(str) - 1;
	free(str);
	str = get_next_line(fd);
	while (str)
	{
		map->height += 1;
		free(str);
		str = get_next_line(fd);
	}
	map->height += 1;
	free(str);
	close(fd);
	return (0);
}

int	map_checker(char **argv, t_game *map)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (map->height <= 1 || fd < 0 || map->height == map->width)
		return (1);
	while (i <= map->height)
	{
		str = get_next_line(fd);
		if (i == map->height)
		{
			if (str[map->width - 1] != '1' || ft_strlen(str) != (map->width))
				return (1);
		}
		else
			if (ft_strlen(str) != (map->width + 1))
				return (1);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}

int	check_walls_nrm(char *str, t_game *map)
{
	if (str[0] != '1')
		return (1);
	if (str[map->width - 1] != '1')
		return (1);
	return (0);
}
