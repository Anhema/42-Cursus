/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:11:04 by aherrero          #+#    #+#             */
/*   Updated: 2021/12/29 17:55:16 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				top;
	unsigned int	capacity;
	int				*array;
	int				*chunk;
	int				head;
	int				a;
	int				median;
}	t_stack;

int		check_errors(char **argv);
int		check_repeated(t_stack *stack);
t_stack	*create_stack(unsigned int capacity);
t_stack	*fill_args(char **argv);
t_stack	*fill_string(char **argv);
t_stack	*swap(t_stack *stack);
t_stack	*push_operation(t_stack *stack_a, t_stack *stack_b);
t_stack	*rotate(t_stack *stack);
t_stack	*reverse_rotate(t_stack *stack);
t_stack	*sort_stack(t_stack *stack);
t_stack	*sort_two(t_stack *stack);
t_stack	*sort_three(t_stack *stack);
t_stack	*sort_three_b(t_stack *stack);
int		check_sort(t_stack *stack);
int		chunk_count(t_stack *stack, int chunk);
t_stack	*sort_chunk_two(t_stack *stack, int chunk);
t_stack	*split_stack_chunk(t_stack *stack);
int		median_chunk(t_stack *stack);
int		chunk_end(t_stack *stack);
int		get_max_chunk(t_stack *stack);
t_stack	*sort_by_chunk(t_stack *stack);
t_stack	*split_by_median(t_stack *stack_to, t_stack *stack_from, int chunk);
void	print_stack(t_stack *stack, t_stack *stack_b);
int	get_next_chunk_pos(t_stack *stack, int start, int chunk);
int		check_sort_chunk(t_stack *stack);
t_stack	*remove_top(t_stack *stack);

#endif