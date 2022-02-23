/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:46:56 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 18:21:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;
	const char		*aux;
	size_t			i;

	i = 0;
	temp = dst;
	aux = src;
	if (temp == NULL && aux == NULL)
		return (dst);
	while (n > 0)
	{
		temp[i] = aux[i];
		n--;
		i++;
	}
	return (dst);
}
