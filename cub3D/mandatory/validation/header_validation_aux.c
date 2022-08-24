/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation_aux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:51:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:48:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_format(char *value, char *file, char **lines)
{
	if (!(value[ft_strlen(value) - 1] == 'm'
			&& value[ft_strlen(value) - 2] == 'p'
			&& value[ft_strlen(value) - 3] == 'x'
			&& value[ft_strlen(value) - 4] == '.'))
	{
		free(value);
		print_map_error("Texture invalid format", file, lines);
	}
}

void	ft_check_identifier(char *value, char *file, char **lines, int i)
{
	int	j;

	if (value[i] == ' ')
	{
		j = i - 1;
		while (value[++j])
		{
			if (value[j] != ' ')
			{
				free (value);
				print_map_error
					("More than one value in a identifier", file, lines);
			}
		}
	}
}

void	ft_indentifier_error(char *value, int fd, char *file, char **lines)
{
	if (fd < 0)
	{
		close(fd);
		free(value);
		print_map_error("Cannot open identifier value", file, lines);
	}
}

static void	ft_rgb_errors(char *value, char **rgb, char *file, char **lines)
{
	free (value);
	free_double_char(rgb);
	print_map_error
		("RGB invalid input arguments", file, lines);
}

void	ft_rgb_checker(char *value, char **rgb, char *file, char **lines)
{
	int	i;
	int	n;

	i = -1;
	while (rgb[++i])
	{
		if ((rgb[i + 1] && i >= 2) || (!rgb[i + 1] && i <= 1))
			ft_rgb_errors(value, rgb, file, lines);
		n = -1;
		while (rgb[i][++n])
			if (rgb[i][n] < '0' || rgb[i][n] > '9')
				ft_rgb_errors(value, rgb, file, lines);
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_rgb_errors(value, rgb, file, lines);
	}
}
