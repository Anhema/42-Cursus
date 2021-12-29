/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:10:44 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/29 23:44:28 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		stack = fill_string(argv);
	}
	else
		stack = fill_args(argv);
	stack->top = stack->array[stack->capacity - 1];
	stack->head = stack->capacity - 1;
	return (stack);
}

void	print_stack(t_stack *stack, t_stack *stack_b)
{
	int	i;

	i = stack->capacity - 1;
	printf("\nSTACK		CHUNK			|			STACK_B		CHUNK\n");
	while (i >= 0)
	{
		if (i > stack->head)
			printf("-		-			|			");
		else
			printf("%d		%d			|			", stack->array[i], stack->chunk[i]);
		if (i > stack_b->head)
			printf("-		-\n");
		else
			printf("%d		%d\n", stack_b->array[i], stack_b->chunk[i]);
		i--;
	}
	printf("\nTOP = %d				|				TOP = %d\n", stack->top, stack_b->top);
	printf("CAPACITY = %d				|				CAPACITY = %d\n",
		stack->capacity, stack_b->capacity);
	printf("HEAD = %d				|				HEAD = %d\n", stack->head, stack_b->head);
	printf("MEDIANA = %d				|				MEDIANA_MAX_CHUNK = %d\n",
		median(stack), median_chunk(stack_b));
	printf("IS SORT = %d				|				IS_SORT_MAX_CHUNK = %d\n",
		check_sort(stack), check_sort(stack_b));
	printf("______________________________________________________\n\n\n\n");
}

t_stack
	*split_by_median(t_stack *stack_to, t_stack *stack_from, int chunk)
{
	int	i;
	int	j;
	int	pivot;

	i = 0;
	pivot = median(stack_from);
	j = stack_from->head;
	while (i <= j)
	{
		if (stack_from->top <= pivot)
		{
			stack_to = push_operation(stack_to, stack_from);
			stack_to->chunk[stack_to->head] = chunk;
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
	t_stack	*stack_b;
	int		chunk;
	int		i;

	if (argc < 2)
	{
		ft_print_colors("ERROR: Se necesitan 2 argumentos minimo\n", "red");
		return (0);
	}
	if (check_errors(argv) == 0)
	{
		ft_print_colors("ERROR: no puede contener letras\n", "red");
		return (0);
	}
	stack = fill_stack(argv);
	stack->a = 1;
	if (check_repeated(stack) == 0)
	{
		ft_print_colors("ERROR: numeros repetidos\n", "red");
		return (0);
	}
	stack_b = create_stack(stack->capacity);
	chunk = 0;
	//print_stack(stack, stack_b);
	while (stack->head > 2)
		split_by_median(stack_b, stack, ++chunk);
	if (stack->head == 2)
		stack = sort_three(stack);
	else
		stack = sort_chunk_two(stack, 0);
	//print_stack(stack, stack_b);
	while (chunk > 0)
	{
		if (check_sort(stack_b))
		{
			i = stack_b->head;
			while (i >= 0)
			{
				if (stack_b->chunk[i] == chunk)
					stack = push_operation(stack, stack_b);
				i--;
			}
		}
		if (chunk_count(stack_b, chunk) == 2)
			stack_b = sort_chunk_two(stack_b, chunk);
		else if (chunk_count(stack_b, chunk) == 3)
		{
			//print_stack(stack, stack_b);
			stack_b = sort_three_b(stack_b);
			//print_stack(stack, stack_b);
		}
		else
		{
			//print_stack(stack, stack_b);
			stack_b = split_stack_chunk(stack_b);
			//print_stack(stack, stack_b);
			stack_b = sort_by_chunk(stack_b);
			//print_stack(stack, stack_b);
		}
		chunk = get_max_chunk(stack_b);
	}
	print_stack(stack, stack_b);
	if (check_sort(stack))
		ft_print_colors("✅ OK", "green");
	free(stack->array);
	free(stack->chunk);
	free(stack);
	free(stack_b->chunk);
	free(stack_b->array);
	free(stack_b);
	return (0);
}
