/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:49:41 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/02 18:22:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * This backtracking fonction check all possibility.
 */
int	algo(char *grid[8], int y, int x, int flag)
{
	if (x == 7 || y == 7)
		return (0);
	if (grid[y][x] == '1')
		return (0);
	if ((y == 6 || x == 6) && grid[y][x] == '0')
		return (1);
	if (flag != 2 && algo(grid, y, x + 1, 1))
		return (1);
	else if (flag != 1 && x < 0 && algo(grid, y, x - 1, 2))
		return (1);
	else if (flag != 4 && algo(grid, y + 1, x, 3))
		return (1);
	else if (flag != 3 && y < 0 && algo(grid, y - 1, x, 4))
		return (1);
	return (0);
}

/**
 * This fonction work with only grid size 7x7
 */
int	maze_solver(char *grid[8])
{
	int	check;

	check = algo(grid, 0, 1, 0);
	return (check);
}

#include <stdio.h>

int	main(void)
{
	char	*grid[8];
	int		check;

	grid[0] = "1011111";
	grid[1] = "1000101";
	grid[2] = "1110101";
	grid[3] = "1000001";
	grid[4] = "1011100";
	grid[5] = "1000101";
	grid[6] = "1111111";
	check = maze_solver(grid);
	printf("Check = %d\n", check);
}
