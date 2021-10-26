/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:42 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/26 15:58:38 by shamizi          ###   ########.fr       */
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
	int *sorted;
	int i;
	int size_a;
	int size_b;
	int size_sorted;
	int action;
	char **av;
};

char **freestrings(char **tab);
int	nb_mot(char *s, char c);
char	**ft_split(char *s, char c);
int	is_in_chunk(t_stack *stack, int to_find, int beg, int end, int rev);
int		find_case(t_stack *stack);
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
void	sort(t_stack *stack);
void	solve_two(t_stack *stack, int i);
void	solve_three(t_stack *stack, int a, int b, int c);
void	solve_five(t_stack *stack, int size);
void	solve_end(t_stack *stack, int i);
void	sort_plus(t_stack *stack, int size, int chunk);
void	empty_b(t_stack *stack);
void	solution(t_stack *stack);
#endif
