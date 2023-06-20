/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:38:48 by javier            #+#    #+#             */
/*   Updated: 2023/06/20 20:03:52 by Jroldan-         ###   ########.fr       */
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
	ft_position(stck_a);
	ft_position(stck_b);
	printf("pb\n");
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
	ft_position(stck_b);
	ft_position(stck_a);
	printf("pa\n");
}
