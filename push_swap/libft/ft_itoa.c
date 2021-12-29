/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:01:21 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/02 19:57:43 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_get_digits(long n)
{
	size_t	digits;
	int		neg;

	digits = 0;
	neg = 0;
	if (n < 0)
	{
		digits++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static char	*ft_strgen(char *dest, long nbr, int len, int neg)
{
	if (nbr != 0)
		dest = malloc(sizeof(char) * (len + 1));
	else
		return (dest = ft_strdup("0"));
	if (!dest)
		return (0);
	neg = 0;
	if (nbr < 0)
	{
		neg++;
		nbr = -nbr;
	}
	dest[len] = '\0';
	while (--len)
	{
		dest[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg >= 1)
		dest[0] = '-';
	else
		dest[0] = (nbr % 10) + '0';
	return (dest);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	int		neg;
	char	*result;

	nbr = n;
	len = ft_get_digits(nbr);
	neg = 0;
	result = 0;
	result = ft_strgen(result, nbr, len, neg);
	if (!result)
		return (0);
	return (result);
}
