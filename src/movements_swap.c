/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:03:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/30 18:29:11 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_nodo **a, char c)
{
	int	swap;
	int	swap_index;

	swap = (*a)->date;
	swap_index = (*a)->index;
	(*a)->date = (*a)->next->date;
	(*a)->index = (*a)->next->index;
	(*a)->next->date = swap;
	(*a)->next->index = swap_index;
	ft_position(a);
	if (c == 'a' || c == 'b')
		ft_printf ("s%c\n", c);
}

void	ss(t_nodo **a, t_nodo **b)
{
	int	swap;
	int	swap_index;

	swap = (*a)->date;
	swap_index = (*a)->index;
	(*a)->date = (*a)->next->date;
	(*a)->index = (*a)->next->index;
	(*a)->next->date = swap;
	(*a)->next->index = swap_index;
	ft_position(a);
	swap = (*b)->date;
	swap_index = (*b)->index;
	(*b)->date = (*b)->next->date;
	(*b)->index = (*b)->next->index;
	(*b)->next->date = swap;
	(*b)->next->index = swap_index;
	ft_position(b);
	ft_printf("ss\n");
}
