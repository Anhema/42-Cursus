/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:33:51 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/22 17:58:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

static void	ft_upper_lower(char *str, unsigned int n, int size, int c)
{
	str[size] = '\0';
	while (size--)
	{
		if (n % 16 < 10)
		{
			str[size] = (n % 16) + '0';
			n /= 16;
		}
		else
		{
			str[size] = (n % 16) + c;
			n /= 16;
		}
	}
}

static char	*ft_htoa(unsigned int n, int c)
{
	char			*res;
	int				size;
	unsigned int	aux;

	size = 1;
	aux = n / 16;
	while (aux)
	{
		size++;
		aux /= 16;
	}
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	if (c == 'x')
		c = 87;
	else
		c = 55;
	ft_upper_lower(res, n, size, c);
	return (res);
}

int	ft_print_hexadecimal(unsigned int i, char c)
{
	int		count;
	char	*str;

	str = ft_htoa(i, c);
	count = 0;
	count += ft_print_str(str);
	free (str);
	return (count);
}
