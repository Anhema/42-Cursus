/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation_aux_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:48:27 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:47:09 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	if (n != 2)
	{
		free(value);
		print_map_error("RGB invalid input arguments", file, lines);
	}
	rgb = ft_split(value, ',');
	ft_rgb_checker(value, rgb, file, lines);
	if (value)
		free (value);
	free_double_char(rgb);
}
