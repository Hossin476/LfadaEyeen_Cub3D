/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:21:03 by lshail            #+#    #+#             */
/*   Updated: 2023/10/13 15:16:42 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_utils *util, t_data *data, t_clfr *clfr)
{
	player->fov = 60 * (M_PI / 180);
	player->speed = 3;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->turn_speed = 1.2 * (M_PI / 180);
	player->x = get_player_pos(util, 1) * TILE_SIZE + (TILE_SIZE / 2);
	player->y = get_player_pos(util, 0) * TILE_SIZE + (TILE_SIZE / 2);
	player->last_x = -1;
	player->data = data;
	player->util = util;
	player->clfr = clfr;
	util->map_width = ft_strlen2(player->util->map[0]) * TILE_SIZE;
	util->map_height = get_grid_height(player->util->map) * TILE_SIZE;
	set_player_angle(player,
		util->map[get_player_pos(util, 0)][get_player_pos(util, 1)]);
}

int	get_player_pos(t_utils *util, int mode)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = util->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player_char(map[i][j]))
			{
				if (!mode)
					return (i);
				else
					return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	set_player_angle(t_player *player, char c)
{
	if (c == 'N')
		player->angle = 3 * M_PI / 2;
	else if (c == 'S')
		player->angle = M_PI / 2;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = M_PI;
}

void	handle_mouse(double xpos, double ypos, void *param)
{
	t_player	*player;
	double		x_new;
	double		x_angle;

	player = param;
	if (xpos < 0 || xpos > WIDTH || ypos < 0 || ypos > HEIGHT)
		player->last_x = xpos;
	x_new = xpos - player->last_x;
	x_angle = (M_PI * 2) * (x_new / WIDTH);
	player->angle += x_angle;
	player->last_x = xpos;
	mlx_set_cursor_mode(player->data->mlx, MLX_MOUSE_HIDDEN);
}

void	draw_player(t_player *player)
{
	double	nposx;
	double	nposy;
	double	move_step;

	move_step = player->walk_direction * player->speed;
	player->angle += player->turn_direction * player->turn_speed;
	nposx = player->x + cos(player->angle) * move_step;
	nposy = player->y + sin(player->angle) * move_step;
	if (!is_wall(nposx + 5, nposy, player->util->map)
		&& !is_wall(nposx - 5, nposy, player->util->map)
		&& !is_wall(nposx, nposy + 5, player->util->map)
		&& !is_wall(nposx, nposy - 5, player->util->map))
	{
		player->x = nposx;
		player->y = nposy;
	}
}
