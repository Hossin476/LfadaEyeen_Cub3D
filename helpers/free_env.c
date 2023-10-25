/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:52 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/12 12:15:08 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_map(char **map)
{
	char	**tmp;

	tmp = map;
	while (map && *map)
	{
		free(*map);
		map++;
	}
	free(tmp);
}

void	lst_clear(t_map *headmap)
{
	t_map	*tmp;

	tmp = headmap;
	if (!headmap)
		return ;
	headmap = headmap->next;
	while (headmap)
	{
		free(tmp->line);
		free(tmp);
		tmp = headmap;
		headmap = headmap->next;
	}
	free(tmp->line);
	free(tmp);
}

void	txt_clear(t_texture *texture)
{
	free(texture->no);
	free(texture->so);
	free(texture->we);
	free(texture->ea);
	free(texture->fr);
	free(texture->cl);
	free(texture);
}

void	ft_free_texture(uint32_t **texture, mlx_texture_t *img)
{
	uint32_t	i;

	i = 0;
	while (i < img->height)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
	free(img->pixels);
	free(img);
}

void	ft_free_all(t_player *player)
{
	clear_map(player->util->map);
	txt_clear(player->util->texture);
	ft_free_texture(player->data->so, player->so);
	ft_free_texture(player->data->no, player->no);
	ft_free_texture(player->data->we, player->we);
	ft_free_texture(player->data->ea, player->ea);
	free(player->util);
}
