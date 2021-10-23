/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:24:50 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/23 17:07:45 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str)
{
	write(2, str, 6);
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
}

int	ft_atoi(char *str)
{
	int i;
	long res;
	int neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	return (res);
}
long	ft_longtoi(char *str)
{
	int i;
	long res;
	int neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * neg;
	return (res);
}


int	check_arg(char *str)
{
	int i;
	long res;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	res = ft_longtoi(str);
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

void	init_stack(t_stack *stack, char **argv)
{
	int i;
	int j;

	i = 0;
	argv++;
	while(*argv)
	{
		stack->a[i] = ft_atoi(*argv);
		stack->sorted[i] = ft_atoi(*argv);
		argv++;
		i++;
	}
	i = 0;
	while(i < stack->size_a)
	{
		j = 1;
		while(i + j < stack->size_a)
		{
			if (stack->a[i] == stack->a[i + j])
				ft_exit("Error\n");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(*stack));
	initialize(stack);
	stack->a = (int*)malloc(sizeof(int) * (argc + 1));
	stack->b = (int*)malloc(sizeof(int) * (argc + 1));
	stack->sorted = (int *)malloc(sizeof(int) * (argc + 1));
	while(stack->i < argc)
	{
		if (check_arg(argv[stack->i]))
			stack->i++;
		else
			ft_exit("Error\n");
	}
	stack->size_a = argc - 1;
	stack->size_sorted = stack->size_a;
	init_stack(stack, argv);
	solution(stack);
	sort(stack);
///////////////////
	int i = 0;
	while (i < stack->size_a)
	{
		printf("stack a : %d \t sorted : %d\n",stack->a[i],stack->sorted[i]);
		i++;
	}
	i = 0;
	while (i < stack->size_b)
	{
		printf("stack b%d : %d\n",i, stack->b[i]);
		i++;
	}
	if (is_sort(stack) == 0)
		printf("is_sort\n");
	else 
		printf("isnotsort\n");
	return (0);
}
