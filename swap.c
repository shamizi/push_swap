/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:23:39 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 15:52:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack, int print)
{
	int		tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
		if (print)
		{
			write(1, "sa\n", 3);
			stack->action++;
		}
	}
}

void	swap_b(t_stack *stack, int print)
{
	int		tmp;

	if (stack->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
		if (print)
		{
			write(1, "sb\n", 3);
			stack->action++;
		}
	}
}

void	swap_double(t_stack *stack)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	write(1, "ss\n", 3);
	stack->action++;
}
