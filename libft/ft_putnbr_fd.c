/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:38:07 by aherrero          #+#    #+#             */
/*   Updated: 2021/08/03 19:47:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			a;
	char			b;
	unsigned int	i;

	i = (unsigned int)n;
	if (i < 10 && i >= 0)
	{
		a = i + '0';
		write(fd, &a, 1);
	}
	else if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		b = i % 10 + '0';
		write(fd, &b, 1);
	}
	else
	{
		write(1, "-", 1);
		ft_putnbr_fd(i * -1, fd);
	}
}
