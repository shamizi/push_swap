/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:46:25 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/19 01:53:07 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_two(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		swap_a(stack, 1);
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

void	solve_end(t_stack *stack, int i)
{
	if (i == 1)
		swap_a(stack, 1);
	reverse_rotate_a(stack, 1);
	reverse_rotate_a(stack, 1);
	swap_a(stack, 1);
	rotate_a(stack, 1);
	rotate_a(stack, 1);
}

void	empty_b(t_stack *stack)
{
	while (stack->size_b)
		push_a(stack);
}


void	sort_plus(t_stack *stack)
{
	int pos;

	while(stack->size_a > 3)
	{
		pos = bigger(stack);
		if (stack->a[pos] == stack->a[0])
			push_b(stack);
		else if (pos <  (stack->size_a)/ 2)
			rotate_a(stack, 1);
		else
			reverse_rotate_a(stack, 1);
	}
	solve_three(stack, stack->a[0], stack->a[1], stack->a[2]);
	empty_b(stack);
	return ;
}
