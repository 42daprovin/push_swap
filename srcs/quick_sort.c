/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:27:36 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/30 19:22:50 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		put_pivot_in_place(t_stack **stack_a, int pivot)
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

t_stack		*mv_to_b(t_stack **stack_a, t_stack **stack_b, int *position, int *push_counter)	
{
	t_stack		*ret;
	int			j;

	j = 0;
	while (j < *position)
	{
		rotate_a(stack_a);
		j++;
	}
	push_b(stack_a, stack_b);
	*push_counter = *push_counter + 1;
	ret = *stack_a;
	*position = 0;
	return (ret);	
}

void		mv_to_a(t_stack **stack_a, t_stack **stack_b, int push_counter)
{
	int		i;

	i = 0;
	if (push_counter == 0)
		push_counter = stacksize(*stack_b);
	while (i < push_counter)
	{
		push_a(stack_a, stack_b);
		i++;
	}
	
}

int			back_sorted(t_stack *stack_a, t_stack *stack_b, int *pivot_pos)
{
	t_stack		*stk;
	
	stk = stack_a;	
	while (stk->next)
	{
		if (stk->data > stk->next->data)
			return (1);
		stk = stk->next;
	}
	if (!stack_b)
		return (3);
	*pivot_pos = stacksize(stack_a);
	return (2);
}

void		quicksort(t_stack **stack_a, t_stack **stack_b, int pivot_pos)
{
	int			pivot;
	int			i;
	int			push_counter;
	t_stack		*stk;
	
	pivot = get_pivot_element(*stack_a, pivot_pos);
	push_counter = 0;
	i = 0;
	stk = *stack_a;
	while (stk)
	{
		if (stk->data < pivot)
			stk = mv_to_b(stack_a, stack_b, &i, &push_counter);
		else
		{
			stk = stk->next;
			i++;
		}
	}
	put_pivot_in_place(stack_a, pivot);
	if (back_sorted(*stack_a, *stack_b, &pivot_pos) == 1)
		quicksort(stack_a, stack_b, pivot_pos);
	if (back_sorted(*stack_a, *stack_b, &pivot_pos) == 2)
	{
		mv_to_a(stack_a, stack_b, push_counter);
		quicksort(stack_a, stack_b, pivot_pos);
	}
}
