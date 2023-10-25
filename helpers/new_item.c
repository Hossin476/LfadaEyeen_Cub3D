/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:00:09 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:31:06 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*new_item(char *line, int length)
{
	t_map	*item;

	item = malloc(sizeof(t_map));
	if (!item)
		return (NULL);
	item->line = line;
	item->length = length;
	item->next = NULL;
	return (item); 
}
