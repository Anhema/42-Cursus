/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:03 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/29 23:40:41 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_chunk_two(t_stack *stack, int chunk)
{
	int	x;
	int	y;

	x = stack->array[stack->head];
	y = stack->array[stack->head - 1];
	if (chunk != 0)
	{
		if (x < y)
			return (swap(stack));
	}
	else
	{
		if (x < y)
			return (swap(stack));
	}
	return (stack);
}

t_stack	*sort_three_b(t_stack *stack)
{
	int	x;
	int	y;
	int	j;

	x = stack->array[stack->head];
	y = stack->array[stack->head - 1];
	j = stack->array[stack->head - 2];
	if (x > y && y < j && x < j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		stack = reverse_rotate(stack);
		return (swap(stack));
	}
	if (x > y && y < j && x > j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if (x > y && y > j && x > j)
	{
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if (x < y && y < j && x < j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		stack = reverse_rotate(stack);
		stack = swap(stack);
		stack = rotate(stack);
		stack = swap(stack);
		stack =  reverse_rotate(stack);
		return (stack);
	}
	if (x < y && y > j && x < j)
	{
		stack = swap(stack);
		return (rotate(stack));
	}
	if (x < y && y > j && x > j)
		return (reverse_rotate(stack));
	return (stack);
}

t_stack	*sort_three(t_stack *stack)
{
	int	x;
	int	y;
	int	j;

	x = stack->array[stack->head];
	y = stack->array[stack->head - 1];
	j = stack->array[stack->head - 2];
	if (x > y && y < j && x < j)
		return (swap(stack));
	if ((x > y && y < j && x < j))
		return (swap(stack));
	if (x > y && y > j && x > j)
	{
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if (x > y && y < j && x > j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if ((x < y && y < j && x < j) && stack->a != 1)
	{
		stack = swap(stack);
		stack = rotate(stack);
		stack = swap(stack);
		stack = reverse_rotate(stack);
		return (swap(stack));
	}
	if (x < y && y > j && x < j)
	{
		stack = swap(stack);
		return (rotate(stack));
	}
	if (x < y && y > j && x > j)
		return (reverse_rotate(stack));
	return (stack);
}

int	check_sort(t_stack *stack)
{
	int	i;
	int	chunk;

	chunk = get_max_chunk(stack);
	i = stack->head;
	if (stack->a == 1)
	{
		while (i > 0)
		{
			if (stack->array[i] > stack->array[i - 1])
				return (0);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (stack->chunk[i - 1] == chunk)
				if (stack->array[i] < stack->array[i - 1])
					return (0);
			i--;
		}
	}
	return (1);
}

int	check_sort_chunk(t_stack *stack)
{
	int	i;
	int	control;
	int	chunk;

	i = stack->head;
	control = 0;
	chunk = get_max_chunk(stack);
	while (i >= 0)
	{
		if (stack->chunk[i] == chunk && control != 0)
			return (0);
		if (stack->chunk[i] != chunk)
			control = 1;
		i--;
	}
	return (1);
}
