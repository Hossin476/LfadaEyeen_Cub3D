/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:08:07 by lshail            #+#    #+#             */
/*   Updated: 2023/10/14 14:31:09 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*load_textures(char *side)
{
	mlx_texture_t	*image;

	image = mlx_load_png(side);
	if (!image)
		exit (1);
	return (image);
}

u_int32_t	**img_to_double_pointer(mlx_texture_t *img)
{
	uint32_t	**pixels;
	t_colors	colors;

	colors.i = 0;
	colors.count = 0;
	pixels = malloc(sizeof(uint32_t *) * img->height);
	if (!pixels)
		return (NULL);
	while (colors.i < img->height)
	{
		colors.j = 0;
		pixels[colors.i] = malloc(sizeof(uint32_t) * img->width);
		if (!pixels[colors.i])
			return (NULL);
		while (colors.j < img->width)
		{
			set_color(&colors, img, pixels);
			colors.j++;
			colors.count += 4;
		}
		colors.i++;
	}
	return (pixels);
}

void	ft_putx_texture(t_player *player,
			t_cord *point, t_ray *ray, t_wall *wall)
{
	while (wall->y1 < wall->y2)
	{
		if (!ft_check_no_so(player, point, ray, wall))
		{
			if (ray->isvertwallhit && is_facing_right(wall->ray_start))
			{
				point->pointy = ((wall->y1 - ((wall->height / 2.0)
								- (wall->wall_strip_ht / 2.0)))
						* player->ea->height) / wall->wall_strip_ht;
				mlx_put_pixel(player->data->img, wall->i, wall->y1,
					player->data->ea[(int)point->pointy][(int)point->pointx]);
			}
			else if (ray->isvertwallhit && !is_facing_right(wall->ray_start))
			{
				point->pointy = ((wall->y1 - ((wall->height / 2.0)
								- (wall->wall_strip_ht / 2.0)))
						* player->we->height) / wall->wall_strip_ht;
				mlx_put_pixel(player->data->img, wall->i, wall->y1,
					player->data->we[(int)point->pointy]
				[(int)((player->so->width - 1) - point->pointx)]);
			}
		}
		wall->y1++;
	}
}

int	ft_check_no_so(t_player *player, t_cord *point, t_ray *ray, t_wall *wall)
{
	if (ray->ishorzwallhit && is_facing_down(wall->ray_start) < 0)
	{
		point->pointy = ((wall->y1 - ((wall->height / 2.0)
						- (wall->wall_strip_ht / 2.0)))
				* player->no->height) / wall->wall_strip_ht;
		mlx_put_pixel(player->data->img, wall->i, wall->y1,
			player->data->no[(int)point->pointy][(int)point->pointx]);
		return (1);
	}
	else if (ray->ishorzwallhit && is_facing_down(wall->ray_start) > 0)
	{
		point->pointy = ((wall->y1 - ((wall->height / 2.0)
						- (wall->wall_strip_ht / 2.0)))
				* player->so->height) / wall->wall_strip_ht;
		mlx_put_pixel(player->data->img, wall->i, wall->y1,
			player->data->so[(int)(point->pointy)]
		[(int)((player->so->width - 1) - point->pointx)]);
		return (1);
	}
	return (0);
}
