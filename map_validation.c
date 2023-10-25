/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:58:53 by lshail            #+#    #+#             */
/*   Updated: 2023/09/18 14:58:53 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_duplicate_player(char **map)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player_char(map[i][j]))
			{
				flag++;
				if (flag > 1)
					error_handling(1);
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		error_handling(3);
	return (0);
}

static int	is_valid_border(char **map, int i, int j)
{
	return (is_border(map, i, j) && (map[i][j] == '0'
		||is_player_char(map[i][j])));
}

static int	has_space_around_cell(char **map, int i, int j)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	if ((map[i][j] == '0' || is_player_char(map[i][j])) &&
		has_space_around(map, i, j))
	{
		while (map[map_height])
			map_height++;
		map_width = ft_strlen2(map[i]);
		if (i > 0 && map[i - 1][j] == ' ')
			return (1);
		if (i < map_height - 1 && map[i + 1][j] == ' ')
			return (1);
		if (j > 0 && map[i][j - 1] == ' ')
			return (1);
		if (j < map_width - 1 && map[i][j + 1] == ' ')
			return (1);
	}
	return (0);
}

static int	is_map_invalid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid_border(map, i, j))
				return (1);
			else if (has_space_around_cell(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_validation(char **map)
{
	int	error_status;

	error_status = 0;
	if (!map || !*map)
	{
		printf("Error:\nempty map.\n");
		exit(1);
	}
	if (has_duplicate_player(map))
		error_status = 1;
	else if (is_map_invalid(map))
		error_status = 2;
	error_handling(error_status);
}
