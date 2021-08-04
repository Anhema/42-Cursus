/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:38:22 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 18:21:00 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*temp;
	unsigned const char		*aux;
	size_t					i;

	i = 0;
	temp = dst;
	aux = src;
	if (temp == NULL && aux == NULL)
		return (dst);
	while (n > 0)
	{
		temp[i] = aux[i];
		if (temp[i] == (unsigned char)c)
			return (temp + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
