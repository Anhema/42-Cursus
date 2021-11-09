/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:26:48 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/09 12:58:04 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_freemem(char **dic, size_t i)
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

static size_t	file_lines(const char *str, char c)
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
	while (*str != c && *str != '\0')
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
		while (*str == to_find && *str != '\0')
			str++;
		if (*str == '\0')
			continue ;
		dest[i] = malloc(sizeof(char) * ft_word_len(str, to_find) + 1);
		if (dest[i] == NULL)
			return (ft_freemem(dest, i));
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

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) > 0)
		dest = malloc(sizeof(char *) * (file_lines(s, c) + 1));
	else
		dest = malloc(sizeof(char *) * (0 + 1));
	if (dest == NULL)
		return (NULL);
	fill_dic(dest, s, c);
	return (dest);
}
