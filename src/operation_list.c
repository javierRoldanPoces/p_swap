/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:45:53 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/14 20:24:50 by Jroldan-         ###   ########.fr       */
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
	return (list);
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
		printf("%d \n", aux->date);
		aux = aux -> next;
	}	
}

// void	ft_free_nodo(t_nodo **lst)
// {
		
// }

void	ft_pop(t_nodo **lst)
{
	(*lst) = (*lst)->next;
	(*lst)->prev = NULL;
}

void	ft_free_lst(t_nodo *lst)
{
	t_nodo	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
