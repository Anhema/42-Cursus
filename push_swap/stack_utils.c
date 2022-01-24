/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:09:31 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/13 21:21:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_string(char **argv)
{
	int		i;
	char	**nbrs;
	t_stack	*stack;

	i = 0;
	nbrs = ft_split(argv[1], ' ');
	while (nbrs[i])
		i++;
	stack = create_stack(i);
	i = 0;
	while (nbrs[i])
	{
		if (ft_atoi_error(nbrs[i]) == 0)
			stack->limit = 1;
		stack->array[i] = ft_atoi(nbrs[i]);
		stack->chunk[i] = 0;
		i++;
	}
	free (nbrs);
	return (stack);
}

t_stack	*fill_args(char **argv)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 1;
	while (argv[i])
		i++;
	stack = create_stack(i - 1);
	i = 1;
	j = 0;
	while (argv[i])
	{
		stack->array[j] = ft_atoi(argv[i]);
		stack->chunk[j] = 0;
		i++;
		j++;
	}
	return (stack);
}

t_stack	*split_stack_chunk(t_stack *stack)
{
	int	i;
	int	m;

	while (chunk_count(stack, get_max_chunk(stack)) > 5)
	{
		i = stack->head;
		m = median_chunk(stack);
		while (i >= 0)
		{
			if (stack->array[i] >= m + 1)
				stack->chunk[i] += 1;
			i--;
		}
	}
	return (stack);
}

static t_stack	*sort_by_chunk_aux(t_stack *stack, t_stack *stack_b, int j)
{
	int	i;

	i = 0;
	if (j <= 2)
		stack_b = sort_chunk_two(stack_b, 0);
	else if (j == 3)
		stack_b = sort_three_stack(stack_b);
	else if (j <= 5 && j > 3)
		stack_b = sort_five(stack_b, stack);
	else if (j <= 10 && j > 5)
		stack_b = sort_ten(stack_b, stack);
	i = 0;
	while (i <= stack_b->head)
	{
		stack_b->chunk[i] = 0;
		i++;
	}
	return (stack_b);
}

t_stack	*sort_by_chunk(t_stack *stack, t_stack *stack_b)
{
	int	chunk;
	int	i;
	int	j;

	chunk = get_max_chunk(stack);
	i = chunk_count(stack, chunk);
	j = i;
	while (i > 0)
	{
		if (stack->chunk[0] == chunk)
		{
			stack_b = push_operation(stack_b, stack);
			i--;
		}
		else
		{
			//if (chunk_start(stack) <= stack->head / 2)
			if (chunk_start(stack) < stack->head - chunk_end(stack))
				stack = rotate(stack);
			else
				stack = reverse_rotate(stack);
		}
	}
	sort_by_chunk_aux(stack, stack_b, j);
	return (stack);
}
