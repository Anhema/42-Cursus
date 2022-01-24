/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:10:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 18:42:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	stack->chunk = (int *)malloc(stack->capacity * sizeof(int));
	stack->head = -1;
	stack->a = 0;
	stack->limit = 0;
	return (stack);
}

int	median(t_stack *stack)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i <= stack->head)
	{
		j = 0;
		while (j <= stack->head)
		{
			if (stack->array[i] < stack->array[j])
				n++;
			j++;
		}
		if (n == (stack->head + 1) / 2)
			return (stack->array[i]);
		n = 0;
		i++;
	}
	return (-1);
}

t_stack	*fill_stack(char **argv)
{
	t_stack	*stack;

	if (argv[2] == NULL)
		stack = fill_string(argv);
	else
		stack = fill_args(argv);
	stack->top = stack->array[0];
	stack->head = stack->capacity - 1;
	return (stack);
}

t_stack
	*split_by_median(t_stack *stack_to, t_stack *stack_from, int chunk)
{
	int	i;
	int	count;
	int	pivot;

	i = 0;
	pivot = median(stack_from);
	count = get_over_median(stack_from, pivot);
	while (count > 0)
	{
		if (stack_from->array[0] <= pivot)
		{
			stack_to = push_operation(stack_to, stack_from);
			stack_to->chunk[0] = chunk;
			count --;
		}
		else
			stack_from = rotate(stack_from);
		i++;
	}
	stack_from->median = median(stack_from);
	return (stack_to);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (check_errors(argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack = fill_stack(argv);
	if (stack->limit == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack->a = 1;
	if (check_repeated(stack) == 0 || stack == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check_sort(stack))
		return (0);
	sort_stack(stack);
	return (0);
}
