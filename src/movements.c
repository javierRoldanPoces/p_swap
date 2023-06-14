/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:03:21 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/14 20:26:57 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_nodo **a, char c)
{
	t_nodo	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*a != NULL && (*a)->next != NULL)
	{	
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	if (c == 's')
		printf("%c%c\n", c, c);
	else
		printf("s%c\n", c);
	//free(tmp);
}

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
	//free(tmp_a);
	if (*b == NULL || (*b)->next == NULL)
		return ;
	if (*b != NULL && (*b)->next != NULL)
	{	
		tmp_b = (*b)->next;
		(*b)->next = tmp_b->next;
		tmp_b->next = (*b);
		(*b) = tmp_b;
	}
	//free (tmp_b);
}

void	pa(t_push_swap **ps)
{
	//t_nodo	*tmp;

	if (((*ps)->stack_a) == NULL)
		return ;
	else
	{
		//tmp = (*ps)->stack_b;
		//tmp->date = 3003;
		insert_begin((*ps)->stack_b, (*ps)->stack_a);
		ft_pop(&(*ps)->stack_b);		
		//(ps)->stack_->next = ((ps)->stack_a)->next->next;
		//((*ps)->stack_a)->prev = NULL;
	}
}
