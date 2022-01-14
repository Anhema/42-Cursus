/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:45:06 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 19:06:05 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_chunk_aux(t_stack *stack, int i, int n)
{
	int	chunk;
	int	j;

	chunk = get_max_chunk(stack);
	if (stack->chunk[i] == chunk)
	{
		j = chunk_start(stack);
		while (j <= stack->head)
		{
			if (stack->array[i] < stack->array[j]
				&& stack->chunk[j] == chunk)
				n++;
			j++;
		}
	}
	return (n);
}

int	median_chunk(t_stack *stack)
{
	int	i;
	int	n;
	int	chunk;

	i = 0;
	n = 0;
	while (i <= stack->head)
	{
		chunk = get_max_chunk(stack);
		n = median_chunk_aux(stack, i, n);
		if (n == (chunk_count(stack, chunk) / 2))
			return (stack->array[i]);
		n = 0;
		i++;
	}
	return (-1);
}

int	chunk_start(t_stack *stack)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_max_chunk(stack);
	while (i <= stack->head)
	{
		if (stack->chunk[i] == chunk)
			return (i);
		i++;
	}
	return (-1);
}

int	chunk_end(t_stack *stack)
{
	int	i;
	int	chunk;

	i = stack->head;
	chunk = get_max_chunk(stack);
	while (i >= 0)
	{
		if (stack->chunk[i] == chunk)
			return (i);
		i--;
	}
	return (-1);
}

int	get_max_chunk(t_stack *stack)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = 0;
	while (i <= stack->head)
	{
		if (stack->chunk[i] > chunk)
			chunk = stack->chunk[i];
		i++;
	}
	return (chunk);
}
