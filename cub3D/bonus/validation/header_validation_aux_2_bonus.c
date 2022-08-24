/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation_aux_2_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:48:27 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:48:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**create_new(char **header, int i, char *id)
{
	char	**new;
	int		n;

	new = NULL;
	new = (char **)ft_calloc(i + 2, sizeof(char *));
	n = 0;
	while (n < i)
	{
		new[n] = ft_strdup(header[n]);
		n++;
	}
	new[i] = ft_strdup(id);
	return (new);
}

void	ft_free(char **header, char *current, char *id)
{
	free_double_char(header);
	free (current);
	free (id);
}

void	check_rgb(char *value, char *file, char **lines, int n)
{
	char	**rgb;
	int		fd;

	if (n != 2)
	{
		ft_check_format(value, file, lines);
		fd = open(value, O_RDONLY);
		ft_indentifier_error(value, fd, file, lines);
		close(fd);
		free(value);
	}
	else
	{
		rgb = ft_split(value, ',');
		ft_rgb_checker(value, rgb, file, lines);
		if (value)
			free (value);
		free_double_char(rgb);
	}
}
