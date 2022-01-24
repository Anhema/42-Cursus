/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 21:23:05 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*split_by_median_stack_aux(t_stack *stack_to,
	t_stack *stack_from, int chunk)
{
	int	i;
	int	j;
	int	pivot;

	i = 0;
	pivot = median_chunk(stack_from);
	j = stack_from->head;
	while (i <= j)
	{
		if (stack_from->array[0] < pivot && stack_from->chunk[0] == chunk)
		{
			stack_to = push_operation(stack_to, stack_from);
			stack_to->chunk[0] = chunk;
		}
		else
			stack_from = rotate(stack_from);
		i++;
	}
	stack_from->median = median(stack_from);
	return (stack_to);
}

// static t_stack	*sort_five_aux(t_stack *stack, t_stack *stack_b)
// {
// 	int	chunk;
// 	int	i;

// 	i = stack_b->head;
// 	chunk = get_max_chunk(stack);
// 	while (chunk_count(stack, chunk) >= 3)
// 		stack_b = split_by_median_stack_aux(stack_b, stack, chunk);
// 	if (stack->head == 2)
// 		stack = sort_three(stack);
// 	else
// 		stack = sort_chunk_two(stack, 0);
// 	i = stack_b->head - i;
// 	while (i > 0)
// 	{
// 		stack = push_operation(stack, stack_b);
// 		i--;
// 	}
// 	if (stack->head == 2)
// 		stack = sort_three(stack);
// 	else
// 		stack = sort_chunk_two(stack, 0);
// 	return (stack);
// }

t_stack	*sort_ten(t_stack *stack, t_stack *stack_b)
{
	int	chunk;
	int	i;

	// chunk = 0;
	// while (chunk <= stack->head)
	// {
	// 	ft_putnbr_fd(stack->array[chunk], 1);
	// 	ft_putchar_fd('\n', 1);
	// 	chunk++;
	// }
	chunk = get_max_chunk(stack);
	i = stack_b->head;
	while (chunk_count(stack, chunk) >= 5)
		stack_b = split_by_median_stack_aux(stack_b, stack, ++chunk);
	// chunk = 0;
	// while (chunk <= stack->head)
	// {
	// 	ft_putnbr_fd(stack->array[chunk], 1);
	// 	ft_putchar_fd('\n', 1);
	// 	chunk++;
	// }
	if (chunk_count(stack, chunk) == 2)
		stack = sort_three(stack);
	else if (chunk_count(stack, chunk) < 2)
		stack = sort_chunk_two(stack, 0);
	else
		stack = sort_only_five(stack, stack_b);
	i = stack_b->head - i;
	while (i > 0)
	{
		stack = push_operation(stack, stack_b);
		i--;
	}
	if (chunk_count(stack, chunk) == 2)
		stack = sort_three(stack);
	else if (chunk_count(stack, chunk) < 2)
		stack = sort_chunk_two(stack, 0);
	else
		stack = sort_five(stack, stack_b);
	// chunk = 0;
	// while (chunk <= stack->head)
	// {
	// 	ft_putnbr_fd(stack->array[chunk], 1);
	// 	ft_putchar_fd('\n', 1);
	// 	chunk++;
	// }
	return (stack);
}
