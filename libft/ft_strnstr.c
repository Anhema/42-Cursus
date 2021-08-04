/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:52:26 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 17:33:11 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] != '\0'
			&& i + j < (int)len && needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)(haystack + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
