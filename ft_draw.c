/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:55:42 by omanar            #+#    #+#             */
/*   Updated: 2022/02/16 16:07:41 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall_img, game->map_x, game->map_y + 20);
}

void	ft_draw_collectible(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->collectible_img, game->map_x, game->map_y + 20);
}

void	ft_draw_exit(t_game *game)
{
	if (count_collectible(game) == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->e4_img, game->map_x, game->map_y + 20);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->e1_img, game->map_x, game->map_y + 20);
}

void	ft_draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, game->map_x, game->map_y + 20);
}
