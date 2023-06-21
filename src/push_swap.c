/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:09 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/21 20:36:09 by Jroldan-         ###   ########.fr       */
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
	ft_position(lst);
}

void	ft_position(t_nodo **lst)
{
	int		i;
	t_nodo	*aux;

	if (!(*lst))
		return ;
	i = 0;
	aux = (*lst);
	while (aux)
	{
		aux->pos = i;
		i++;
		aux = aux->next;
	}
}

// static int	index_min(t_nodo *stack_a)
// {
// 	int		i;
// 	t_nodo	*aux;

// 	i = INT_MAX;
// 	aux = stack_a;
// 	while (aux)
// 	{
// 		if (aux->index < i)
// 			i = aux->index;
// 		aux = aux->next;
// 	}
// 	return (i);
// }
int	index_min(t_nodo **stack_a)
{
	t_nodo	*aux;
	int		i;

	aux = (*stack_a);
	i = INT_MAX;
	while (aux)
	{
		if (aux->index < i)
			i = aux->index;
		aux = aux->next;
	}
	aux = (*stack_a);
	while (aux->index != i)
		aux = aux->next;
	return (aux->pos);
}
void	ft_sort(t_nodo **stack_a, t_nodo **stack_b)
{
	int	size_stack;
	int	i;

	size_stack = ft_size_lst(*stack_a);
	i = 0;
	while (i < size_stack)
	{
		if ((*stack_a)->index < size_stack / 2 + 1)
			pb(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
		i++;
	}
	while (ft_size_lst(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (ft_size_lst(*stack_a) == 3)
		ft_sort_three(stack_a);
}

void	ft_target_pos(t_nodo **stack_a, t_nodo **stack_b)
{
	t_nodo	*a;
	t_nodo	*b;
	int		aux;

	a = (*stack_a);
	b = (*stack_b);
	while (b)
	{
		aux = INT_MAX;
		b->target_pos = INT_MAX;
		while (a)
		{
			if (a->index > b->index && aux > a->index)
			{
				aux = a->index;
				b->target_pos = a->pos;
			}
			if (b->target_pos == INT_MAX)
				b->target_pos = index_min(&a);
			a = a->next;
		}
		b = b->next;
		a = (*stack_a);
	}
}



// void	ft_target_pos(t_nodo **stack_a, t_nodo **stack_b)
// {
// 	t_nodo	*aux_a;
// 	t_nodo	*aux_b;
// 	//int		min_index;
// 	int		aux;
// 	//int		aux_max;

// 	aux_a = (*stack_a);
// 	aux_b = (*stack_b);
// 	aux = INT_MIN;
// 	aux_max = INT_MAX;
// 	min_index = index_min(*stack_a);
// 	printf("el index minimo de stack a es : %d", min_index);
// 	while (aux_b)
// 	{
// 		aux_a = (*stack_a);
// 		aux = INT_MIN;
// 		aux_max = INT_MAX;
// 		while (aux_a)
// 		{
// 			if (aux_b->index < min_index)
// 			{
// 				if (aux_b->index - aux_a->index > aux) //
// 				{
// 					aux = aux_b->index - aux_a->index;
// 					aux_b->target_pos = aux_a->pos;
// 				}			
// 			}
// 			else
// 			{
// 				if (aux_b->index - aux_a->index < aux_max)
// 				{
// 					aux_max = aux_b->index - aux_a->index;
// 					aux_b->target_pos = aux_a->pos;
// 				}
// 			}
// 			aux_a = aux_a->next;
// 		}
// 		aux_b = aux_b->next;
// 	}
// }
