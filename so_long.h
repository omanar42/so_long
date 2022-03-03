/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:44:05 by omanar            #+#    #+#             */
/*   Updated: 2022/02/16 16:06:11 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		move_count;
	char	*wall_path;
	void	*wall_img;
	char	*right_player_path;
	void	*right_player_img;
	char	*left_player_path;
	void	*left_player_img;
	void	*player_img;
	char	*collectible_path;
	void	*collectible_img;
	char	*e1_path;
	void	*e1_img;
	char	*e4_path;
	void	*e4_img;
	char	*empty_path;
	void	*empty_img;
	int		xml_w;
	int		xml_h;
	char	**mat;
	int		map_x;
	int		map_y;
	int		empty_x;
	int		empty_y;
}				t_game;

int		map_dimensions(char **argv, t_game *map);
int		map_checker(char **argv, t_game *map);
int		check_walls(char **argv, t_game *map);
int		check_walls_nrm(char *str, t_game *map);
int		check_player(char **argv, t_game *map);
int		check_collectible(char **argv, t_game *map);
int		check_exit(char **argv, t_game *map);
int		check_characters(char **argv, t_game *map);
void	ft_draw_map(t_game *game);
void	ft_draw_wall(t_game *game);
void	ft_draw_collectible(t_game *game);
void	ft_draw_exit(t_game *game);
void	ft_draw_player(t_game *game);
void	empty_set(t_game *game);
int		link_images(t_game *game);
void	put_images(t_game *game);
void	map_set(t_game *game, int i, int j);
int		ft_putstr(char *s);
int		key_hook(int keycode, t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	ft_swap_ud(t_game *game, int i, int j, int s);
void	ft_swap_lr(t_game *game, int i, int j, int s);
int		count_collectible(t_game *game);
char	*ft_itoa(int n);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_exit(t_game *game);

#endif