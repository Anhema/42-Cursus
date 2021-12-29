/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:52:06 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/24 15:09:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	int	temp;
	int	temp_chunk;

	if (stack->head <= 0 || stack->capacity == 1)
		return (stack);
	temp = stack->array[stack->head];
	temp_chunk = stack->chunk[stack->head];
	stack->array[stack->head] = stack->array[stack->head - 1];
	stack->chunk[stack->head] = stack->chunk[stack->head - 1];
	stack->array[stack->head - 1] = temp;
	stack->chunk[stack->head - 1] = temp_chunk;
	stack->top = stack->array[stack->head];
	if (stack->a == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	return (stack);
}

t_stack	*push_operation(t_stack *stack_to, t_stack *stack_from)
{
	int		i;
	int		j;

	if (stack_from->head < 0)
		return (stack_to);
	i = 0;
	j = stack_to->capacity;
	stack_to->head = stack_to->head + 1;
	stack_to->array[stack_to->head] = stack_from->array[stack_from->head];
	//stack_to->chunk[stack_to->head] = 0;
	stack_to->top = stack_from->top;
	stack_from->head -= 1;
	stack_from->top = stack_from->array[stack_from->head];
	if (stack_from->a == 1)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
	return (stack_to);
}

t_stack	*rotate(t_stack *stack)
{
	int	temp;
	int	temp_chunk;
	int	i;

	temp = stack->array[stack->head];
	temp_chunk = stack->chunk[stack->head];
	i = stack->head;
	while (i >= 0)
	{
		stack->array[i] = stack->array[i - 1];
		stack->chunk[i] = stack->chunk[i - 1];
		i--;
	}
	stack->array[0] = temp;
	stack->chunk[0] = temp_chunk;
	stack->top = stack->array[stack->head];
	if (stack->a == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	return (stack);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	int	temp;
	int	temp_chunk;
	int	i;

	temp = stack->array[0];
	temp_chunk = stack->chunk[0];
	i = 0;
	while (i <= stack->head - 1)
	{
		stack->array[i] = stack->array[i + 1];
		stack->chunk[i] = stack->chunk[i + 1];
		i++;
	}
	stack->array[stack->head] = temp;
	stack->chunk[stack->head] = temp_chunk;
	stack->top = stack->array[stack->head];
	if (stack->a == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	return (stack);
}
