/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:24:10 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 19:05:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(*s1) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[j++] = s2[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
