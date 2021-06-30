/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:32:43 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/30 14:20:16 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	int			save;
	int			save2;
	int			save3;
	t_stack		*stk;

	stk = *stack;
	while (stk->next)
		stk = stk->next;
	save = stk->data;
	stk = *stack;
	save2 = stk->data; 
	while (stk->next)
	{
		save3 = stk->next->data;
		stk->next->data = save2;
		save2 = save3;
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
