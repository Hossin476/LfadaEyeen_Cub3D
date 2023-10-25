/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:27:00 by lshail            #+#    #+#             */
/*   Updated: 2023/10/13 15:33:51 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_key_release(mlx_key_data_t keydata, void *arg)
{
	t_player	*player;

	player = arg;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		player->side_direction = 0;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		player->side_direction = 0;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		player->walk_direction = 0;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		player->walk_direction = 0;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		player->turn_direction = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		player->turn_direction = 0;
}

void	ft_handle_moves(mlx_key_data_t keydata, void *arg)
{
	t_player	*player;

	player = arg;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player->walk_direction = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player->walk_direction = -1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player->side_direction = -1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player->side_direction = 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		player->turn_direction = 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		player->turn_direction = -1;
	ft_key_release(keydata, arg);
}

void	clear_window(t_player *player, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i < (height / 2))
				mlx_put_pixel(player->data->img, j, i, player->clfr->cl);
			else
				mlx_put_pixel(player->data->img, j, i, player->clfr->fr);
			j++;
		}
		i++;
	}
}

void	update(void *param)
{
	t_player	*player;

	player = param;
	clear_window(player, player->util->height, player->util->width);
	wall_projection(player);
	if (player->walk_direction != 0 || player->turn_direction != 0)
		draw_player(player);
	if (player->side_direction != 0)
		draw_player2(player);
	ft_draw_map(player);
}
