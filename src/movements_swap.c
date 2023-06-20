/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:03:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/20 20:11:40 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_nodo **a, char c)
{
	// t_nodo	*tmp;

	// if (*a == NULL || (*a)->next == NULL)
	// 	return ;
	// if (*a != NULL && (*a)->next != NULL)
	// {	
	// 	tmp = (*a)->next;
	// 	(*a)->next = tmp->next;
	// 	tmp->next = (*a);
	// 	(*a) = tmp;
	// }
	int	swap;
	int	swap_index;

	swap = (*a)->date;
	swap_index = (*a)->index;
	(*a)->date = (*a)->next->date;
	(*a)->index = (*a)->next->index;
	(*a)->next->date = swap;
	(*a)->next->index = swap_index;
	if (c == 'a' || c == 'b')
		printf ("s%c\n", c);
}

//arreglar ss
void	ss(t_nodo **a, t_nodo **b)
{
	t_nodo	*tmp_a;
	t_nodo	*tmp_b;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*a != NULL && (*a)->next != NULL)
	{	
		tmp_a = (*a)->next;
		(*a)->next = tmp_a->next;
		tmp_a->next = (*a);
		(*a) = tmp_a;
	}
	if (*b == NULL || (*b)->next == NULL)
		return ;
	if (*b != NULL && (*b)->next != NULL)
	{	
		tmp_b = (*b)->next;
		(*b)->next = tmp_b->next;
		tmp_b->next = (*b);
		(*b) = tmp_b;
	}
	printf("ss\n");
}
