/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:04:50 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/06 16:39:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_contains_n(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
	}
	return (0);
}

char	*ft_get_line(char *cache)
{
	int		i;
	char	*rest;

	if (!cache)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	rest = malloc(i + 2);
	if (!rest)
		return (NULL);
	i = -1;
	while (cache[++i] && cache[i] != '\n')
		rest[i] = cache[i];
	if (ft_contains_n(cache))
		rest[i++] = '\n';
	rest[i] = '\0';
	return (rest);
}

char	*ft_get_cache(char *cache)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!(ft_contains_n(cache)) && cache)
	{
		free(cache);
		return (NULL);
	}
	while (cache[i] && (cache[i] != '\n'))
		i++;
	rest = malloc((ft_strlen(cache) - i) + 1);
	if (!rest)
		return (NULL);
	if (cache[i] != 0)
		i++;
	while (cache[i])
		rest[j++] = cache[i++];
	rest[j] = '\0';
	free(cache);
	return (rest);
}

char	*ft_error(int readed, char *line)
{
	if (readed == 0 && !ft_strlen(line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*buff;
	char		*dst;
	static char	*cache;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_alloc(BUFFER_SIZE);
	ret = 1;
	while (ret > 0 && !ft_contains_n(cache))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		cache = ft_strjoin(cache, buff);
	}
	free(buff);
	dst = ft_get_line(cache);
	cache = ft_get_cache(cache);
	return (ft_error(ret, dst));
}
