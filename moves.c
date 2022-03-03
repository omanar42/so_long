/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:43:06 by omanar            #+#    #+#             */
/*   Updated: 2022/02/15 17:47:14 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53 || keycode < 0)
		exit(0);
	mlx_clear_window(game->mlx, game->win);
	if (keycode == 2 || keycode == 124)
		move_right(game);
	if (keycode == 0 || keycode == 123)
		move_left(game);
	if (keycode == 13 || keycode == 126)
		move_up(game);
	if (keycode == 1 || keycode == 125)
		move_down(game);
	ft_draw_map(game);
	return (0);
}

void	move_right(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_img = game->right_player_img;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i][j + 1] == '0')
					ft_swap_lr(game, i, j, j + 1);
				else if (game->mat[i][j + 1] == 'C')
					ft_swap_lr(game, i, j, j + 1);
				else if (game->mat[i][j + 1] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player_img = game->left_player_img;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i][j - 1] == '0')
					ft_swap_lr(game, i, j, j - 1);
				else if (game->mat[i][j - 1] == 'C')
					ft_swap_lr(game, i, j, j - 1);
				else if (game->mat[i][j - 1] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i - 1][j] == '0')
					ft_swap_ud(game, i, j, i - 1);
				else if (game->mat[i - 1][j] == 'C')
					ft_swap_ud(game, i, j, i - 1);
				else if (game->mat[i - 1][j] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
			}
			j++;
		}
		i++;
	}
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j] == 'P')
			{
				if (game->mat[i + 1][j] == '0')
					ft_swap_ud(game, i, j, i + 1);
				else if (game->mat[i + 1][j] == 'C')
					ft_swap_ud(game, i, j, i + 1);
				else if (game->mat[i + 1][j] == 'E')
					if (count_collectible(game) == 0)
						ft_exit(game);
				i++;
			}
			j++;
		}
		i++;
	}
}
