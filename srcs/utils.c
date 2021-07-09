/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:48:50 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/08 15:14:22 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	int		l;

	l = 0;
	while (stack)
	{
		l++;
		stack = stack->next;
	}
	return (l);
}

int	get_pivot_element(t_stack *stack, int pivot_pos)
{
	int		ret;
	int		l;

	l = stacksize(stack);
	l = l - pivot_pos;
	while (--l > 0)
		stack = stack->next;
	ret = stack->data;
	return (ret);
}

void	put_pivot_in_place(t_stack **stack_a, int pivot)
{
	int			l;
	int			pos;
	t_stack		*stk;

	pos = 1;
	l = stacksize(*stack_a);
	stk = *stack_a;
	while (stk && stk->data != pivot)
	{
		stk = stk->next;
		pos++;
	}
	if (pos <= l / 2)
		while (pos-- > 1)
			rotate_a(stack_a);
	else
		while (pos++ <= l)
			rev_rotate_a(stack_a);
}
