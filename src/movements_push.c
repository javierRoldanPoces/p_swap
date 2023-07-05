/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:38:48 by javier            #+#    #+#             */
/*   Updated: 2023/06/30 13:00:10 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_nodo **stack_a, t_nodo **stack_b)
{
	t_nodo	*temp;
	int		flag;

	flag = 0;
	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
	{
		temp = NULL;
		flag = 1;
	}
	else
		temp = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
		(*stack_b)->prev = (*stack_a);
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	if (flag == 0)
		temp->prev = NULL;
	*stack_a = temp;
	ft_position(stack_a);
	ft_position(stack_b);
	ft_printf("pb\n");
}

void	pa(t_nodo **stack_a, t_nodo **stack_b)
{
	t_nodo	*temp;
	int		flag;

	flag = 0;
	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == NULL)
	{
		temp = NULL;
		flag = 1;
	}
	else
		temp = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = (*stack_b);
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	if (flag == 0)
		temp->prev = NULL;
	*stack_b = temp;
	ft_position(stack_b);
	ft_position(stack_a);
	ft_printf("pa\n");
}
