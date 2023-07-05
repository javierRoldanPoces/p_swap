/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:25:39 by javier            #+#    #+#             */
/*   Updated: 2023/06/29 11:40:53 by javier           ###   ########.fr       */
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
	return (1);
}

static	int	ft_look_min(t_nodo *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->index == 0)
			i = lst->date;
		lst = lst->next;
	}
	return (i);
}

static	int	ft_asign_min(t_nodo *lst, int min)
{
	while (lst != NULL)
	{
		if (lst->date < min && lst->index == 0)
			min = lst->date;
		lst = lst->next;
	}
	return (min);
}

void	ft_asign_index(t_nodo **lst, int size)
{
	t_nodo	*aux;
	int		min;
	int		i;

	if (*lst == NULL)
		ft_printf("Error\n");
	aux = *lst;
	i = 0;
	while (++i <= size)
	{
		min = ft_look_min(aux);
		min = ft_asign_min(aux, min);
		while (aux != NULL)
		{
			if (aux->date == min)
				aux->index = i;
			aux = aux->next;
		}
		aux = *lst;
	}
}
