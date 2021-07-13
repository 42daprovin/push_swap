/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:42:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/05 20:09:22 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	create_a(char **av, t_stack **stack_a)
{
	int			i;
	t_stack		*new;
	t_stack		*lst;

	if (ft_isdigit(*av[0]) || *av[0] == '-')
		i = 0;
	else
		i = 1;
	(*stack_a)->data = ft_atoi(av[i]);
	(*stack_a)->next = NULL;
	i++;
	lst = *stack_a;
	while (av[i] != NULL)
	{	
		new = (t_stack *)malloc(sizeof(t_stack));
		if (new == NULL)
			exit(1);
		new->data = ft_atoi(av[i]);
		new->next = NULL;
		lst->next = new;
		lst = lst->next;
		i++;
	}
}
