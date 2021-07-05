/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:58:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/05 20:16:53 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	sorted(t_stack *stk)
{
	while (stk->next)
	{
		if (stk->data > stk->next->data)
			return (0);
		stk = stk->next;
	}	
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int			l;

	if (sorted(*stack_a))
		return ;
	l = stacksize(*stack_a);
	if (l <= 70)
		small_algorithm(stack_a, stack_b, l);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (check_errors(ac, &av))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = (t_stack *)malloc(sizeof(t_stack));
		if (stack_a == NULL)
			exit(1);
		create_a(av, &stack_a);
	}
	sort_stack(&stack_a, &stack_b);
	return (0);
}
