/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:28:55 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/22 17:47:36 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	ft_params(char *str, t_nodo *aux, t_nodo **lst)
{
	if (ft_check_sign(str) && ft_check_digit(str)
		&& ft_range_int((long)ft_atoi(str), ft_atoi_long(str)))
	{
		aux = create_nodo(ft_atoi(str));
		if (repeat_value(aux->date, *lst))
			insert_last(lst, aux);
		else
		{
			printf("error:repeat_value");
			exit(0);
		}
	}
	else
		exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_nodo		*aux;
	t_nodo		*stack_a;
	t_nodo		*stack_b;
	char		**arg;

	stack_a = init_list();
	stack_b = init_list();
	aux = init_list();
	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
			ft_params(argv[i], aux, &stack_a);
	}
	else if (argc == 2)
	{
		i = -1;
		arg = ft_split(argv[1], ' ');
		while (arg[++i] != NULL)
			ft_params(arg[i], aux, &stack_a);
	}
	if (ft_stack_sorted(stack_a))
		return (printf("error:stack ordenado\n"), 1);
	ft_asign_index(&(stack_a), ft_size_lst(stack_a));
	ft_position(&(stack_a));
	printf("++++++++++++++++++++++++++Stack a:\n");
	print_stack(stack_a);
	printf("+++++++++++++++++++++++++++Stack b:\n");
	printf("size b:%d\n", ft_size_lst(stack_b));
	print_stack(stack_b);
	//pb(&stack_a, &stack_b);
	ft_sort(&(stack_a), &(stack_b));
	//ft_calc_cost(&(stack_a), &(stack_b));
	printf("+++++++++++++++++++++++++++++Stack a :\n");
	printf("size a:%d\n", ft_size_lst(stack_a));
	print_stack(stack_a);
	printf("++++++++++++++++++++++++++++++Stack b:\n");
	printf("size b:%d\n", ft_size_lst(stack_b));
	print_stack(stack_b);
	return (1);
}
