/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:24:53 by aherrero          #+#    #+#             */
/*   Updated: 2021/09/27 18:45:45 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_numbers(int number)
{
	char	*result;
	int		count;

	result = ft_itoa(number);
	count = 0;
	while (result[count] != '\0')
	{
		ft_putchar_fd(result[count], 1);
		count++;
	}
	free(result);
	return (count);
}
