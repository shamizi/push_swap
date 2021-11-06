/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:46:25 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 17:25:17 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_two(t_stack *stack, int i)
{
	if (stack->a[0] > stack->a[1])
		swap_a(stack, 1);
	else if (stack->b[0] < stack->b[1] && i)
		swap_b(stack, 1);
}

void	solve_three(t_stack *stack, int a, int b, int c)
{
	if (a > b && b > c)
	{
		swap_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack, 1);
	else if (a > b && c > a)
		swap_a(stack, 1);
	else if (a < b && b > c && c < a)
		reverse_rotate_a(stack, 1);
	else if (a < b && b > c)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
}

void	solve_five(t_stack *stack, int size)
{
	int		i;

	i = 0;
	while (i < size -3)
	{
		if (stack->a[0] == stack->sorted[0]
			|| (stack->a[0] == stack->sorted[1] && size == 5))
		{
			push_b(stack);
			i++;
		}
		else
			rotate_a(stack, 1);
	}
	solve_three(stack, stack->a[0], stack->a[1], stack->a[2]);
	if (size == 5)
		solve_two(stack, 1);
	empty_b(stack);
}

void	empty_b(t_stack *stack)
{
	while (stack->size_b)
		push_a(stack);
}
