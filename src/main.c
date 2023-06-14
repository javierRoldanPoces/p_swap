/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:28:55 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/14 20:26:43 by Jroldan-         ###   ########.fr       */
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
	t_push_swap	*ps;
	char		**arg;

	ps = init();
	ps = init_push_swap();
	aux = init_list();
	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
		{
			ft_params(argv[i], aux, &(ps)->stack_a);
			ft_params(argv[i], aux, &(ps)->stack_b);
		}
	}
	else if (argc == 2)
	{
		i = -1;
		arg = ft_split(argv[1], ' ');
		while (arg[++i] != NULL)
			ft_params(arg[i], aux, &(ps)->stack_a);
	}
	if (ft_stack_sorted(ps->stack_a))
		return (printf("error:stack ordenado\n"), 1);
	ps->size = i;
	printf("Stack a:\n");
	print_stack(ps->stack_a);
	//swap(&(ps->stack_a), 'a');
	printf("Stack b:\n");
	print_stack(ps->stack_b);
	//swap(&(ps->stack_b), 'b');
	//insert_begin((ps->stack_b), (ps->stack_a));
	pa(&(ps));
	printf("Stack a:\n");
	print_stack(ps->stack_a);
	//print_stack(ps->stack_a);
	//insert_last(&(ps->stack_b), aux);
	//insert_last(&(ps->stack_b), aux);
	printf("Stack b:\n");
	print_stack(ps->stack_b);
	return (1);
}
