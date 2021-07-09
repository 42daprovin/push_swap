/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:43:53 by daprovin          #+#    #+#             */
/*   Updated: 2021/07/09 17:11:10 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static char	**change_av(char *str)
{
	char	**av;

	av = ft_split(str, ' ');
	if (!av)
		exit(1);
	return (av);
}

static int	not_int(char *av)
{
	int		neg;
	int		i;

	neg = 0;
	if (*av == '-')
	{
		neg = 1;
		av++;
	}
	if (ft_strlen(av) > 10)
		return (1);
	if (ft_strlen(av) < 10)
		return (0);
	if (neg == 1)
		if (ft_strcmp(av, "2147483648") > 0)
			return (1);
	if (neg == 0)
		if (ft_strcmp(av, "2147483647") > 0)
			return (1);
	return (0);
}

static int	check_numbers(char **av)
{
	int		i;
	int		j;

	if (ft_isdigit(*av[0]) || *av[0] == '-')
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || (j == 0 && av[i][j] == '-')))
				return (1);
			j++;
		}
		if (not_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicates(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (i != j && ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int ac, char ***av)
{
	if (ac == 1)
		return (1);
	if (ac == 2)
		*av = change_av((*av)[1]);
	if (check_numbers(*av))
		return (1);
	if (check_duplicates(*av))
		return (1);
	return (0);
}
