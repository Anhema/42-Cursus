/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:52:06 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/05 12:45:00 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	int	temp;
	int	temp_chunk;

	if (stack->head <= 0 || stack->capacity == 1)
		return (stack);
	temp = stack->array[0];
	temp_chunk = stack->chunk[0];
	stack->array[0] = stack->array[1];
	stack->chunk[0] = stack->chunk[1];
	stack->array[1] = temp;
	stack->chunk[1] = temp_chunk;
	stack->top = stack->array[0];
	if (stack->a == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
	return (stack);
}

static void	print_push(t_stack *stack_from)
{
	if (stack_from->a == 1)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
}

t_stack	*push_operation(t_stack *stack_to, t_stack *stack_from)
{
	int		i;

	if (stack_from->head < 0)
		return (stack_to);
	stack_to->head = stack_to->head + 1;
	i = stack_to->head;
	while (i > 0)
	{
		stack_to->array[i] = stack_to->array[i - 1];
		stack_to->chunk[i] = stack_to->chunk[i - 1];
		i--;
	}
	stack_to->array[0] = stack_from->array[0];
	stack_to->chunk[0] = stack_from->chunk[0];
	stack_to->top = stack_to->array[0];
	while (i < stack_from->head)
	{
		stack_from->array[i] = stack_from->array[i + 1];
		stack_from->chunk[i] = stack_from->chunk[i + 1];
		i++;
	}
	stack_from->head -= 1;
	stack_from->top = stack_from->array[0];
	print_push(stack_from);
	return (stack_to);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	int	temp;
	int	temp_chunk;
	int	i;

	temp = stack->array[stack->head];
	temp_chunk = stack->chunk[stack->head];
	i = stack->head;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		stack->chunk[i] = stack->chunk[i - 1];
		i--;
	}
	stack->array[0] = temp;
	stack->chunk[0] = temp_chunk;
	stack->top = stack->array[0];
	if (stack->a == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	return (stack);
}

t_stack	*rotate(t_stack *stack)
{
	int	temp;
	int	temp_chunk;
	int	i;

	temp = stack->array[0];
	temp_chunk = stack->chunk[0];
	i = 0;
	while (i < stack->head)
	{
		stack->array[i] = stack->array[i + 1];
		stack->chunk[i] = stack->chunk[i + 1];
		i++;
	}
	stack->array[stack->head] = temp;
	stack->chunk[stack->head] = temp_chunk;
	stack->top = stack->array[0];
	if (stack->a == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	return (stack);
}
