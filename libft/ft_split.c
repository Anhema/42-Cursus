/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:26:48 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/03 20:08:43 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_cleanup(char **dic, size_t i)
{
	size_t	j;

	if (dic)
	{
		j = 0;
		while (j < i)
		{
			if (dic[j] != NULL)
				free(dic[i]);
			i++;
		}
		free(dic);
	}
	return (NULL);
}

static int	file_lines(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		count++;
	}
	if (str[i - 1] == c)
		count--;
	return (count);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && *str != c)
	{
		str++;
		count++;
	}
	return (count);
}

static char	**fill_dic(char **dest, const char *str, char to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == to_find)
			str++;
		if (*str == '\0')
			continue ;
		dest[i] = malloc(sizeof(char *) * ft_word_len(str, to_find) + 1);
		if (dest[i] == NULL)
			return (ft_cleanup(dest, i));
		j = 0;
		while (*str != to_find && *str != '\0')
		{
			dest[i][j] = *str;
			j++;
			str++;
		}
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		lines;

	if (s == NULL)
		return (NULL);
	i = 0;
	lines = file_lines(s, c);
	dest = malloc(sizeof(char *) * (lines + 1));
	if (dest == NULL)
		return (NULL);
	fill_dic(dest, s, c);
	return (dest);
}
