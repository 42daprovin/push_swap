/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:40:01 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 15:37:27 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_lst;
	t_list	*f_lst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp_lst = lst;
	f_lst = ft_lstnew(f(tmp_lst->content));
	if (!f_lst)
		return (NULL);
	tmp_lst = tmp_lst->next;
	while (tmp_lst)
	{
		tmp = ft_lstnew(f(tmp_lst->content));
		if (!tmp)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&f_lst, tmp);
		tmp_lst = tmp_lst->next;
	}
	return (f_lst);
}
