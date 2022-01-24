/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:50 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 21:11:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack)
{
	t_stack	*stack_b;
	int		chunk;

	stack_b = create_stack(stack->capacity);
	chunk = 0;
	while (stack->head >= 10)
		split_by_median(stack_b, stack, ++chunk);
	if (stack->head < 2)
		stack = sort_chunk_two(stack, 0);
	else if (stack->head == 2)
		stack = sort_three(stack);
	else if (stack->head > 2 && stack->head < 5)
		sort_only_five(stack, stack_b);
	else
		sort_only_ten(stack, stack_b);
	while (chunk > 0)
	{
		stack_b = split_stack_chunk(stack_b);
		stack_b = sort_by_chunk(stack_b, stack);
		chunk = get_max_chunk(stack_b);
	}
	// chunk = 0;
	// while (chunk <= stack->head)
	// {
	// 	ft_putnbr_fd(stack->array[chunk], 1);
	// 	ft_putchar_fd('\n', 1);
	// 	chunk++;
	// }
	free_mem(stack, stack_b);
}

int	get_over_median(t_stack *stack, int pivot)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= stack->head)
	{
		if (stack->array[i] <= pivot)
			count++;
		i++;
	}
	return (count);
}
