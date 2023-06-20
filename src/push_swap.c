/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:09 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/20 18:40:16 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_nodo **lst)
{
	t_nodo	*aux;

	aux = (*lst)->next;
	while (!((*lst)->index < aux->index) || !((*lst)->index < aux->next->index) 
		|| !(aux->index < aux->next->index))
	{
		if ((*lst)->index > aux->index && (*lst)->index > aux->next->index)
			rotate(lst, 'a');
		else if (aux->index > (*lst)->index && aux->index > aux->next->index)
			reverse(lst, 'a');
		else if ((*lst)->index > aux->index)
			swap(lst, 'a');
		aux = (*lst)->next;
	}
}
