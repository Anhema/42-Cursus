/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:21:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/09 16:43:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**check_repeated_header(char **lines, char *file,
	char **header, char *current)
{
	char	**new;
	char	*id;
	int		i;

	i = 0;
	new = NULL;
	id = malloc(sizeof(char) * 3);
	id[0] = current[0];
	id[1] = current[1];
	id[2] = '\0';
	if (header)
	{
		while (header && header[i])
		{
			if (ft_strcmp(header[i], id) == 0)
			{
				ft_free(header, current, id);
				print_map_error("Repeated indentifier", file, lines);
			}
			i++;
		}
	}
	new = create_new(header, i, id);
	return (ft_free(header, current, id), new);
}

int	indentifies_value_validation(char **lines, int j, int i, char *file)
{
	int		n;
	int		fd;
	char	*value;

	while (lines[i][j] == ' ')
		j++;
	value = NULL;
	value = ft_calloc((ft_strlen(lines[i]) - j + 1), sizeof(char));
	if (!value)
		print_map_error("Identifier has no value", file, lines);
	n = -1;
	while (lines[i][j])
		value[++n] = lines[i][j++];
	value[n + 1] = '\0';
	i = -1;
	while (value[++i])
		ft_check_identifier(value, file, lines, i);
	value = ft_strreplace(value, " ", "");
	ft_check_format(value, file, lines);
	fd = open(value, O_RDONLY);
	ft_indentifier_error(value, fd, file, lines);
	close(fd);
	free (value);
	return (1);
}

int	check_f_c_validation(char **lines, int j, int i, char *file)
{
	int		n;
	char	*value;

	while (lines[i][j] == ' ')
		j++;
	value = NULL;
	value = ft_calloc((ft_strlen(lines[i]) - j + 1), sizeof(char));
	if (!value)
		print_map_error("Identifier has no value", file, lines);
	n = -1;
	while (lines[i][j])
		value[++n] = lines[i][j++];
	value[n + 1] = '\0';
	i = -1;
	n = 0;
	while (value[++i])
	{
		if (value[i] == ' ')
			ft_check_identifier(value, file, lines, i);
		if (value[i] == ',')
			n++;
	}
	check_rgb(value, file, lines, n);
	return (1);
}
