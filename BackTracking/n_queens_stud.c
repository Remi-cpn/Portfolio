/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_stud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:23:02 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 22:31:19 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * This fonction write a string on fd 1.
 */
void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

/**
 * This fonction init array.
 */
char	**ft_init_chessboard(int n)
{
	int		i;
	char	**chessboard;

	chessboard = malloc(sizeof(char*) * (n + 1));
	if (!chessboard)
		return (NULL);
	i = 0;
	while (i < n)
	{
		chessboard[i] = calloc(n + 1, sizeof(char));
		if (!chessboard)
		{
			while(i >= 0)
			{
				free(chessboard[i]);
				chessboard[i] = NULL;
				i--;
			}
			free(chessboard);
			chessboard = NULL;
			return (NULL);
		}
		i++;
	}
	chessboard[i] = NULL;
	return (chessboard);
}

/**
 * This fonction control the queen precence on the line, the column and diagonals
 * from a position in array.
 */
int	clues(int y, int x, char **chessboard, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if(chessboard[y][i] == '1' || chessboard[i][x] == '1')
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
 * This recursive backtracking fonction browes line by line and return all solutions.
 */
int	algo(int y, char **chessboard, char	*str, int n)
{
	int	x;
	static int count = 0;

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

#include <stdio.h>

int	ft_n_queens_puzzle(int n)
{
	char	**chessboard;
	int		i;
	int		count;
	char	*str;

	str = calloc(n + 1, sizeof(char));
	if (!str)
		return (-1);
	chessboard = ft_init_chessboard(n);
	if (chessboard)
	{
		count = algo(0, chessboard, str, n);
		i = n;
		while(i >= 0)
		{
			free(chessboard[i]);
			chessboard[i--] = NULL;
		}
		free(chessboard);
		chessboard = NULL;
	}
	free(str);
	str = NULL;
	return (count);
}

int	main(void)
{
	int			count;
	const int	n = 11;

	count = ft_n_queens_puzzle(n);
	printf("-> Nombre de solutions = >%d<\n", count);
}

