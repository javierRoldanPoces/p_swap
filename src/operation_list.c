/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:45:53 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/07 18:32:38 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodo	*init_list(void)
{
	return (NULL);
}

t_nodo	*create_nodo(int a)
{
	t_nodo	*aux;

	aux = (t_nodo *)malloc(sizeof(t_nodo));
	aux->date = a;
	aux->next = NULL;
	aux->prev = NULL;
	return (aux);
}

t_nodo	*insert_begin(t_nodo *list, t_nodo *new_nodo)
{
	new_nodo->next = list;
	if (list != NULL)
		list->prev = new_nodo;
	return (new_nodo);
}

void	print_stack(t_nodo *list)
{
	t_nodo	*aux;

	aux = list;
	while (aux != NULL)
	{
		printf("%d \n", aux->date);
		aux = aux-> next;
	}
}

//liberar