/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:12:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/05 12:37:08 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int	i;
	int	chunk;

	chunk = get_max_chunk(stack);
	i = 0;
	if (stack->a == 1)
	{
		while (i < stack->head)
		{
			if (stack->array[i] > stack->array[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < stack->head)
		{
			if (stack->chunk[i + 1] == chunk)
				if (stack->array[i] < stack->array[i + 1])
					return (0);
			i++;
		}
	}
	return (1);
}

int	check_sort_chunk(t_stack *stack)
{
	int	i;
	int	control;
	int	chunk;

	i = 0;
	control = 0;
	chunk = get_max_chunk(stack);
	if (chunk_count(stack, chunk) == 1 && stack->chunk[0] == chunk)
		return (1);
	while (i <= stack->head)
	{
		if (stack->chunk[i] == chunk && control != 0)
			return (0);
		if (stack->chunk[i] != chunk)
			control = 1;
		i++;
	}
	return (1);
}

int	chunk_count(t_stack *stack, int chunk)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i <= stack->head)
	{
		if (stack->chunk[i] == chunk)
			n++;
		i++;
	}
	return (n);
}
