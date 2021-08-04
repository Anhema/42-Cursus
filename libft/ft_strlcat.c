/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:27:49 by errero            #+#    #+#             */
/*   Updated: 2021/07/27 18:22:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	i;
	size_t	j;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	i = 0;
	j = lendst;
	if (lendst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] != '\0' && j < (dstsize - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (lendst >= dstsize)
		lendst = dstsize;
	return (lendst + lensrc);
}
