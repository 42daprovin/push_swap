/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:04:13 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 18:26:20 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int					data;
	struct s_stack		*next;
}				t_stack;

void			create_a(char **av, t_stack **stack_a);

void			swap_a(t_stack **stack_a);

void			swap_b(t_stack **stack_b);

void			swap_a_b(t_stack **stack_a, t_stack **stack_b);

void			push_a(t_stack **stack_a, t_stack **stack_b);

void			push_b(t_stack **stack_a, t_stack **stack_b);

void			print_stack(t_stack *stack);

int				stacksize(t_stack *stack);

void			rotate_a(t_stack **stack_a);

void			rotate_b(t_stack **stack_b);

static void		rotate_stack(t_stack **stack);

#endif
