/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:57:51 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/24 12:55:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_errors(char **argv)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	while (argv[n])
	{
		i = 0;
		while (argv[n][i])
		{
			if (
				(argv[n][i] >= '0' && argv[n][i] <= '9') || argv[n][i] == '-')
				i++;
			else
				return (0);
		}
		n++;
	}
	return (1);
}

int	check_errors(char **argv)
{
	int	i;

	i = 0;
	if (argv[2] == NULL)
	{
		if (ft_strcmp(argv[1], "") == 1)
			return (0);
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' ||
				(argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == '-')
				i++;
			else
				return (0);
		}
	}
	else
	{
		if (args_errors(argv) == 0)
			return (0);
	}
	return (1);
}

int	check_repeated(t_stack *stack)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (stack->array[i])
	{
		temp = stack->array[i];
		j = i + 1;
		while (stack->array[j])
		{
			if (temp == stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
