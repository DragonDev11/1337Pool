/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:59:15 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/26 12:13:17 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define N 10

char	g_board[N][N];

int	absolute_value(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_cell_valid(int row, int col)
{
	int	col_index;
	int	row_index;

	col_index = 0;
	row_index = row - 1;
	while (row_index >= 0)
	{
		col_index = 0;
		while (col_index < N)
		{
			if ((g_board[row_index][col_index] == 'Q'
				&& (col_index == col
					|| absolute_value(col_index - col) == row - row_index))
						|| g_board[row][col] == 'X')
				return (0);
			col_index++;
		}
		row_index--;
	}
	return (1);
}
/*
void	print_board()
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%c", g_board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_board()
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			g_board[i][j] = '-';
			j++;
		}
		i++;
	}
}
*/

char	*if_last_row(char *solution, int *num_solutions)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (g_board[i][j] == 'Q')
			{
				solution[i] = j + 48;
				break ;
			}
			j++;
		}
		i++;
	}
	solution[i] = '\0';
	write(1, solution, 10);
	write(1, "\n", 1);
	(*num_solutions)++;
	return (solution);
}

char	*solve(int row, char *solution, int *num_solutions)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	if (row == N)
		return (if_last_row(solution, num_solutions));
	while (col < N)
	{
		if (is_cell_valid(row, col))
		{
			g_board[row][col] = 'Q';
			solve(row + 1, solution, num_solutions);
			g_board[row][col] = 'X';
		}
		col++;
	}
	i = 0;
	while (i < N)
		g_board[row][i++] = '-';
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int		solutions;
	char	solution[N + 1];

	solutions = 0;
	solve(0, solution, &solutions);
	return (solutions);
}
/*
int	main(void)
{
	printf("Solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
