/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:46:50 by Jroldan-          #+#    #+#             */
/*   Updated: 2023/06/07 19:02:35 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

t_nodo		*init_list(void);
t_nodo		*create_nodo(int a);
t_nodo		*insert_begin(t_nodo *list, t_nodo *new);
void		print_stack(t_nodo *list);
t_nodo		*delete_nodo(t_nodo *list);
t_push_swap	*init(void);
t_push_swap	*init_push_swap(void);
#endif