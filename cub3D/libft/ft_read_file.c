/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:21:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/05 18:15:59 by aherrero         ###   ########.fr       */
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
		free(str);
	}
	return (x);
}

char	*ft_read_file(char *name, int len)
{
	char	*str;
	int		fd;

	len = count_bytes(name);
	if (len <= 0)
		return (NULL);
	str = NULL;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	fd = open(name, O_RDONLY);
	read(fd, str, len);
	close(fd);
	str[len] = '\0';
	return (str);
}
