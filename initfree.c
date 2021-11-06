/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:55:21 by shamizi           #+#    #+#             */
/*   Updated: 2021/11/06 01:33:37 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	if (stack->av)
		freestrings(stack->av);
	if (stack->sorted)
		free(stack->sorted);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
}

void	ft_exit(char *str, int i, t_stack *stack)
{
	if (stack->av)
		freestrings(stack->av);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->sorted)
		free(stack->sorted);
	if (stack)
		free(stack);
	write(1, str, i);
	exit(EXIT_FAILURE);
}

void	initialize(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->sorted = NULL;
	stack->i = 1;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->size_sorted = 0;
	stack->action = 0;
	stack->av = NULL;
}
