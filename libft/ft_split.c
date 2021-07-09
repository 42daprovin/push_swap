/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:13:17 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 16:35:48 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = ft_countstrings(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	split[count] = NULL;
	if (ft_doingmalloc(split, s, c) == 1)
		return (NULL);
	ft_fillstr(split, s, c);
	return (split);
}
