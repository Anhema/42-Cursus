/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:36:58 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/06 21:13:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	set_contains(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	result = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (set_contains(s1[i], set) == 0)
		i++;
	if (i == ft_strlen(s1))
	{
		result = ft_strdup("");
		if (result == NULL)
			return (NULL);
		else
			return (result);
	}
	while (set_contains(s1[j - 1], set) == 0)
		j--;
	result = ft_substr(s1, i, j - i);
	return (result);
}
