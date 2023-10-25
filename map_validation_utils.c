/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:00:36 by lshail            #+#    #+#             */
/*   Updated: 2023/10/12 11:55:50 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_border(char **map, int i, int j)
{
	int	map_height;

	map_height = 0;
	while (map[map_height])
		map_height++;
	return (i == 0 || i == map_height - 1
		|| j == 0 || j == ft_strlen2(map[i]) - 1);
}

int	has_space_around(char **map, int i, int j)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	map_width = ft_strlen2(map[i]);
	while (map[map_height])
		map_height++;
	return ((i > 0 && map[i - 1][j] == ' ')
		|| (i < map_height - 1 && map[i + 1][j] == ' ')
		|| (j > 0 && map[i][j - 1] == ' ')
		|| (j < map_width - 1 && map[i][j + 1] == ' '));
}

void	error_handling(int status)
{
	if (status == 1)
	{
		printf("Error:\nduplicate player.\n");
		exit(1);
	}
	else if (status == 2)
	{
		printf("Error:\ninvalid map.\n");
		exit(1);
	}
	else if (status == 3)
	{
		printf("Error:\nno player.\n");
		exit(1);
	}
	else if (status == 4)
	{
		printf("Error:\nTexture not valid\n");
		exit(1);
	}
}

int	ft_fill_texture(int fd, t_texture *texture)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_skip_newline2(line))
		{
			line = get_next_line(fd);
			continue ;
		}
		if (!ft_check_sides(line, texture))
			return (txt_clear(texture), 0);
		if (++i == 6)
			break ;
		line = get_next_line(fd);
	}
	return (1);
}
