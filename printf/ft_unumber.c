/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:06:22 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/20 16:21:34 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_number_to_str(unsigned int n)
{
	char			*result;
	int				len;
	unsigned int	temp;

	len = 1;
	temp = n / 10;
	while (temp)
	{
		len++;
		temp /= 10;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (n % 10 + '0');
		n /= 10;
	}
	return (result);
}

int	ft_print_unumber(unsigned int n)
{
	char	*str;
	int		i;

	str = ft_number_to_str(n);
	i = ft_print_str(str);
	free(str);
	return (i);
}
