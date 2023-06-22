/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:45:53 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/22 16:18:18 by Jroldan-         ###   ########.fr       */
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
	aux->index = 0;
	aux->cost_a = -2;
	aux->cost_b = -2;
	aux->cost_total= -1;
	aux->pos = -1;
	aux->target_pos = -1;
	aux->next = NULL;
	aux->prev = NULL;
	return (aux);
}

void	insert_last(t_nodo **list, t_nodo *new_nodo)
{
	t_nodo	*aux;

	if (*list)
	{
		aux = final(*list);
		aux -> next = new_nodo;
		new_nodo -> prev = aux;
		new_nodo -> next = NULL;
	}
	else
		*list = new_nodo;
}

t_nodo	*final(t_nodo *list)
{
	t_nodo	*aux;

	aux = list;
	if (!list)
		return (NULL);
	while (aux && aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	print_stack(t_nodo *list)
{
	t_nodo	*aux;

	aux = list;
	if (list == NULL)
		printf("lista vacia \n");
	while (aux != NULL)
	{
		printf("*******************\n");
		printf("dato-> %d \n", aux->date);
		printf("index-> %d \n", aux->index);
		printf("position in stack-> %d \n", aux->pos);
		// printf("Actual-> %p \n", aux);
		// printf("Next-> %p \n", aux->next);
		// printf("Prev-> %p \n", aux->prev);
		printf("target_pos-> %d \n", aux->target_pos);
		printf("cost_b %d \n", aux->cost_b);
		printf("cost_a-> %d \n", aux->cost_a);
		printf("cost_total-> %d \n", aux->cost_total);
		aux = aux -> next;
	}	
}
