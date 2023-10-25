/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:22:53 by lshail            #+#    #+#             */
/*   Updated: 2023/10/07 13:09:21 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_facing_down(double ray)
{
	if (ray > 0 && ray < M_PI)
		return (1);
	else
		return (-1);
}

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}

int	is_facing_right(double ray)
{
	if (ray < M_PI / 2 || ray > (3 * M_PI) / 2)
		return (1);
	else
		return (0);
}

int	is_wall(double posx, double posy, char **map)
{
	int	x;
	int	y;

	x = (posx / TILE_SIZE);
	y = (posy / TILE_SIZE);
	if (x > ft_strlen2(map[0]) || x < 0 || y < 0 || y > get_grid_height(map))
		return (1);
	if (x < ft_strlen2(map[0]) && x >= 0
		&& y >= 0 && y < get_grid_height(map) && map[y][x] == '1')
		return (1);
	else
		return (0);
}

int	get_grid_height(char **grid)
{
	int		j;
	char	**tmp;

	tmp = grid;
	j = 0;
	while (*tmp)
	{
		j++;
		tmp++;
	}
	return (j);
}
