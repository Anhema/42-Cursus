/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:20:07 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 19:35:35 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	if (s == NULL)
		return (NULL);
	result = malloc(sizeof(*s) * len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		result[i] = '\0';
		return (result);
	}
	while (len > 0)
	{
		result[i] = s[start];
		i++;
		len--;
		start++;
	}
	result[i] = '\0';
	return (result);
}
