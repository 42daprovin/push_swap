/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:09:28 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 16:42:06 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*sol;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	sol = (char *)ft_calloc(sizeof(char), (l + 1));
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sol[i] = f(i, s[i]);
		i++;
	}
	return (sol);
}
