/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:20:24 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/19 17:26:08 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *str)
{
	long	i;
	long	res;
	long	sig;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-')
		sig *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sig);
}

int	ft_range_int(long a, long b)
{
	if (a == b)
		return (1);
	else
		return (printf("error: out of range"), 0);
}

int	ft_check_sign(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (printf("error signos\n"), 0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (printf("error signos\n"), 0);
		i++;
	}
	return (1);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{
			return (printf("No digit\n"), 0);
		}
	}
	return (1);
}

int	repeat_value(int a, t_nodo *lst)
{
	t_nodo	*aux;

	aux = lst;
	if (lst == NULL)
		return (1);
	while (aux != NULL)
	{
		if (a == aux->date)
			return (0);
		aux = aux->next;
	}
	return (1);
}
