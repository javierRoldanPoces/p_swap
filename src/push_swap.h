/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:46:50 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/20 18:01:00 by Jroldan-         ###   ########.fr       */
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
	int			index;
	int			cost;
	struct nodo	*next;
	struct nodo	*prev;
}	t_nodo;

// typedef struct push_swap {
// 	int		size;
// 	t_nodo	*stack_a;
// 	t_nodo	*stack_b;
// }	t_push_swap;

//list functions
t_nodo		*init_list(void);
t_nodo		*create_nodo(int a);
void		insert_last(t_nodo **list, t_nodo *new_nodo);
t_nodo		*final(t_nodo *list);
void		print_stack(t_nodo *list);
int			ft_size_lst(t_nodo *lst);
//free
void		ft_free_lst(t_nodo *lst);
//parse
int			ft_check_sign(char *str);
int			ft_check_digit(char *str);
int			repeat_value(int a, t_nodo *lst);
int			ft_stack_sorted(t_nodo *lst);
long		ft_atoi_long(const char *str);
int			ft_range_int(long a, long b);
void		ft_asign_index(t_nodo **lst, int size);
//movements
void		swap(t_nodo **a, char c);
void		ss(t_nodo **a, t_nodo **b);
void		pa(t_nodo **stck_b, t_nodo **stck_a);
void		pb(t_nodo **origin, t_nodo **dest);
void		rotate(t_nodo **stack, char c);
void		rr(t_nodo **stack_a, t_nodo **stack_b);
void		reverse(t_nodo **stack, char c);
//push_swap sort
void		ft_sort_three(t_nodo **lst);

#endif