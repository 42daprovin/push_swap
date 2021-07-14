/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:02:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/14 17:33:02 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(stack_a);
	return ;
}

void	sort_3(t_stack **stack_a)
{
	t_stack		*stk;

	stk = *stack_a;
	if (stk->data > stk->next->data && stk->data > stk->next->next->data)
	{
		if (stk->next->data < stk->next->next->data)
			rotate_a(stack_a);
		else
		{
			swap_a(stack_a);
			rev_rotate_a(stack_a);
		}
	}
	else if (stk->data < stk->next->data && stk->data < stk->next->next->data)
	{
		if (stk->next->data < stk->next->next->data)
			return ;
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stk->next->data > stk->next->next->data)
		rev_rotate_a(stack_a);
	else
		swap_a(stack_a);
}

void	insert_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*stk;
	int			pivot;
	int			in_element;

	stk = *stack_a;
	in_element = (*stack_b)->data;
	pivot = in_element;
	while (stk)
	{
		if (pivot == in_element && stk->data > in_element)
			pivot = stk->data;
		if (stk->data < pivot && stk->data > in_element)
			pivot = stk->data;
		stk = stk->next;
	}
	if (pivot != in_element)
		put_pivot_in_place(stack_a, pivot);
	push_a(stack_a, stack_b);
	put_beg_in_place(stack_a);
}

void	sort_using_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*stk;
	int			beg;

	while (stacksize(*stack_a) > 3)
		push_b(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
		insert_in_a(stack_a, stack_b);
	stk = *stack_a;
	beg = stk->data;
	while (stk)
	{
		if (stk->data < beg)
			beg = stk->data;
		stk = stk->next;
	}
	put_pivot_in_place(stack_a, beg);
}

void	small_algorithm(t_stack **stack_a, t_stack **stack_b, int l)
{
	if (l == 1)
		return ;
	if (l == 2)
		sort_2(stack_a);
	if (l == 3)
		sort_3(stack_a);
	if (l > 3)
		sort_using_3(stack_a, stack_b);
}
