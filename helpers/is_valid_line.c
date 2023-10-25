/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:07:51 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:30:16 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_line(char *arg)
{
	int	i;

	i = 0;
	if (!*arg)
		return (0);
	while (arg[i])
	{
		if (!ft_strchr("10 \nNSWE", arg[i]))
			return (0);
		i++;
	}
	return (1);
}
