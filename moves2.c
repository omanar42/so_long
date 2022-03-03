/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:31:42 by omanar            #+#    #+#             */
/*   Updated: 2022/02/17 15:29:00 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->mat[i])
	{
		j = 0;
		while (game->mat[i][j])
		{
			if (game->mat[i][j + 1] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_swap_ud(t_game *game, int i, int j, int s)
{
	game->mat[i][j] = '0';
	game->mat[s][j] = 'P';
	game->move_count++;
}

void	ft_swap_lr(t_game *game, int i, int j, int s)
{
	game->mat[i][j] = '0';
	game->mat[i][s] = 'P';
	game->move_count++;
}

void	ft_exit(t_game *game)
{
	game->move_count++;
	ft_putstr("Congratulations, YOU WON!!\n");
	exit(0);
}
