/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:54:12 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/05 19:58:55 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	merge(int **vct, int p, int q, int r)
{
	int		i;
	int		j;
	int		k;
	int		*b;

	b = (int *)malloc(sizeof(int) * (r + 1));
	if (b == NULL)
		exit (1);
	k = 0;
	i = p;
	j = q + 1;
	while (i <= q && j <= r)
		if ((*vct)[i] < (*vct)[j])
			b[k++] = (*vct)[i++];
	else
		b[k++] = (*vct)[j++];
	while (i <= q)
		b[k++] = (*vct)[i++];
	while (j <= r)
		b[k++] = (*vct)[j++];
	i = r;
	while (i >= p)
		(*vct)[i--] = b[--k];
	free(b);
}

void	merge_sort(int **vct, int p, int r)
{
	int		q;

	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(vct, p, q);
		merge_sort(vct, q + 1, r);
		merge(vct, p, q, r);
	}
}
