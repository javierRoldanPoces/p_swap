/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:09 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/22 18:39:18 by Jroldan-         ###   ########.fr       */
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

int	ft_calc_min_cost(t_nodo *lst)
{
	t_nodo	*aux;
	int		cost_min;
	int		pos_min;

	pos_min = 0;
	cost_min = 0;
	aux = (lst);
	while (aux)
	{
		if (aux->cost_total <= cost_min)
		{
			cost_min = aux->cost_total;
			pos_min = aux->pos;
		}
		aux = aux->next;
	}
	return (pos_min);
}

void	ft_sort(t_nodo **stack_a, t_nodo **stack_b)
{
	int		size_stack;
	int		i;
	t_nodo	*b;
	t_nodo	*aux;
	int		pos_min;

	size_stack = ft_size_lst(*stack_a);
	i = 0;
	pos_min = 0;
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
		//***
	b = *stack_b;
	while (b)
	{
		ft_target_pos(stack_a, stack_b);
		ft_calc_cost(stack_a, stack_b);
		//printf("último recorrido_00\n");
		printf("elemento arriba: %d\n", b->date);
		pos_min = ft_calc_min_cost(*stack_b);
		/* while (b->pos != pos_min) // posible correciond evolviendo el nodo para no perder la cabeza del auxiliar
		{
			printf("b->pos:%d - pos_min:%d\n", b->pos, pos_min);
			b = b->next;
			printf("último recorrido_01\n");
		} */
		if (b->cost_a > 0 && b->cost_b > 0) //ambos costes +
		{
			if (b->cost_a > b->cost_b)
			{
				i = -1;
				while (++i < b->cost_b)
					rr(stack_a, stack_b); //posible solucion reasignar  el aux tras cada movimiento
				i = -1;
				while (++i < (b->cost_a - b->cost_b))
					rotate(stack_a, 'a');
			}
			else if (b->cost_a < b->cost_b)
			{
				i = -1;
				while (++i < b->cost_a)
					rr(stack_a, stack_b);
				i = -1;
				while (++i < (b->cost_b - b->cost_a))
					rotate(stack_b, 'b');
			}
			else if (b->cost_a == b->cost_b)
			{
				i = -1;
				while (++i < b->cost_a)
					rr(stack_a, stack_b);
			}
		}
		else if (b->cost_a < 0 && b->cost_b < 0) //ambos costes -
		{
			if (ft_abs(b->cost_a) > ft_abs(b->cost_b))
			{
				i = -1;
				while (++i < ft_abs(b->cost_b))
					rrr(stack_a, stack_b);
				i = -1;
				while (++i < (ft_abs(b->cost_a) - ft_abs(b->cost_b)))
					reverse(stack_a, 'a');
			}
			else if (ft_abs(b->cost_a) < ft_abs(b->cost_b))
			{
				i = -1;
				while (++i < ft_abs(b->cost_a))
					rrr(stack_a, stack_b);
				i = -1;
				while (++i < (ft_abs(b->cost_b) - ft_abs(b->cost_a)))
					reverse(stack_b, 'b');
			}
			else if (b->cost_a == b->cost_b)
			{
				i = -1;
				while (++i < ft_abs(b->cost_a))
					rrr(stack_a, stack_b);
			}
		}
		else if ((b->cost_a > 0 && b->cost_b < 0)
			|| (b->cost_a < 0 && b->cost_b > 0))
		{
			if (b->cost_a < 0)
			{
				i = -1;
				while (++i < ft_abs(b->cost_a))
					reverse(stack_a, 'a');
			}
			else if (b->cost_a > 0)
			{
				i = -1;
				while (++i < b->cost_a)
					rotate(stack_a, 'a');
			}
			if (b->cost_b < 0)
			{
				i = -1;
				while (++i < ft_abs(b->cost_b))
					reverse(stack_b, 'b');
			}
			else if (b->cost_b > 0)
			{
				i = -1;
				while (++i < b->cost_b)
					rotate(stack_b, 'b');
			}
			pa(stack_b, stack_a);
		}
	}
	// calculo el de menor coste funcion: "t_nodo *ft_calc_min_cost(t_nodo *lst)""
	// con los costes del nodo con menor coste total hago las operaciones pertinentes
	// recalculo posiciones y target pos y vuelvo a calcular costes
	// repito todo lo anterior mientras el stack_b no este vacío
}
  //./push_swap 34 106 -45 -32 100 101 102 105 109 99 107 108 -40 -393718 -16005 -3841 -4486 -2940 -16424 10458 -525 -16238 -3719 -4507 3703 -12912 -16218 -4334 -15968 -21368 -4342 -16977 -5521 11568 -14713 246 6006 2869 15056 18057 6462 8890 14566 19847 -6675 -12836 14018 20516 15448 12778 -797 5660 -9650 14540 -16154 8708 17692 12095 11423 -14154 -17558 -2428 3185 -14704 11528 -16166 -10480 6386 12045 3013 1835 1415 -7739 -15876 -8989 -10898 -5825 -10188 -313 11590 12132 -17505 5266 19175 -17876 -20020 -15527 -21445 -7487 -14314 20053 -14818 -14997 6862 -1932 16984 -801 11583 2200 638 5423 -7287 20602 12671 20975 -13981 -19550 -10009 4262 2052 1764 19935 -173 -8588 14343 21211 -15997 4962 -9566 2366 2813 -19073 -19818 -19393 13799 -7951 15478 11615 18642 12900 -16628 20240 1251 20908 19378 -3758 -19721 15584 650 16816 -9168 15007 12733 19778 -14653 11753 9106 5081 16327 7911 -7971 -3961 -7177 -4099 -19563 16419 19346 17718 -9991 7592 -1459 -6199 -19829 19759 -1446 12933 13191 -16659 4482 -3917 6178 5733 3499 -9007 -15437 8729 -15104 -4311 287 -940 1561 19772 21262 -17902 -3826 -7196 18873 -8148 -10343 -16368 686 -5583 -12323 -14828 1680 -850 2049 6938 17068 -4834 11674 18343 4444 15530 15608 10070 -11413 1006 10177 1999 -1223 19058  -8895 