/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:21:50 by lshail            #+#    #+#             */
/*   Updated: 2023/10/14 14:35:03 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	draw_player2(t_player *player)
{
	double	nposx;
	double	nposy;
	double	move_step;

	move_step = player->side_direction * player->speed;
	player->angle += player->turn_direction * player->turn_speed;
	nposx = player->x + cos(player->angle + (M_PI_2)) * move_step;
	nposy = player->y + sin(player->angle + (M_PI_2)) * move_step;
	if (!is_wall(nposx + 5, nposy, player->util->map)
		&& !is_wall(nposx - 5, nposy, player->util->map)
		&& !is_wall(nposx, nposy + 5, player->util->map)
		&& !is_wall(nposx, nposy - 5, player->util->map))
	{
		player->x = nposx;
		player->y = nposy;
	}
}

void	draw_circle(t_player *player, t_circle *circle, int radius, int color)
{
	int	x;
	int	y;

	x = -radius;
	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
				mlx_put_pixel(player->data->img,
					circle->x_center + x, circle->y_center + y, color);
			y++;
		}
		x++;
	}
}
