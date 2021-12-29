/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:45:06 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/29 23:32:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_chunk(t_stack *stack)
{
	int	i;
	int	j;
	int	n;
	int	chunk;

	i = 0;
	n = 0;
	while (i <= stack->head)
	{
		chunk = get_max_chunk(stack);
		if (stack->chunk[i] == chunk)
		{
			j = chunk_end(stack);
			while (j <= stack->head)
			{
				if (stack->array[i] < stack->array[j] && stack->chunk[j] == chunk)
					n++;
				j++;
			}
		}
		if (n == (chunk_count(stack, chunk) / 2))
		{
			//printf("\nCHUNK = %d\nCHUNK COUNT = %d\nN = %d\n", chunk, chunk_count(stack, chunk), stack->array[i]);
			return (stack->array[i]);
		}
		n = 0;
		i++;
	}
	return (-1);
}

int	chunk_end(t_stack *stack)
{
	int	i;
	int	start;
	int	end;
	int	chunk;

	i = 0;
	start = 0;
	end = 0;
	chunk = get_max_chunk(stack);
	while (i <= stack->head)
	{
		if (stack->chunk[i] == chunk)
			return (i);
		i++;
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

int	get_next_chunk_pos(t_stack *stack, int start, int chunk)
{
	int	i;

	i = stack->head / 2;
	if (start == 1)
	{
		while (i <= stack->head)
		{
			if (stack->chunk[i] == chunk)
				return (i);
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			if (stack->chunk[i] == chunk)
				return (i);
			i--;
		}
	}
	return (-1);
}
