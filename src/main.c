/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:28:55 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/07/06 22:14:25 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	ft_params(char **str, t_nodo *aux, t_nodo **lst, int wall)
{
	if (ft_check_sign(*str) && ft_check_digit(*str)
		&& ft_range_int((long)ft_atoi(*str), ft_atoi_long(*str)))
	{
		aux = create_nodo(ft_atoi(*str));
		if (repeat_value(aux->date, *lst))
			insert_last(lst, aux);
		else
		{
			if (fail_parse(wall) == 0)
				return (0);
		}	
	}
	else
		fail_parse(wall);
	return (1);
}

static void	ft_two_params(char **argv, t_nodo *aux, t_nodo **stack_a)
{
	int		i;	
	char	**arg;

	i = 0;
	arg = ft_split(argv[1], ' ');
	while (arg[i] != NULL)
	{
		if (ft_params(&arg[i], aux, stack_a, 1))
			i++;
		else
		{
			free_memory(arg);
			exit(0);
		}
	}
	free_memory(arg);
}

// void	leaks(void)
// {
// 	system("leaks -q push_swap");
// }

static void	stack_is_sorted(t_nodo *stack_a)
{
	ft_free_lst(stack_a);
	exit(EXIT_SUCCESS);
}

static int	order_stack(t_nodo **stack_a, t_nodo **stack_b)
{
	ft_asign_index(stack_a, ft_size_lst(*stack_a));
	ft_position(stack_a);
	if (ft_size_lst(*stack_a) == 2)
	{
		ft_sort_two(stack_a);
		ft_free_lst(*stack_a);
		exit (1);
	}
	else if (ft_size_lst(*stack_a) == 3)
	{	
		ft_sort_three(stack_a);
		ft_free_lst(*stack_a);
		exit (1);
	}
	else if (ft_size_lst(*stack_a) > 3)
	{
		*stack_b = init_list();
		ft_sort(stack_a, stack_b);
	}
	ft_free_lst(*stack_a);
	ft_free_lst(*stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_nodo		*aux;
	t_nodo		*stack_a;
	t_nodo		*stack_b;

	//atexit(leaks);
	stack_a = init_list();
	aux = NULL;
	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
			ft_params(&argv[i], aux, &stack_a, 0);
	}
	else if (argc == 1)
		exit (1);
	else if (argc <= 2)
		ft_two_params(argv, aux, &(stack_a));
	if (ft_size_lst(stack_a) == 0)
		error(stack_a);
	if (ft_stack_sorted(stack_a))
		stack_is_sorted(stack_a);
	order_stack(&(stack_a), &(stack_b));
	return (1);
}
