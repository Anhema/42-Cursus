/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:21:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/03 18:21:09 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int	count_bytes(char *filename)
{
	char	*str;
	int		fd;
	int		x;
	int		n;

	x = 0;
	n = 0;
	while (n == x)
	{
		n++;
		fd = open(filename, O_RDONLY);
		str = malloc(sizeof(char) * n);
		if (str == NULL)
			return (0);
		x = read(fd, str, n);
		close(fd);
	}
	free(str);
	return (x);
}

char	*ft_read_file(char *name, int len)
{
	char	*str;
	int		fd;
	int		ret;

	len = count_bytes(name);
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	fd = open(name, O_RDONLY);
	ret = read(fd, str, len);
	close(fd);
	return (str);
}
