/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:28:25 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/06 16:13:13 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if (*s == (unsigned char)c)
		return ((char *)s);
	while (*s++)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_alloc(int buffer_size)
{
	char	*cache;

	cache = malloc(buffer_size + 2);
	if (!cache)
		return (NULL);
	return (cache);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s1[len] != '\0')
		len++;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		result[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		result[j++] = s2[i];
	result[j] = '\0';
	free ((char *)s1);
	return (result);
}
