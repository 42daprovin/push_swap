/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:58:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/28 23:17:54 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	ft_atoi(av[1]);
	if (ac > 1)
	{
		if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
			exit(1);
		create_a(av, &stack_a);
	}
}
