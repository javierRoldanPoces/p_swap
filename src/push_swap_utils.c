/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:07:38 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/22 17:51:22 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = a * -1;
	return (a);
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

void	ft_calc_cost(t_nodo **stack_a, t_nodo **stack_b)
{
	int		size_a;
	int		size_b;
	t_nodo	*aux;

	aux = (*stack_b);
	size_a = ft_size_lst(*stack_a);
	size_b = ft_size_lst(*stack_b);
	// 1º caclculo coste de B
	//printf("el size_b es = %d\n", size_b);
	//printf("el size_a es = %d\n", size_a);
	while (aux)
	{
		//printf("Entra en calculo de costes\n");
		if ((aux)-> pos < size_b / 2 + 1)
			(aux)->cost_b = ((aux)->pos);
		else if ((aux)-> pos >= size_b / 2 + 1)
			(aux)->cost_b = (size_b - (aux)->pos) * -1;
		// 2º Calculo de coste de A (basado en target_pos)
		if ((aux)->target_pos < size_a / 2 + 1)
			(aux)->cost_a = (aux)->target_pos;
		else if ((aux)-> target_pos >= size_a / 2 + 1)
			(aux)->cost_a = (size_a - (aux)->target_pos) * -1;
		aux = aux->next;
	}
	ft_total_cost(stack_b);
}

void	ft_total_cost(t_nodo **stack_b)
{
	t_nodo	*aux;

	aux = (*stack_b);

	while (aux)
	{
		aux->cost_total = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
		aux = aux->next;
	}
}
