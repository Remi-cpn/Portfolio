/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teen_queens_stud.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:23:02 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 12:37:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
void	ft_init_chessboard(char chessboard[11][11])
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			chessboard[y][x] = '.';
			x++;
		}
		chessboard[y][x] = '\0'; 
		y++;
	}
}

/**
 * This fonction control the queen precence on the line, the column and diagonals
 * from a position in array.
 */
int	clues(int y, int x, char chessboard[11][11])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if(chessboard[y][i] == '1' || chessboard[i][x] == '1')
			return (0);
		i++;
	}
	i = 1;
	while (i <= y)
	{
		if (x + i < 10 && chessboard[y - i][x + i] == '1')
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
int	algo(int y, char chessboard[11][11], char	*str)
{
	int	x;
	static int count = 0;

	if (y > 9)
	{
		putstr(str);
		return (count++);
	}
	x = 0;
	while (x < 10)
	{
		if (clues(y, x, chessboard))
		{
			chessboard[y][x] = '1';
			str[y] = x + 48;
			algo(y + 1, chessboard, str);
			chessboard[y][x] = '0';
		}
		x ++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	chessboard[11][11];
	int		y;
	int		count;
	char	str[11];

	ft_init_chessboard(chessboard);
	y = 0;
	str[0] = '\0';
	count = algo(y, chessboard, str);
	return (count);
}
/**
int	main(void)
{
	int	count;

	count = ft_ten_queens_puzzle();
	printf("-> Nombre de solutions = >%d<", count);
}
*/
