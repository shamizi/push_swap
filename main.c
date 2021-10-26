/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:24:50 by shamizi           #+#    #+#             */
/*   Updated: 2021/10/26 16:27:01 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str,int i, t_stack *stack)
{
	if (stack->av)
		freestrings(stack->av);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->sorted)
		free(stack->sorted);
	free(stack);
	write(2, str, i);
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
				ft_exit("Error\n", 6, stack);
			j++;
		}
		i++;
	}
}

void	ft_free(t_stack *stack)
{
	if (stack->sorted)
		free(stack->sorted);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack->av)
		freestrings(stack->av);
	if (stack)
		free(stack);

}

int	main(int argc, char **argv)
{
	t_stack *stack;

	stack = malloc(sizeof(*stack));
	initialize(stack);
	if (argc != 2)
		ft_exit("Error\nargument format\n",22, stack);
	argc = nb_mot(argv[1], ' ');
	stack->av = ft_split(argv[1], ' ');
	stack->a = (int*)malloc(sizeof(int) * (argc + 1));
	stack->b = (int*)malloc(sizeof(int) * (argc + 1));
	stack->sorted = (int *)malloc(sizeof(int) * (argc + 1));
	while(stack->i < argc)
	{
		if (check_arg(stack->av[stack->i]))
			stack->i++;
		else
			ft_exit("Error\n", 6, stack);
	}
	stack->size_a = argc;
	stack->size_sorted = stack->size_a;
	init_stack(stack, stack->av);
	solution(stack);
	sort(stack);
	ft_free(stack);
	return (0);
}
