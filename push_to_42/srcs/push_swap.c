/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:58:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/13 16:44:34 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	doing_free(t_stack **a, char ***av, int ac)
{
	int		i;
	t_stack	*tmp;

	if (ac == 2)
	{
		i = 0;
		while ((*av)[i])
		{
			free((*av)[i]);
			i++;
		}
		free(*av);
	}	
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

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

	if (ac == 1)
		return (0);
	if (check_errors(ac, &av))
	{
		write(2, "Error\n", 6);
		return (1);
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
	doing_free(&stack_a, &av, ac);
	return (0);
}
