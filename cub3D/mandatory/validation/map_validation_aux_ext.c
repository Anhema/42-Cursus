/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_aux_ext.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:29:53 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:48:06 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_header_n(int n, char *file, char **lines)
{
	if (n > 6)
		print_map_error("To many Identifier", file, lines);
	if (n < 6)
		print_map_error("Missing Identifier", file, lines);
}

int	ft_check_header_first(char **lines, int i, int j)
{
	if (((lines[i][j] == 'N' && lines[i][j + 1] == 'O')
			|| (lines[i][j] == 'S' && lines[i][j + 1] == 'O')
			|| (lines[i][j] == 'W' && lines[i][j + 1] == 'E')
			|| (lines[i][j] == 'E' && lines[i][j + 1] == 'A'))
			&& lines[i][j + 2] == ' ')
		return (1);
	return (0);
}

int	ft_check_f_and_c(char **lines, int i, int j)
{
	if ((lines[i][j] == 'F' || lines[i][j] == 'C')
				&& lines[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	ft_invalid_identifier(char **lines, char *file, int i, int j)
{
	j = -1;
	while (lines[i][++j])
		if (lines[i][j] != '1' && lines[i][j] != '0'
				&& lines[i][j] != ' ')
			print_map_error("Invalid Identifier", file, lines);
	return (1);
}
