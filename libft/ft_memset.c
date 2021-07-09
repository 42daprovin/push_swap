/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:21:47 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 15:50:54 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	a;
	size_t	i;

	a = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*((unsigned char *)(b + i)) = a;
		i++;
	}
	return (b);
}
