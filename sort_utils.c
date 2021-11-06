/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:43 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 15:50:59 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size_a -1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	bigger(t_stack *stack)
{
	int		tmp;
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	tmp = stack->b[0];
	while (i < stack->size_b -1)
	{
		if (stack->b[i] > tmp)
		{
			pos = i;
			tmp = stack->b[i];
		}
		i++;
	}
	return (pos);
}

void	sort(t_stack *stack)
{
	if (!is_sort(stack))
		return ;
	if (stack->size_a == 2)
		solve_two(stack, 0);
	else if (stack->size_a == 3)
		solve_three(stack, stack->a[0], stack->a[1], stack->a[2]);
	else if (stack->size_a <= 5)
		solve_five(stack, stack->size_a);
	else if (stack->size_a <= 100)
		sort_plus(stack, stack->size_a / 5);
	else if (stack->size_a <= 500)
		sort_plus(stack, stack->size_a / 11);
	else
		sort_plus(stack, stack->size_a / 20);
}
