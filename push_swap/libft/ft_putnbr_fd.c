/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:38:07 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/04 18:14:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		i;

	i = n;
	if (n <= -2147483647 - 1)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 10 && i >= 0)
	{
		a = i + '0';
		write(fd, &a, 1);
	}
	else if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		a = i % 10 + '0';
		write(fd, &a, 1);
	}
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
}
