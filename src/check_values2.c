/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:39 by javier            #+#    #+#             */
/*   Updated: 2023/06/19 17:26:14 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_nodo *lst)
{
	t_nodo	*aux;

	aux = lst;
	if (lst == NULL)
		return (1);
	while (aux->next != NULL)
	{
		if (aux->date < aux->next->date)
			aux = aux->next;
		else
			return (0);
	}
	printf("ordenado\n");
	return (1);
}