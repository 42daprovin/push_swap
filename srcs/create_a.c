/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:42:27 by daprovin          #+#    #+#             */
/*   Updated: 2021/06/28 23:13:36 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	create_a(char **av, t_stack **stack_a)
{
	int			i;
	t_stack		*new;
	t_stack		*lst;

	(*stack_a)->data = ft_atoi(av[1]);
	(*stack_a)->next = NULL;
	i = 2;
	lst = *stack_a;
	while (av[i] != NULL)
	{	
		if (!(new = (t_stack*)malloc(sizeof(t_stack))))
			exit(1);
		new->data = ft_atoi(av[i]);
		new->next = NULL;
		lst->next = new;
		lst = lst->next;
		i++;
	}
}
