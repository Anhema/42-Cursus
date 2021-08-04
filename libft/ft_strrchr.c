/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:20:28 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/03 16:45:35 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	while (*s++)
	{
		if (*s == (unsigned char)c)
			temp = (char *)s;
		if (*s == '\0')
			break ;
	}
	return (temp);
}
