/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:23:02 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/19 10:42:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * This fonction free all alocations.
 */
static void	free_all(char **chessboard, char *str)
{
	int	i;

	free(str);
	str = NULL;
	i = 0;
	while (chessboard[i])
	{
		free(chessboard[i]);
		chessboard[i] = NULL;
		i++;
	}
	free(chessboard);
	chessboard = NULL;
}

/**
 * This fonction write a string on fd 1.
 */
static void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

/**
 * This fonction control the queen precence on the line, the column and diagonals
 * from a position in array.
 */
static int	clues(int y, int x, char **chessboard, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (chessboard[y][i] == '1' || chessboard[i][x] == '1')
			return (0);
		i++;
	}
	i = 1;
	while (i <= y)
	{
		if (x + i < n && chessboard[y - i][x + i] == '1')
			return (0);
		if (x - i >= 0 && chessboard[y - i][x - i] == '1')
			return (0);
		i++;
	}
	return (1);
}

/**
 * This recursive backtracking fonction browes line by line and return 
 * all solutions.
 */
static int	algo(int y, char **chessboard, char	*str, int n)
{
	int			x;
	static int	count = 0;

	if (y > n - 1)
	{
		putstr(str);
		return (count++);
	}
	x = 0;
	while (x < n)
	{
		if (clues(y, x, chessboard, n))
		{
			chessboard[y][x] = '1';
			str[y] = x + 48;
			algo(y + 1, chessboard, str, n);
			chessboard[y][x] = '0';
		}
		x ++;
	}
	return (count);
}

/**
 * This fonction is the main fonction.
 */
int	ft_n_queens_puzzle(int n)
{
	char	**chessboard;
	int		i;
	int		y;
	int		count;
	char	*str;

	chessboard = calloc(n + 1, sizeof(char *));
	i = 0;
	while (i < n)
	{
		chessboard[i] = calloc(n + 1, sizeof(char));
		i++;
	}
	str = calloc(n + 1, sizeof(char));
	y = 0;
	count = algo(y, chessboard, str, n);
	free_all(chessboard, str);
	return (count);
}
/**
#include <stdio.h>

int	main(int ac, char **av)
{
	int	count;

	if (ac == 1)
	{
		write(2, "Arg ?", 5);
		return (-1);
	}
	count = ft_n_queens_puzzle(atoi(av[1]));
	printf("-> Nombre de solutions = >%d<\n", count);
}*/

