/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:20:28 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/09 12:47:38 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		len;

	len = ft_strlen(s);
	if (*(s + len) == (char) c)
		return ((char *)s + len);
	temp = NULL;
	while (s)
	{
		if (*s == (unsigned char)c)
			temp = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (temp);
}
