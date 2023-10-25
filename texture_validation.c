/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:00:40 by lshail            #+#    #+#             */
/*   Updated: 2023/10/09 17:16:49 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void	check_texture(char **str)
{
	int		i;
	char	*tmp;

	tmp = *str;
	i = 2;
	if (!tmp || !*tmp)
		return ;
	while (tmp[i] == ' ')
		i++;
	tmp = ft_strdup(tmp + i);
	free(*str);
	*str = tmp;
}

static void	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		printf("Error:\nRGB not valid\n");
		exit(1);
	}
}

int	check_color_range(char **find)
{
	int	i;
	int	count;
	int	color;

	i = 0;
	count = 0;
	while (find[i])
	{
		if (ft_strchr(find[i], ' '))
			return (0);
		color = ft_atoi(find[i]);
		if (color < 0 || color > 255)
		{
			error_handling(4);
			break ;
		}
		i++;
		count++;
	}
	return (count);
}

void	check_colors(char *str, int *color)
{
	int		count;
	char	**find;
	int		i;

	count = 0;
	i = 1;
	check_comma(str);
	while (str[i] == ' ')
		i++;
	find = ft_split(&str[i], ",");
	if (find == NULL)
	{
		error_handling(4);
		return ;
	}
	count = check_color_range(find);
	if (count != 3)
		error_handling(4);
	*color = pixel_color(ft_atoi(find[0]),
			ft_atoi(find[1]), ft_atoi(find[2]), 255);
	clear_map(find);
}

void	validate_texture(t_texture *texture, t_clfr *clfr)
{
	if (!texture->no || !texture->so || !texture->we
		|| !texture->ea || !texture->fr || !texture->cl)
	{
		printf("Error:\nTexture is not valid");
		exit(1);
	}
	check_colors(texture->fr, &clfr->fr);
	check_colors(texture->cl, &clfr->cl);
	check_texture(&(texture->no));
	check_texture(&(texture->so));
	check_texture(&(texture->we));
	check_texture(&(texture->ea));
}
