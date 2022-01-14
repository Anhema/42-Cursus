/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:57:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/12 17:41:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_stack *stack, t_stack *stack_b)
{
	free(stack->array);
	free(stack->chunk);
	free(stack);
	free(stack_b->chunk);
	free(stack_b->array);
	free(stack_b);
}

int	ft_atoi_error(const char *str)
{
	long	result;
	int		minus;

	result = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		if ((result * minus <= -2147483648) || (result * minus >= 2147483648))
			return (0);
		str++;
	}
	return (1);
}

int	args_errors(char **argv)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	while (argv[n])
	{
		if (ft_atoi_error(argv[n]) == 0)
			return (0);
		i = 0;
		while (argv[n][i])
		{
			if (argv[n][i] == '-' && i > 0)
				return (0);
			if ((argv[n][i] >= '0' && argv[n][i] <= '9') || argv[n][i] == '-')
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
			if (argv[1][i] == '-' &&
				(argv[1][i - 1] >= '0' && argv[1][i - 1] <= '9'))
				return (0);
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
	while (i <= stack->head)
	{
		temp = stack->array[i];
		j = i + 1;
		while (j <= stack->head)
		{
			if (temp == stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
