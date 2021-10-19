/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:38:36 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/18 13:29:59 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack, int print)
{
	int tmp;
	int i;

	i = 0;
	if (stack->size_a < 2)
		return ;
	tmp = stack->a[0];
	while(i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = tmp;
	if (print)
	{
		write(1, "ra\n", 3);
		stack->action++;
	}
}

void	rotate_b(t_stack *stack, int print)
{
	int tmp;
	int i;

	i = 0;
	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	while(i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = tmp;
	if (print)
	{
		write(1, "rb\n", 3);
		stack->action++;
	}
}

void	rotate_both(t_stack *stack)
{
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	write(1, "rr\n", 3);
	stack->action++;
}
