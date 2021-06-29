/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:56:28 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 17:18:13 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*save;

	if (!*stack_b)
		return;
	save = *stack_b;
	*stack_b = (*stack_b)->next;
	save->next = (*stack_a);
	*stack_a = save;
}

void		push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*save;

	if (!*stack_a)
		return;
	save = *stack_a;
	*stack_a = (*stack_a)->next;
	save->next = (*stack_b);
	*stack_b = save;
}
