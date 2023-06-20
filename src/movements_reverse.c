/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:32:07 by javier            #+#    #+#             */
/*   Updated: 2023/06/20 20:04:46 by Jroldan-         ###   ########.fr       */
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
	ft_position(stack);
	if (c == 'a' || c == 'b')
		printf ("rr%c\n", c);
}

void	rrr(t_nodo **stack_a, t_nodo **stack_b)
{
	reverse(stack_a, 'r');
	reverse(stack_b, 'r');
	printf("rrr\n");
}
