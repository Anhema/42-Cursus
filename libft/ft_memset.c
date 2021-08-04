/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:30:36 by errero            #+#    #+#             */
/*   Updated: 2021/07/27 15:40:28 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = b;
	while (len > 0)
	{
		temp[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
