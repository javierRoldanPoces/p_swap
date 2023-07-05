/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:37:19 by javier            #+#    #+#             */
/*   Updated: 2023/07/05 19:55:53 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = a * -1;
	return (a);
}

t_nodo	*ft_calc_min_cost(t_nodo *lst)
{
	t_nodo	*aux;
	t_nodo	*cost_min;

	aux = (lst);
	cost_min = aux;
	while (aux)
	{
		if (aux->cost_total < cost_min->cost_total)
			cost_min = aux;
		else
			aux = aux->next;
	}
	return (cost_min);
}
