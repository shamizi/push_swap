/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:47:00 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/06 00:40:49 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_top(t_stack *stack, int chunk, int i)
{
	int		ret;

	ret = 0;
	while (ret < stack->size_a)
	{
		if (is_in_chunk(stack, stack->a[ret], ((chunk * i) - chunk), chunk * i))
			return (ret);
		ret++;
	}
	return (-1);
}

int	scan_bot(t_stack *stack, int chunk, int i)
{
	int		ret;
	int		cmp;

	ret = stack->size_a -1;
	cmp = 0;
	while (ret > 0)
	{
		if (is_in_chunk(stack, stack->a[ret], ((chunk * i) - chunk), chunk * i))
			return (cmp);
		ret--;
		cmp++;
	}
	return (-1);
}

void	scan(t_stack *stack, int chunk, int i)
{
	int		j;
	int		top;
	int		bot;

	top = scan_top(stack, chunk, i);
	bot = scan_bot(stack, chunk, i);
	j = 0;
	if (top <= bot)
	{
		while (j < top)
		{
			rotate_a(stack, 1);
			j++;
		}
		push_b(stack);
	}
	else
	{
		while (j -1 < bot)
		{
			reverse_rotate_a(stack, 1);
			j++;
		}
		push_b(stack);
	}
}

void	sort_plus(t_stack *stack, int chunk)
{
	int		i;

	i = 1;
	while (stack->size_a)
	{
		while (stack->size_b < chunk * i && stack->size_a)
			scan(stack, chunk, i);
		i++;
	}
	while (stack->size_b)
	{
		i = 0;
		while (stack->b[i] != stack->sorted[stack->size_b -1])
			i++;
		if (i == 0)
			push_a(stack);
		else if (i < stack->size_b / 2)
			rotate_b(stack, 1);
		else
			reverse_rotate_b(stack, 1);
	}
}
