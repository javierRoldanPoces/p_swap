/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:32:07 by javier            #+#    #+#             */
/*   Updated: 2023/06/19 18:06:07 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reverse(t_nodo **stack, char c)
{
	t_nodo	*tmp;
	t_nodo	*fin;

	if (!(*stack) || !(*stack)->next)
		return ;
	fin = final(*stack);
	tmp = fin->prev;
	(*stack)->prev = fin;
	fin->next = (*stack);
	fin->prev = NULL;
	tmp->next = NULL;
	(*stack) = fin;
	if (c == 'a' || c == 'b')
		printf ("rr%c\n", c);
}

void	rrr(t_nodo **stack_a, t_nodo **stack_b)
{
	reverse(stack_a, 'r');
	reverse(stack_b, 'r');
	printf("rrr\n");
}
