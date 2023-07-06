/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:21:09 by javier            #+#    #+#             */
/*   Updated: 2023/07/06 22:08:06 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void	free_memory(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_size_lst(t_nodo *lst)
{
	int		count;
	t_nodo	*aux;

	aux = lst;
	count = 0;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	return (count);
}

void	error(t_nodo *stack_a)
{
	ft_free_lst(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
