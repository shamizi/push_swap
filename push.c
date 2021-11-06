/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:55:14 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 15:07:56 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	if (stack->size_b > 0)
	{
		tmp = stack->b[0];
		while (i < stack->size_b)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		i = stack->size_a;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = tmp;
		stack->size_a++;
		stack->size_b--;
		write(1, "pa\n", 3);
		stack->action++;
	}
}

void	push_b(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	if (stack->size_a > 0)
	{
		tmp = stack->a[0];
		while (i < stack->size_a)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		i = stack->size_b;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = tmp;
		stack->size_a--;
		stack->size_b++;
		write(1, "pb\n", 3);
		stack->action++;
	}
}
