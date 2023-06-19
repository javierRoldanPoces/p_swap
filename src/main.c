/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:28:55 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/19 17:59:09 by javier           ###   ########.fr       */
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
		{
			ft_params(argv[i], aux, &stack_a);
			//ft_params(argv[i], aux, &stack_b);
		}
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
	printf("Stack a:\n");
	print_stack(stack_a);
	reverse(&(stack_a), 'a');
	printf("\n************************\n");
	printf("Stack a tras reverse a:\n");
	print_stack(stack_a);
	print_stack(stack_b);
	print_stack(stack_b);
/*	//swap(&(stack_a), 'a');
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	printf("\nStack a tras 2 pb:\n");
	print_stack(stack_a);
	printf("\nStack b tras 2 pb:\n");
	print_stack(stack_b);
	ss(&(stack_a), &(stack_b));
	printf("\nStack a tras ss:\n");
	print_stack(stack_a);
	printf("\nStack b tras ss:\n");
	print_stack(stack_b);*/
	return (1);
}
