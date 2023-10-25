/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshail <lshail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:59:17 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:32:21 by lshail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	charpos(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		s++;
		i++;
	}
	return (i);
}

static char	*line_handler(char **hold)
{
	char	*tmp;
	char	*line;
	int		pos;

	pos = charpos(*hold, '\n');
	line = ft_substr(*hold, 0, pos + 1);
	tmp = *hold;
	*hold = ft_substr(tmp, pos + 1, ft_strlen(tmp));
	free(tmp);
	return (line);
}

static int	read_line(char *buff, int fd)
{
	int		rd;

	rd = read(fd, buff, 42);
	if (rd < 0)
		return (rd);
	buff[rd] = '\0';
	return (rd);
}

static void	fill_holder(char **hold, char *buff)
{
	char	*tmp;

	if (!*hold)
		*hold = ft_strdup("");
	tmp = *hold;
	*hold = ft_strjoin(tmp, buff);
	free(tmp);
	free(buff);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buff;
	int			rd;

	if (fd < 0 || 42 <= 0)
		return (NULL);
	while (1)
	{
		buff = malloc(sizeof(char) * 42 + 1);
		if (!buff)
			return (NULL);
		rd = read_line(buff, fd);
		if (rd < 0 || (rd == 0 && !hold))
			return (free(buff), NULL);
		fill_holder(&hold, buff);
		if (!*hold)
			return (free(hold), hold = 0, NULL);
		if ((rd == 0 && *hold) || (ft_strchr(hold, '\n') != NULL))
			return (line_handler(&hold));
	}
}
