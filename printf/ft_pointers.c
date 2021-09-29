/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:45:54 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/21 19:29:41 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_upper_lower(char *str, size_t n, int size, int c)
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

char	*ft_htoa(size_t n, int c)
{
	char	*res;
	size_t	size;
	size_t	aux;

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

int	ft_print_pointer(size_t p)
{
	int		count;
	char	*str;

	count = 0;
	count += ft_print_char('0');
	count += ft_print_char('x');
	str = ft_htoa(p, 'x');
	count += ft_print_str(str);
	free (str);
	return (count);
}
