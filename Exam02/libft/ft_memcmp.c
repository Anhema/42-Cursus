/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:41:21 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/03 18:21:52 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		while (n--)
		{
			if (*(unsigned char *)s1 != *(unsigned char *)s2)
				return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
			s1++;
			s2++;
		}
	}
	return (0);
}
