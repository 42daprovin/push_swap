/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:58:31 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/03 23:41:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int			*set_vct(t_stack *stk, int *l)
{
	int		i;
	int		*vct;

	*l = stacksize(stk);
	if (!(vct = (int*)malloc((sizeof(int) * (*l)))))
		exit(1);
	i = 0;
	while (stk)
	{
		vct[i] = stk->data;
		i++;
		stk = stk->next;
	}
	return (vct);
}

void		sort_vct(int **vct, int l)
{
	int		save;
	int		i;
	int		j;

	i = 0;
	while (i < l)
	{
		j = i;
		while (j <  l)
		{
			if ((*vct)[i] > (*vct)[j])
			{
				save = (*vct)[i];
				(*vct)[i] = (*vct)[j];
				(*vct)[j] = save;
			}
			j++;
		}
		i++;	
	}
}

void		simplify_numbers(int * vct, t_stack **stack_a, int l)
{
	t_stack	*stk;
	int		i;

	stk = *stack_a;
	while (stk)
	{
		i = 0;
		while (i < l)
		{
			if (stk->data == vct[i])
			{
				stk->data = i;
				break ;  
			}
			i++;
		}
		stk = stk->next;
	}
}

void		radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		*vct;
	int		l;
	int		j;
	int		i;

	vct = set_vct(*stack_a, &l);
	/* sort_vct(&vct, l); */
	merge_sort(&vct, 0, l - 1);
	simplify_numbers(vct, stack_a, l);
	i = 0;
	while (!(sorted(*stack_a)))
	{
		j = 0;
		while (j < l)
		{
			if ((((*stack_a)->data >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
