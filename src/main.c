/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:28:55 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/07 19:07:39 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_nodo		*aux;
	t_push_swap	*ps;
	char		**arg;

	ps = init();
	ps = init_push_swap();
	i = 0;

	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			aux = create_nodo(ft_atoi(argv[i]));
			ps->stack_a = insert_begin(ps->stack_a, aux);
			i++;
		}
	}
	else if (argc == 2)
	{
		i = 0;
		arg = ft_split(argv[1], ' ');
		while (arg[i] != NULL)
		{
			aux = create_nodo(ft_atoi(arg[i]));
			ps->stack_a = insert_begin(ps->stack_a, aux);
			i++;
		}
	}
	ps->size = i;
	print_stack(ps->stack_a);
	printf("%d", ps->size);
	return (0);
}
