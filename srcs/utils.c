/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:48:50 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 17:51:03 by daprovin         ###   ########.fr       */
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
