/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:03 by aherrero          #+#    #+#             */
/*   Updated: 2022/01/05 13:22:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_chunk_two(t_stack *stack, int chunk)
{
	int	x;
	int	y;

	x = stack->array[0];
	y = stack->array[1];
	if (chunk != 0)
	{
		if (x < y)
			return (swap(stack));
	}
	else
	{
		if (x > y)
			return (swap(stack));
	}
	return (stack);
}
