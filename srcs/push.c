/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:56:28 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/05 20:15:05 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*save;

	if (*stack_b)
	{
		save = *stack_b;
		*stack_b = (*stack_b)->next;
		save->next = (*stack_a);
		*stack_a = save;
	}
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*save;

	if (*stack_a)
	{
		save = *stack_a;
		*stack_a = (*stack_a)->next;
		save->next = (*stack_b);
		*stack_b = save;
	}
	ft_printf("pb\n");
}
