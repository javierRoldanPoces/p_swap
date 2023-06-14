/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:21:28 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/13 19:30:10 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*init(void)
{
	return (NULL);
}

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	ps->size = 0;
	ps->stack_a = init_list();
	ps->stack_b = init_list();
	return (ps);
}
