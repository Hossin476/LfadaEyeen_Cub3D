/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:00:47 by lshail            #+#    #+#             */
/*   Updated: 2023/10/09 13:29:05 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen2(const char *str)
{
	int	length;

	length = 0;
	if (!str || !*str)
		return (0);
	while (str[length])
		length++;
	return (length);
}
