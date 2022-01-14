/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 19:25:48 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_three_stack_aux(t_stack *stack)
{
	int	x;
	int	y;
	int	j;

	x = stack->array[0];
	y = stack->array[1];
	j = stack->array[2];
	if (x < y && y > j && x < j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if (x < y && y > j && x > j)
	{
		stack = rotate(stack);
		stack = swap(stack);
		stack = reverse_rotate(stack);
		return (swap(stack));
	}
	return (stack);
}

t_stack	*sort_three_stack(t_stack *stack)
{
	int	x;
	int	y;
	int	j;

	x = stack->array[0];
	y = stack->array[1];
	j = stack->array[2];
	if (x > y && y < j && x < j)
		return (swap(stack));
	if (x > y && y < j && x > j)
	{
		stack = swap(stack);
		stack = rotate(stack);
		stack = swap(stack);
		return (reverse_rotate(stack));
	}
	if (x > y && y > j && x > j)
	{
		stack = swap(stack);
		stack = rotate(stack);
		stack = swap(stack);
		stack = reverse_rotate(stack);
		return (swap(stack));
	}
	return (sort_three_stack_aux(stack));
}

static t_stack	*sort_three_aux(t_stack *stack)
{
	int	x;
	int	y;
	int	j;

	x = stack->array[0];
	y = stack->array[1];
	j = stack->array[2];
	if (x < y && y < j && x < j)
	{
		stack = rotate(stack);
		stack = rotate(stack);
		return (rotate(stack));
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

	x = stack->array[0];
	y = stack->array[1];
	j = stack->array[2];
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
		return (rotate(stack));
	return (sort_three_aux(stack));
}
