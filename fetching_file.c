/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:19:39 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/12 12:15:42 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	ft_memset(texture, 0, sizeof(t_texture));
	return (texture);
}

int	ft_check_sides(char *line, t_texture *texture)
{
	char	*trimed;

	trimed = ft_strtrim(line, " \n");
	free(line);
	if (!texture->no && !ft_strncmp(trimed, "NO ", 3))
		return (texture->no = trimed, 1);
	else if (!texture->so && !ft_strncmp(trimed, "SO ", 3))
		return (texture->so = trimed, 1);
	else if (!texture->we && !ft_strncmp(trimed, "WE ", 3))
		return (texture->we = trimed, 1);
	else if (!texture->ea && !ft_strncmp(trimed, "EA ", 3))
		return (texture->ea = trimed, 1);
	else if (!texture->fr && !ft_strncmp(trimed, "F ", 2))
		return (texture->fr = trimed, 1);
	else if (!texture->cl && !ft_strncmp(trimed, "C ", 2))
		return (texture->cl = trimed, 1);
	free(trimed);
	return (0);
}

int	ft_skip_newline2(char *line)
{
	if (!ft_strcmp(line, "\n"))
	{
		free(line);
		return (1);
	}
	return (0);
}

int	get_map(t_map **headmap, int fd)
{
	char	*line;
	char	*trimed;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_skip_newline2(line))
			break ;
		line = get_next_line(fd);
	}
	while (line)
	{
		trimed = ft_strtrim(line, "\n");
		free(line);
		if (is_valid_line(trimed))
			addback(headmap, new_item(trimed, ft_length(trimed)));
		else
			return (free(trimed), lst_clear(*headmap), 0);
		line = get_next_line(fd);
	}
	return (1);
}

t_texture	*fetching_file(char *scene, t_map **headmap)
{
	int			fd;
	t_texture	*texture;

	fd = open(scene, O_RDONLY, 664);
	if (fd < 0)
		return (NULL);
	texture = init_texture();
	if (!ft_fill_texture(fd, texture))
		return (NULL);
	if (!get_map(headmap, fd))
		return (txt_clear(texture), NULL);
	return (texture);
}
