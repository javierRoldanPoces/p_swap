/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:09 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/07/05 19:55:33 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_nodo **stack_a)
{
	t_nodo	*aux;

	aux = (*stack_a)->next;
	if ((*stack_a)->date > aux->date)
		rotate(stack_a, 'a');
}

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

static void	movements_costs(t_nodo **stack_a, t_nodo **stack_b, t_nodo *lower)
{
	recalculate(stack_a, stack_b);
	lower = ft_calc_min_cost(*stack_b);
	if (lower->cost_b >= 0 && lower->cost_a >= 0)
		cost_ab_pos(stack_a, stack_b, lower);
	else if (lower->cost_b < 0 && lower->cost_a < 0)
		cost_ab_neg(stack_a, stack_b, lower);
	else if (lower->cost_b >= 0 && lower->cost_a < 0)
		cost_a_neg_b_pos(stack_a, stack_b, lower);
	else if (lower->cost_b < 0 && lower->cost_a >= 0)
		cost_a_pos_b_neg(stack_a, stack_b, lower);
}

void	ft_sort(t_nodo **stack_a, t_nodo **stack_b)
{
	int		size_stack;
	int		i;
	t_nodo	*lower;

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
	lower = *stack_b;
	while ((*stack_b))
		movements_costs(stack_a, stack_b, lower);
	ft_position(stack_a);
	finishing_move(stack_a);
}
