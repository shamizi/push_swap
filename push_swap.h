/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:42 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/18 23:53:34 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack t_stack;
struct					s_stack
{
	int *a;
	int *b;
	int i;
	int size_a;
	int size_b;
	int action;
};

void	swap_a(t_stack *stack, int print);
void	swap_b(t_stack *stack, int print);
void	swap_double(t_stack * stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack, int print);
void	rotate_b(t_stack *stack, int print);
void	rotate_both(t_stack *stack);
void	reverse_rotate_a(t_stack *stack, int print);
void	reverse_rotate_b(t_stack *stack, int print);
void	reverse_rotate_both(t_stack *stack);
int	is_sort(t_stack *stack);
int	bigger(t_stack *stack);
void	sort(t_stack *stack, int b);
void	solve_two(t_stack *stack);
void	solve_three(t_stack *stack, int a, int b, int c);
void	solve_end(t_stack *stack, int i);
void	sort_plus(t_stack * stack);
void	empty_b(t_stack *stack);
#endif
