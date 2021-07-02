/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:20:57 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/02 17:38:59 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* void	swap_algo(t_stack **stack_a, t_stack **stack_b) */
/* { */
/* 	while (*stack_a) */
/* 	{ */
/* 		while (*stack_b && (*stack_b)->data > (*stack_a)->data) */
/* 		{ */
/* 			push_a(stack_a, stack_b); */
/* 			swap_a(stack_a); */
/* 		} */
/* 		push_b(stack_a, stack_b); */
/* 	} */
/* 	while (*stack_b) */
/* 		push_a(stack_a, stack_b); */
/* } */ 

int			find_smallest(t_stack *stk)
{
	int			sml;

	sml = stk->data;
	while (stk)
	{
		if (stk->data < sml)
			sml = stk->data;
		stk = stk->next;
	}
	return (sml);
}

void		swap_algo(t_stack **stack_a, t_stack **stack_b)
{
	int			smallest;
	
	while (*stack_a)
	{
		smallest = find_smallest(*stack_a);
		put_pivot_in_place(stack_a, smallest);
		push_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

/* void		improved_insertion(t_stack **stack_a, t_stack **stack_b) */
/* { */

/* } */
