/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:09:47 by aherrero          #+#    #+#             */
/*   Updated: 2021/07/27 17:33:44 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
