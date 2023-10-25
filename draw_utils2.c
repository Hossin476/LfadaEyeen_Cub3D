/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:35 by lshail            #+#    #+#             */
/*   Updated: 2023/10/16 11:00:19 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_pixel(t_player *player, t_minimap map, int i, int j)
{
	if (map.pointx < 0 || map.pointy < 0
		|| map.pointx > player->util->map_width
		|| map.pointy > player->util->map_height)
		mlx_put_pixel(player->data->img, j, i, pixel_color(190, 5, 5, 255));
	else if (is_wall(map.pointx, map.pointy, player->data->utils->map))
		mlx_put_pixel(player->data->img, j, i, pixel_color(0, 0, 0, 128));
	else
		mlx_put_pixel(player->data->img, j, i, pixel_color(128, 128, 128, 255));
}

void	ft_draw_map(t_player *player)
{
	t_minimap	map;
	t_circle	circle;

	map.i = 0;
	map.j = 0;
	map.width = 350;
	map.height = 200;
	map.pointx = (player->x - (map.width / 2.0));
	map.pointy = (player->y - (map.height / 2.0));
	while (map.i < map.height)
	{
		map.pointx = player->x - (map.width / 2.0);
		map.j = 0;
		while (map.j < map.width)
		{
			draw_minimap_pixel(player, map, map.i, map.j);
			map.pointx++;
			map.j++;
		}
		map.i++;
		map.pointy++;
	}
	circle.x_center = (map.width / 2.0);
	circle.y_center = (map.height / 2.0);
	draw_circle(player, &circle, 8, pixel_color(255, 0, 0, 255));
}

void	set_color(t_colors *colors, mlx_texture_t *img, uint32_t	**pixels)
{
	colors->r = img->pixels[colors->count];
	colors->g = img->pixels[colors->count + 1];
	colors->b = img->pixels[colors->count + 2];
	colors->a = img->pixels[colors->count + 3];
	pixels[colors->i][colors->j] = pixel_color(colors->r,
			colors->g, colors->b, colors->a);
}
