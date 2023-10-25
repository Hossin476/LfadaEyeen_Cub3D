/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:27:05 by lshail            #+#    #+#             */
/*   Updated: 2023/10/13 14:54:48 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_horizantal(double angle, t_player *player,
		t_ray *ray, t_instersict point)
{
	double	p_y2;

	while (point.p_x >= 0 && point.p_x <= player->util->map_width
		&& point.p_y >= 0 && point.p_y <= player->util->map_height)
	{
		if (is_facing_down(angle) < 0)
			p_y2 = point.p_y - 1;
		else
			p_y2 = point.p_y;
		if (is_wall(point.p_x, p_y2, player->util->map))
		{
			ray->hx = point.p_x;
			ray->hy = point.p_y;
			ray->ishorzwallhit = 1;
			break ;
		}
		else
		{
			point.p_y += point.step_y;
			point.p_x += point.step_x;
		}
	}
}

void	horizantal_ray(double angle, t_player *player, t_ray *ray)
{
	t_instersict	point;

	point.step_y = TILE_SIZE * is_facing_down(angle);
	point.step_x = (TILE_SIZE / tan(angle));
	point.p_y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (is_facing_down(angle) > 0)
		point.p_y += TILE_SIZE;
	point.p_x = player->x + ((point.p_y - player->y) / tan(angle));
	if ((!is_facing_right(angle) && point.step_x > 0)
		|| (is_facing_right(angle) && point.step_x < 0))
		point.step_x *= -1.0;
	cast_horizantal(angle, player, ray, point);
	ray->horizantal_distance = sqrtf(pow(ray->hx - player->x, 2)
			+ pow(ray->hy - player->y, 2));
}

void	cast_vertical(double angle, t_player *player,
			t_ray *ray, t_instersict point)
{
	double	p_x2;

	while (point.p_x >= 0 && point.p_x <= player->util->map_width
		&& point.p_y >= 0 && point.p_y <= player->util->map_height)
	{
		if (!is_facing_right(angle))
			p_x2 = point.p_x - 1;
		else
			p_x2 = point.p_x;
		if (is_wall(p_x2, point.p_y, player->util->map))
		{
			ray->vx = point.p_x;
			ray->vy = point.p_y;
			ray->isvertwallhit = 1;
			break ;
		}
		else
		{
			point.p_y += point.step_y;
			point.p_x += point.step_x;
		}
	}
}

void	vertical_ray(double angle, t_player *player, t_ray *ray)
{
	t_instersict	point;

	point.p_x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	point.step_x = TILE_SIZE;
	if (is_facing_right(angle))
		point.p_x += TILE_SIZE;
	point.p_y = player->y + ((point.p_x - player->x) * tan(angle));
	if (!is_facing_right(angle))
		point.step_x *= -1;
	point.step_y = TILE_SIZE * tan(angle);
	if ((is_facing_down(angle) < 0 && point.step_y > 0)
		|| (is_facing_down(angle) > 0 && point.step_y < 0))
		point.step_y *= -1;
	cast_vertical(angle, player, ray, point);
	ray->vertical_distance = sqrtf(pow(ray->vx - player->x, 2)
			+ pow(ray->vy - player->y, 2));
}

void	wall_projection(t_player *player)
{
	t_cord	point;
	t_ray	ray;
	t_wall	wall;

	init_vals(&wall, player);
	while (wall.i < player->util->width)
	{
		ray.ishorzwallhit = 0;
		ray.isvertwallhit = 0;
		normalize_angle(&wall.ray_start);
		horizantal_ray(wall.ray_start, player, &ray);
		vertical_ray(wall.ray_start, player, &ray);
		check_ray(&ray, &wall, player);
		check_wall(&wall, &wall.y1);
		if (ray.isvertwallhit)
			point.pointx = check_xtext(&ray, wall.ray_start,
					point.pointx, player);
		if (ray.ishorzwallhit)
			point.pointx = check_xtext1(&ray, wall.ray_start,
					point.pointx, player);
		ft_putx_texture(player, &point, &ray, &wall);
		wall.ray_start += wall.ray_increment;
		wall.i++;
	}
}
