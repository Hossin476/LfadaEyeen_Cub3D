/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:57:51 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:28:30 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*f;

	f = (unsigned char *)str;
	while (n-- > 0)
		*f++ = (unsigned char)c;
	return (str);
}
