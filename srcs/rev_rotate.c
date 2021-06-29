/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:43 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 18:43:33 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	int			save;
	t_stack		*stk;

	stk = *stack;
	while (stk->next)
		stk = stk->next;
	save = stk->data;
	stk = *stack;
	while (stk->next)
	{
		stk->next->data = stk->data;
		stk = stk->next;
	}
	(*stack)->data = save;
}

void		rev_rotate_a(t_stack **stack_a)
{
	int			l;

	l = stacksize(*stack_a);
	if (l >= 2)
		rev_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void		rev_rotate_b(t_stack **stack_b)
{
	int			l;

	l = stacksize(*stack_b);
	if (l >= 2)
		rev_rotate_stack(stack_b);
	ft_printf("rrb\n");
}

void		rev_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	int			l;

	l = stacksize(*stack_a);
	if (l >= 2)
		rev_rotate_stack(stack_a);
	l = stacksize(*stack_b);
	if (l >= 2)
		rev_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
