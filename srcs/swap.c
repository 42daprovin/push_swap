/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:23:28 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 17:58:57 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		swap_a(t_stack **stack_a)
{
	int		save;
	int		l;

	l = stacksize(*stack_a);
	if (l < 2)
	{
		ft_printf("sa\n");
		return;
	}
	save = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = save;
	ft_printf("sa\n");
}

void		swap_b(t_stack **stack_b)
{
	int		save;
	int		l;

	l = stacksize(*stack_b);
	if (l < 2)
	{
		ft_printf("sb\n");
		return;
	}
	save = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = save;
	ft_printf("sb\n");
}

void		swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	int save;
	int	l;

	l = stacksize(*stack_a);
	if (l >= 2)
	{
		save = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = save;
	}
	l = stacksize(*stack_b);
	if (l >= 2)
	{
		save = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = save;
	}
	ft_printf("ss\n");
}
