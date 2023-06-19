/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:44:03 by javier            #+#    #+#             */
/*   Updated: 2023/06/19 17:57:53 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate(t_nodo **stack, char c)
{
	t_nodo	*tmp;
	t_nodo	*fin;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	fin = final(*stack);
	fin->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = fin;
	(*stack) = tmp;
	(*stack)->prev = NULL;
	if (c == 'a' || c == 'b')
		printf ("r%c\n", c);
}

void	rr(t_nodo **stack_a, t_nodo **stack_b)
{
	rotate(stack_a, 's');
	rotate(stack_b, 's');
	printf("ss\n");
}
