/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:06 by javier            #+#    #+#             */
/*   Updated: 2023/07/06 18:32:01 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ambos costos son positivos
void	cost_ab_pos(t_nodo **stack_a, t_nodo **stack_b, t_nodo *lower)
{
	while (lower->cost_b > 0 && lower->cost_a > 0)
	{
		rr(stack_a, stack_b);
		lower->cost_b--;
		lower->cost_a--;
	}
	if (lower->cost_b >= 0 || lower->cost_a >= 0)
	{
		while (lower->cost_b == 0 && lower->cost_a > 0)
		{
			rotate(stack_a, 'a');
			lower->cost_a--;
		}
		while (lower->cost_b > 0)
		{
			rotate(stack_b, 'b');
			lower->cost_b--;
		}
	}
	pa(stack_a, stack_b);
}

//ambos costes son negativos
void	cost_ab_neg(t_nodo **stack_a, t_nodo **stack_b, t_nodo *lower)
{
	while (lower->cost_b < 0 && lower->cost_a < 0)
	{
		rrr(stack_a, stack_b);
		lower->cost_b++;
		lower->cost_a++;
	}
	if (lower->cost_b < 0 || lower->cost_a < 0)
	{
		while (lower->cost_b < 0)
		{
			reverse(stack_b, 'b');
			lower->cost_b++;
		}
		while (lower->cost_a < 0)
		{
			reverse(stack_a, 'a');
			lower->cost_a++;
		}
	}
	pa(stack_a, stack_b);
}

//coste de a negativo , coste de b positivo
void	cost_a_neg_b_pos(t_nodo **stack_a, t_nodo **stack_b, t_nodo *lower)
{
	if (lower->cost_b >= 0 || lower->cost_a < 0)
	{
		while (lower->cost_b > 0)
		{
			rotate(stack_b, 'b');
			lower->cost_b--;
		}
		while (lower->cost_a < 0)
		{
			reverse(stack_a, 'a');
			lower->cost_a++;
		}
	}
	pa(stack_a, stack_b);
}

//coste de a positivo y coste de b negativo
void	cost_a_pos_b_neg(t_nodo **stack_a, t_nodo **stack_b, t_nodo *lower)
{
	if (lower->cost_b < 0 || lower->cost_a >= 0)
	{
		while (lower->cost_b < 0)
		{
			reverse(stack_b, 'b');
			lower->cost_b++;
		}
		while (lower->cost_a > 0)
		{
			rotate(stack_a, 'a');
			lower->cost_a--;
		}
	}
	pa(stack_a, stack_b);
}

void	finishing_move(t_nodo **stack_a)
{
	int		len;
	t_nodo	*a;
	int		i;

	i = -1;
	a = *stack_a;
	len = ft_size_lst(a);
	while (a && a->index != 1)
		a = a->next;
	i = a->pos + 1;
	if (a->pos > len / 2)
	{
		while (a->pos < len)
		{
			reverse(stack_a, 'a');
			len--;
		}
	}	
	else if (a->pos < len / 2 + 1)
	{
		while (--i > 0)
			rotate(stack_a, 'a');
	}
	ft_position(stack_a);
}
