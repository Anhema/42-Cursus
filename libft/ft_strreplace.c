/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:03:29 by aherrero          #+#    #+#             */
/*   Updated: 2022/04/19 18:15:45 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strreplace_aux(char	*result, char *orig, char *rep, char *with)
{
	int	i;
	int	newwlen;
	int	oldwlen;

	newwlen = ft_strlen(with);
	oldwlen = ft_strlen(rep);
	i = 0;
	while (*orig)
	{
		if (ft_strstr(orig, rep) == orig)
		{
			result = ft_strcpy(&result[i], with);
			i += newwlen;
			orig += oldwlen;
		}
		else
			result[i++] = *orig++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strreplace(char *orig, char *rep, char *with)
{
	char	*result;
	int		i;
	int		cnt;
	int		newwlen;
	int		oldwlen;

	newwlen = ft_strlen(with);
	oldwlen = ft_strlen(rep);
	cnt = 0;
	i = 0;
	while (orig[i] != '\0')
	{
		if (ft_strstr(&orig[i], rep) == &orig[i])
		{
			cnt++;
			i += oldwlen - 1;
		}
		i++;
	}
	result = (char *)malloc(sizeof(char) * (i + cnt * (newwlen - oldwlen) + 1));
	result = ft_strreplace_aux(result, orig, rep, with);
	return (result);
}
