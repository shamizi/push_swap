/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:38:45 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/05 15:53:08 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_chunk(t_stack *stack, int to_find, int beg, int end)
{
	while (beg < end && beg < stack->size_sorted)
	{
		if (to_find == stack->sorted[beg])
			return (1);
		beg++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	solution(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->size_a -1)
	{
		j = 0;
		while (j < stack->size_a -1 - i)
		{
			if (stack->sorted[j] > stack->sorted[j +1])
				ft_swap(&stack->sorted[j], &stack->sorted[j + 1]);
			j++;
		}
		i++;
	}
}
