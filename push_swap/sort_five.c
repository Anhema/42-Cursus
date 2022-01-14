/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 19:36:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_five_final(t_stack *stack, t_stack *stack_b, int j, int n)
{
	while (n > 0)
	{
		stack = reverse_rotate(stack);
		n--;
	}
	if (stack_b->head == 2)
		stack_b = sort_three(stack_b);
	else
		stack_b = sort_chunk_two(stack_b, 1);
	if (stack->head == 2)
		stack = sort_three(stack);
	else
		stack = sort_three_stack(stack);
	stack = push_operation(stack, stack_b);
	stack->chunk[0] = 0;
	if (j == 2)
	{
		stack = push_operation(stack, stack_b);
		stack->chunk[0] = 0;
	}
	return (stack);
}

static int	get_temp(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->array[0];
	while (i <= chunk_end(stack))
	{
		if (stack->array[i] < temp)
			temp = stack->array[i];
		i++;
	}
	return (temp);
}

static int	get_temp_b(t_stack *stack)
{
	int	temp;
	int	temp_b;
	int	i;

	i = 0;
	temp = stack->array[0];
	temp_b = stack->array[0];
	while (i <= chunk_end(stack))
	{
		if (stack->array[i] < temp)
			temp = stack->array[i];
		if (stack->array[i] > temp)
			temp_b = stack->array[i];
		i++;
	}
	while (i >= 0)
	{
		if (stack->array[i] < temp_b && stack->array[i] > temp)
		{
			temp_b = stack->array[i];
		}
		i--;
	}
	return (temp_b);
}

static t_stack	*sort_five_move(t_stack *stack, t_stack *stack_b, int i, int j)
{
	int	n;
	int	temp;
	int	temp_b;

	n = 0;
	temp = get_temp(stack);
	temp_b = get_temp_b(stack);
	while (i > 0)
	{
		if (stack->array[0] == temp)
		{
			stack_b = push_operation(stack_b, stack);
			stack->chunk[0] = 0;
			temp = temp_b;
			i--;
		}
		else
		{
			stack = rotate(stack);
			n++;
		}
	}
	return (sort_five_final(stack, stack_b, j, n));
}

t_stack	*sort_five(t_stack *stack, t_stack *stack_b)
{
	int	i;
	int	n;
	int	j;
	int	temp;
	int	temp_b;

	n = 0;
	temp = get_temp(stack);
	temp_b = get_temp_b(stack);
	if (chunk_count(stack, get_max_chunk(stack)) == 5)
		i = 2;
	else
		i = 1;
	j = i;
	stack = sort_five_move(stack, stack_b, i, j);
	return (stack);
}
