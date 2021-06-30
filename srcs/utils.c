/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:48:50 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/30 16:40:41 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		stacksize(t_stack *stack)
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

int		get_pivot_element(t_stack *stack, int pivot_pos)
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
