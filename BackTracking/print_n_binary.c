/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:46:58 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 11:17:13 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	algo(int n, int index, char *str)
{
	if (index == n)
	{
		printf("%s\n", str);
		return ;
	}
	str[index] = '0';
	algo(n, index + 1, str);
	str[index] = '1';
	algo(n, index + 1, str);
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
	algo(atoi(av[1]), 0, str);
	free(str);
	str = NULL;
}
