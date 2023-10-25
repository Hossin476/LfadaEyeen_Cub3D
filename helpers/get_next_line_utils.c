/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:25:29 by ykhourba          #+#    #+#             */
/*   Updated: 2023/10/09 13:23:32 by ykhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*d1;

	len = ft_strlen(s1);
	d1 = (char *)malloc(len + 1);
	if (!d1)
		return (NULL);
	while (*s1)
	{
		*d1 = *s1;
		d1++;
		s1++;
	}
	*d1 = '\0';
	return (d1 - len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*full_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	full_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 +1));
	if (!full_str)
		return (NULL);
	while (*s1)
		full_str[i++] = *s1++;
	while (*s2)
		full_str[i++] = *s2++;
	full_str[i] = '\0';
	return (full_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		counter;

	counter = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (*s && len-- > 0)
	{
		*substr++ = *((s++) + start);
		counter++;
	}
	*substr = '\0';
	return (substr - counter);
}
