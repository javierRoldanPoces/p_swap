/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:38:48 by javier            #+#    #+#             */
/*   Updated: 2023/06/19 16:39:28 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_nodo **stck_a, t_nodo **stck_b)
{
	t_nodo	*temp;

	if (*stck_a == NULL)
		return ;
	temp = (*stck_a)->next;
	if (*stck_a)
		(*stck_a)->prev = NULL;
	if (*stck_b)
		(*stck_b)->prev = (*stck_a);
	(*stck_a)->next = *stck_b;
	*stck_b = *stck_a;
	temp->prev = NULL;
	*stck_a = temp;
}

void	pa(t_nodo **stck_b, t_nodo **stck_a)
{
	t_nodo	*temp;

	if (*stck_b == NULL)
		return ;
	temp = (*stck_b)->next;
	if (*stck_b)
		(*stck_b)->prev = NULL;
	if (*stck_a)
		(*stck_a)->prev = (*stck_b);
	(*stck_b)->next = *stck_a;
	*stck_a = *stck_b;
	temp->prev = NULL;
	*stck_b = temp;
}