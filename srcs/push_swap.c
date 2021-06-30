/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:58:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/30 19:08:32 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	/* check_errors(ac, av); */
	if (ac > 1)
	{
		stack_b = NULL;
		if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
			exit(1);
		create_a(av, &stack_a);
	}
	quicksort(&stack_a, &stack_b, 0);
	print_stack(stack_a);
	ft_printf("B\n");
	print_stack(stack_b);
}
