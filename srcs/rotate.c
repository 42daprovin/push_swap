/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:00:42 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 18:28:29 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	int			save;
	t_stack		*stk;

	stk = *stack;
	save = stk->data;
	while (stk->next)
	{
		stk->data = stk->next->data;
		stk = stk->next;
	}
	stk->data = save;
}

void		rotate_a(t_stack **stack_a)
{
	int			l;

	l = stacksize(*stack_a);
	if  (l >= 2)
		rotate_stack(stack_a);
	ft_printf("ra\n");
}

void		rotate_b(t_stack **stack_b)
{
	int			l;

	l = stacksize(*stack_b);
	if  (l >= 2)
		rotate_stack(stack_b);
	ft_printf("rb\n");
}


void		rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	int			save;
	t_stack		*stk;
	int			l;

	l = stacksize(*stack_a);
	if (l >= 2)
		rotate_stack(stack_a);
	l = stacksize(*stack_b);
	if (l >= 2)
		rotate_stack(stack_b);
	ft_printf("rr\n");
}
