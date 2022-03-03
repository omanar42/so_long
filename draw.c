/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:50:13 by omanar            #+#    #+#             */
/*   Updated: 2022/02/16 16:11:36 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game *game)
{
	char	*move;

	move = ft_itoa(game->move_count);
	empty_set(game);
	put_images(game);
	mlx_string_put(game->mlx, game->win, game->width * 40 - 40, 0,
		0xffffffff, "Moves : ");
	mlx_string_put(game->mlx, game->win, game->width * 40 + 40, 0,
		0xffffffff, move);
	free(move);
}

void	empty_set(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			game->empty_x = j * 80;
			game->empty_y = i * 80;
			mlx_put_image_to_window(game->mlx, game->win,
				game->empty_img, game->empty_x, game->empty_y);
			j++;
		}
		i++;
	}
}

void	put_images(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			game->map_x = j * 80;
			game->map_y = i * 80;
			map_set(game, i, j);
			j++;
		}
		i++;
	}
}

void	map_set(t_game *game, int i, int j)
{
	if (game->mat[i][j] == '\n')
		i++;
	if (game->mat[i][j] == '1')
		ft_draw_wall(game);
	if (game->mat[i][j] == 'C')
		ft_draw_collectible(game);
	if (game->mat[i][j] == 'E')
		ft_draw_exit(game);
	if (game->mat[i][j] == 'P')
		ft_draw_player(game);
}

int	link_images(t_game *game)
{
	game->move_count = 0;
	game->wall_path = "./xpms/wall.xpm";
	game->right_player_path = "./xpms/right_player.xpm";
	game->left_player_path = "./xpms/left_player.xpm";
	game->collectible_path = "./xpms/collectible.xpm";
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "./xpms/empty.xpm",
			&game->xml_w, &game->xml_h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, game->wall_path,
			&game->xml_w, &game->xml_h);
	game->right_player_img = mlx_xpm_file_to_image(game->mlx,
			game->right_player_path, &game->xml_w, &game->xml_h);
	game->left_player_img = mlx_xpm_file_to_image(game->mlx,
			game->left_player_path, &game->xml_w, &game->xml_h);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			game->collectible_path, &game->xml_w, &game->xml_h);
	game->e1_img = mlx_xpm_file_to_image(game->mlx, "./xpms/e1.xpm",
			&game->xml_w, &game->xml_h);
	game->e4_img = mlx_xpm_file_to_image(game->mlx, "./xpms/e4.xpm",
			&game->xml_w, &game->xml_h);
	if (!game->empty_img || !game->wall_img || !game->right_player_img
		|| !game->left_player_img || !game->collectible_img
		|| !game->e1_img || !game->e4_img)
		return (1);
	game->player_img = game->right_player_img;
	return (0);
}
