/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:59:33 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:30:56 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	addback(t_map **headmap, t_map *item)
{
	t_map	*tmp;

	if (!*headmap)
	{
		*headmap = item;
		return ;
	}
	tmp = *headmap;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = item;
}
