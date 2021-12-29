/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:09:31 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/29 23:44:00 by aherrero         ###   ########.fr       */
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
	return (stack);
}

t_stack	*fill_string(char **argv)
{
	int		i;
	int		j;
	char	**nbrs;
	t_stack	*stack;

	i = 0;
	nbrs = ft_split(argv[1], ' ');
	while (nbrs[i])
		i++;
	stack = create_stack(i);
	i--;
	j = 0;
	while (nbrs[i])
	{
		stack->array[j] = ft_atoi(nbrs[i]);
		stack->chunk[j] = 0;
		i--;
		j++;
	}
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
	i--;
	j = 0;
	while (i >= 1)
	{
		stack->array[j] = ft_atoi(argv[i]);
		stack->chunk[j] = 0;
		i--;
		j++;
	}
	return (stack);
}

t_stack	*split_stack_chunk(t_stack *stack)
{
	int	i;
	int	m;

	//printf("\nMEDIAN = %d\nCHUNK COUNT = %d\n", 0, 0);
	while (chunk_count(stack, get_max_chunk(stack)) > 2)
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

t_stack	*sort_by_chunk(t_stack *stack)
{
	int	chunk;
	int	head;
	int	i;
	int	n;

	chunk = get_max_chunk(stack);
	head = stack->head;
	n = 0;
	i = 0;
	//printf("\nCHUNK: %d\nCHUNK COUNT: %d\n", chunk, chunk_count(stack, chunk));
	while (n < chunk_count(stack, chunk))
	{
		if (stack->chunk[stack->head] != chunk)
			stack->head--;
		else
		{
				stack = rotate(stack);
				i++;
				n++;
		}
	}
	stack->head = head;
	while (i > 0)
	{
		stack = reverse_rotate(stack);
		i--;
	}
	return (stack);
}
