/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:49:28 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 15:43:32 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack, int print)
{
	int		tmp;
	int		i;

	i = stack->size_a;
	if (i < 2)
		return ;
	tmp = stack->a[stack->size_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (print)
	{
		write(1, "rra\n", 4);
		stack->action++;
	}
}

void	reverse_rotate_b(t_stack *stack, int print)
{
	int		tmp;
	int		i;

	i = stack->size_b;
	if (i < 2)
		return ;
	tmp = stack->b[stack->size_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (print)
	{
		write(1, "rrb\n", 4);
		stack->action++;
	}
}

void	reverse_rotate_both(t_stack *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	write(1, "rrr\n", 4);
	stack->action++;
}
