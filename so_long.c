/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:33:24 by omanar            #+#    #+#             */
/*   Updated: 2022/02/17 11:33:41 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_parsing(char **mat, int fd)
{
	*mat = get_next_line(fd);
	return (*mat);
}

void	matris_building(char **argv, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	game->mat = (char **)malloc(sizeof(char *) * (game->height + 1));
	while ((ft_parsing(&game->mat[i], fd)))
		i++;
	game->mat[i] = 0;
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || map_dimensions(argv, &game) == 1)
		return (ft_putstr("Error\nInvalid Arguments"));
	if (map_checker(argv, &game) == 1 || check_walls(argv, &game) == 1
		|| check_characters(argv, &game) == 1
		|| check_player(argv, &game) != 1 || check_exit(argv, &game) < 1
		|| check_collectible(argv, &game) < 1)
		return (ft_putstr("Error\nInvalid Map"));
	matris_building(argv, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 80,
			game.height * 80 + 20, "So_long");
	if (link_images(&game) == 1)
		return (ft_putstr("Error\nInvalid xpm"));
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
