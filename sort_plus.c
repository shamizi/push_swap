/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:47:00 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/23 19:39:13 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_top(t_stack *stack,int size, int chunk, int i)
{
	int ret;

	ret = 0;
	while (ret < stack->size_a)
	{
		if (is_in_chunk(stack, stack->a[ret], ((chunk *i) - chunk), chunk * i, 1))
			return (ret);
		ret++;
	}
	if (size == 200)
		return (200);
	return (-1);
}

int scan_bot(t_stack *stack, int size, int chunk, int i)
{
	int ret;
	int cmp;

	ret = stack->size_a -1;
	cmp = 0;
	while (ret > 0)
	{
		if (is_in_chunk(stack, stack->a[ret], ((chunk *i) - chunk), chunk * i, 1))
			return (cmp);
		ret--;
		cmp++;
	}
	if (size == 200)
		return (200);
	return (-1);

}

void	scan(t_stack *stack,int size,int chunk, int i)
{
	int j;
	int top;
	int bot;

	top = scan_top(stack, size, chunk, i);
	bot = scan_bot(stack, size, chunk, i);
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

/*void	sort_b(t_stack *stack, int pos)
{
		if (stack->b[0] == stack->b[pos])
			push_a(stack);
		else if (pos < stack->size_b / 2)
			rotate_b(stack, 1);
		else
			reverse_rotate_b(stack, 1);
}
*/
void	sort_plus(t_stack *stack, int size, int chunk)
{
	int i;

	i = 1;
	while (stack->size_a)
	{
		while (stack->size_b < chunk * i && stack->size_a)
			scan(stack, size, chunk, i);
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
			rotate_b(stack, 0);
		else
			reverse_rotate_b(stack, 0);
	}
}
