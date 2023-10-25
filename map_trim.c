/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:56:36 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 11:00:42 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_length(char *tirmed)
{
	int	length;

	length = ft_strlen(tirmed);
	while (ft_strchr(" ", tirmed[length]))
	{
		length--;
	}
	return (length + 1);
}

int	get_width(t_map *headmap)
{
	int	max;

	max = headmap->length;
	while (headmap)
	{
		if (max < headmap->length)
			max = headmap->length;
		headmap = headmap->next;
	}
	return (max);
}

int	get_height(t_map *headmap)
{
	int	height;

	height = 0;
	while (headmap)
	{
		headmap = headmap->next;
		height++;
	}
	return (height);
}

void	fill_line(char *map, char *line, int width)
{
	int	i;

	i = 0;
	while (line[i] && i < width)
	{
		map[i] = line[i];
		i++;
	}
	while (i < width)
	{
		map[i] = ' ';
		i++;
	}
	map[i] = '\0';
}

char	**lst_to_arr(t_map *headmap)
{
	int		width;
	int		height;
	char	**map;
	int		i;

	i = 0;
	if (!headmap || !*headmap->line)
		return (NULL);
	height = get_height(headmap);
	width = get_width(headmap);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			return (NULL);
		fill_line(map[i], headmap->line, width);
		i++;
		headmap = headmap->next;
	}
	map[i] = NULL;
	return (map);
}
