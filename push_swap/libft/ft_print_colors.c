/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:22:27 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/05 12:31:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_colors(char *str, char *color)
{
	if (ft_strcmp("black", color))
		ft_putstr_fd("\033[0;30m", 1);
	if (ft_strcmp("red", color))
		ft_putstr_fd("\033[0;31m", 1);
	if (ft_strcmp("green", color))
		ft_putstr_fd("\033[0;32m", 1);
	if (ft_strcmp("yellow", color))
		ft_putstr_fd("\033[0;33m", 1);
	if (ft_strcmp("blue", color))
		ft_putstr_fd("\033[0;34m", 1);
	if (ft_strcmp("purple", color))
		ft_putstr_fd("\033[0;35m", 1);
	if (ft_strcmp("cyan", color))
		ft_putstr_fd("\033[0;36m", 1);
	if (ft_strcmp("white", color))
		ft_putstr_fd("\033[0;37m", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\033[0m", 1);
}
