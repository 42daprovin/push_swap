/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:23:26 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/29 17:28:58 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		print_stack(t_stack *stack)
{
	t_stack *save;

	save = stack;
	while(save)
	{
		ft_printf("%d\n", save->data);
		save = save->next;
	}
}
