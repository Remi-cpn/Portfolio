/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:21:46 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/19 09:55:28 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	check(int v, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == v + '0')
			return (0);
		i++;
	}
	return (1);
}

void	swap_tab(int n, int index, char *str)
{
	int	v;

	if (index == n)
	{
		printf("%s\n", str);
		return ;
	}
	v = 1;
	while (v <= n)
	{
		if (check(v, str))
		{
			str[index] = v + '0';
			swap_tab(n, index + 1, str);
			str[index] = '0';
		}
		v++;
	}
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac < 2)
	{
		write(2, "Arg ?", 5);
		return (-1);
	}
	str = calloc(atoi(av[1]) + 1, sizeof(char));
	if (!str)
		return (-1);
	swap_tab(atoi(av[1]), 0, str);
}
