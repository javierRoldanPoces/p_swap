/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:46:50 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/14 20:03:26 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct nodo {
	int			date;
	//int			index;
	struct nodo	*next;
	struct nodo	*prev;
}	t_nodo;

typedef struct push_swap {
	int		size;
	t_nodo	*stack_a;
	t_nodo	*stack_b;
}	t_push_swap;

//list functions
t_nodo		*init_list(void);
t_nodo		*create_nodo(int a);
t_nodo		*insert_begin(t_nodo *list, t_nodo *new);
void		insert_last(t_nodo **list, t_nodo *new_nodo);
t_nodo		*final(t_nodo *list);
void		print_stack(t_nodo *list);
t_nodo		*delete_nodo(t_nodo *list);
t_push_swap	*init(void);
void		ft_pop(t_nodo **lst);
//struct push_swap
t_push_swap	*init_push_swap(void);
//parse
int			ft_check_sign(char *str);
int			ft_check_digit(char *str);
int			repeat_value(int a, t_nodo *lst);
int			ft_stack_sorted(t_nodo *lst);
long		ft_atoi_long(const char *str);
int			ft_range_int(long a, long b);
//movements
void		swap(t_nodo **a, char c);
void		ss(t_nodo **a, t_nodo **b);
void		pa(t_push_swap **ps);
//free
void		ft_free_lst(t_nodo *lst);
#endif