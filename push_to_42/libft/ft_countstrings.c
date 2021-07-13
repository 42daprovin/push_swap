/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstrings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:28:49 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 15:27:30 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countstrings(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != 0)
		count++;
	while (s[i])
	{
		while (s[i] == c && s[i + 1] != 0)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
				count++;
			i++;
		}
		i++;
	}
	return (count);
}
