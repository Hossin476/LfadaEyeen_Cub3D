/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:45:33 by lshail            #+#    #+#             */
/*   Updated: 2023/10/14 13:04:55 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_xtext(t_ray *ray, double ray_start,
			double x_text, t_player *player)
{
	if (ray->ishorzwallhit && is_facing_down(ray_start) < 0)
		x_text = ((fmod(ray->vy, TILE_SIZE) * player->no->width) / TILE_SIZE);
	else if (ray->ishorzwallhit && is_facing_down(ray_start) > 0)
		x_text = ((fmod(ray->vy, TILE_SIZE) * player->so->width) / TILE_SIZE);
	else if (ray->isvertwallhit && is_facing_right(ray_start))
		x_text = ((fmod(ray->vy, TILE_SIZE) * player->ea->width) / TILE_SIZE);
	else if (ray->isvertwallhit && !is_facing_right(ray_start))
		x_text = ((fmod(ray->vy, TILE_SIZE) * player->we->width) / TILE_SIZE);
	return (x_text);
}

double	check_xtext1(t_ray *ray, double ray_start,
			double x_text, t_player *player)
{
	if (ray->ishorzwallhit && is_facing_down(ray_start) < 0)
		x_text = ((fmod(ray->hx, TILE_SIZE) * player->no->width) / TILE_SIZE);
	else if (ray->ishorzwallhit && is_facing_down(ray_start) > 0)
		x_text = ((fmod(ray->hx, TILE_SIZE) * player->so->width) / TILE_SIZE);
	else if (ray->isvertwallhit && is_facing_right(ray_start))
		x_text = ((fmod(ray->hx, TILE_SIZE) * player->ea->width) / TILE_SIZE);
	else if (ray->isvertwallhit && !is_facing_right(ray_start))
		x_text = ((fmod(ray->hx, TILE_SIZE) * player->we->width) / TILE_SIZE);
	return (x_text);
}

void	init_vals(t_wall *wall, t_player *player)
{
	wall->wall_ht = TILE_SIZE;
	wall->height = player->util->height;
	wall->width = player->util->width;
	wall->proj_dist = (wall->width / 2.0) / tan(player->fov / 2.0);
	wall->ray_increment = (player->fov / wall->width);
	wall->ray_start = (player->angle - (player->fov / 2.0));
	wall->y1 = ((wall->height / 2.0) - (wall->wall_strip_ht / 2.0));
	wall->y2 = ((wall->height / 2.0) + (wall->wall_strip_ht / 2.0));
	wall->i = 0;
}

void	check_ray(t_ray *ray, t_wall *wall, t_player *player)
{
	if (!ray->ishorzwallhit)
		ray->horizantal_distance = INFINITY;
	if (!ray->isvertwallhit)
		ray->vertical_distance = INFINITY;
	if (ray->horizantal_distance < ray->vertical_distance)
	{
		ray->sm = ray->horizantal_distance;
		ray->isvertwallhit = 0;
		wall->wall_dist = (ray->horizantal_distance
				* cos(wall->ray_start - player->angle));
	}
	else
	{
		ray->sm = ray->vertical_distance;
		ray->ishorzwallhit = 0;
		wall->wall_dist = (ray->vertical_distance
				* cos(wall->ray_start - player->angle));
	}
}

void	check_wall(t_wall *wall, double *step)
{
	wall->wall_strip_ht = ((wall->wall_ht / wall->wall_dist) * wall->proj_dist);
	wall->y1 = (wall->height / 2.0) - (wall->wall_strip_ht / 2.0);
	wall->y2 = (wall->height / 2.0) + (wall->wall_strip_ht / 2.0);
	if (wall->y1 < 0)
		wall->y1 = 0;
	if (wall->y2 > wall->height)
		wall->y2 = wall->height;
	*step = wall->y1;
}
