/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:43 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/19 01:54:06 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *stack)
{
	int i;

	i = 0;
	if(stack->size_b != 0)
		return(0);
	while (i < stack->size_a -1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	bigger(t_stack *stack)
{
	int tmp;
	int pos;
	int i;

	i = 0;
	pos = 0;
	tmp = stack->a[0];
	while(i < stack->size_a)
	{
		if (stack->a[i] < tmp)
		{
			pos = i;
			tmp = stack->a[i];
		}
		i++;
	}
	return (pos);
}
void	sort(t_stack *stack, int b)
{
	if (is_sort(stack))
		return ;
	if (stack->size_a == 2)
		solve_two(stack);
	else if (stack->size_a == 3)
		solve_three(stack, stack->a[0], stack->a[1], stack->a[2]);
	else if (stack->a[0] > stack->a[1] &&
		stack->a[stack->size_a -2] > stack->a[stack->size_a -1] && b)
		solve_end(stack, 1);
	else if (stack->a[0] > stack->a[1] && b)
		swap_a(stack, 1);
	else if (stack->a[stack->size_a - 2] > stack->a[stack->size_a - 1] && b)
		solve_end(stack, 0);
	else
		sort_plus(stack);
	if (is_sort(stack) == 0)
		sort(stack, 0);
	printf("fin de fonction sort\n");
}
