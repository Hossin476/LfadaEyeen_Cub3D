/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:56:35 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/12 12:16:45 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *scene)
{
	char	*extension;

	extension = ft_strrchr(scene, '.');
	if (ft_strcmp(extension, ".cub") == 0)
		return (1);
	return (0);
}

t_utils	*ft_validate_scene(char *scene, t_clfr *clfr)
{
	t_texture	*texture;
	t_map		*headmap; 
	char		**map;
	t_utils		*util;

	map = NULL;
	headmap = NULL;
	texture = NULL;
	if (!check_extension(scene))
		return (NULL);
	util = malloc(sizeof(t_utils));
	if (!util)
		return (NULL);
	texture = fetching_file(scene, &headmap);
	if (!texture)
		return (free(util), NULL);
	map = lst_to_arr(headmap);
	if (!map)
		return (free(util), txt_clear(texture), NULL);
	lst_clear(headmap);
	validate_texture(texture, clfr);
	map_validation(map);
	util->map = map;
	util->texture = texture;
	return (util);
}
