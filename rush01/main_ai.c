#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	**g_grid;
int	n;

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(g_grid[i][j] + '0');
			if (j < n - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** views:
**
** 0 1 2 3       = top
** 4 5 6 7       = bottom
** 8 9 10 11     = left
** 12 13 14 15   = right
*/

int	get_visibility(int *line, int reverse)
{
	int	i;
	int	max;
	int	count;

	max = 0;
	count = 0;
	if (!reverse)
	{
		i = 0;
		while (i < n)
		{
			if (line[i] > max)
			{
				max = line[i];
				count++;
			}
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			if (line[i] > max)
			{
				max = line[i];
				count++;
			}
			i--;
		}
	}
	return (count);
}

/*
** Check the candidate against the left/right clues
** of the row we're currently filling.
*/
int	row_is_valid(int *permutation, int *views, int row)
{
	int	left;
	int	right;

	left = 2 * n + row;
	right = 3 * n + row;

	if (views[left] != 0
		&& get_visibility(permutation, 0) != views[left])
		return (0);
	if (views[right] != 0
		&& get_visibility(permutation, 1) != views[right])
		return (0);
	return (1);
}

/*
** Check whether putting this candidate in 'row'
** would create a duplicate in any column.
*/
int	permutation_fits_columns(int *permutation, int row)
{
	int	col;
	int	previous_row;

	col = 0;
	while (col < n)
	{
		previous_row = 0;
		while (previous_row < row)
		{
			if (g_grid[previous_row][col] == permutation[col])
				return (0);
			previous_row++;
		}
		col++;
	}
	return (1);
}

void	put_row(int row, int *permutation)
{
	int	col;

	col = 0;
	while (col < n)
	{
		g_grid[row][col] = permutation[col];
		col++;
	}
}

void	clear_row(int row)
{
	int	col;

	col = 0;
	while (col < n)
	{
		g_grid[row][col] = 0;
		col++;
	}
}

/*
** Check top/bottom clues once the entire grid is filled.
*/
int	columns_are_valid(int *views)
{
	int	col;
	int	row;
	int	line[n];

	col = 0;
	while (col < n)
	{
		row = 0;
		while (row < n)
		{
			line[row] = g_grid[row][col];
			row++;
		}

		if (views[col] != 0
			&& get_visibility(line, 0) != views[col])
			return (0);

		if (views[n + col] != 0
			&& get_visibility(line, 1) != views[n + col])
			return (0);

		col++;
	}
	return (1);
}

int	solve(int row, int *views, int *permutation, int start)
{
	int	i;

	/*
	** Every row has been filled.
	** Now check the top/bottom clues.
	*/
	if (row == n)
		return (columns_are_valid(views));

	/*
	** Generate every permutation of 1..n.
	*/
	if (start == n)
	{
		/*
		** Does this permutation satisfy this row's clues?
		*/
		if (!row_is_valid(permutation, views, row))
			return (0);

		/*
		** Does it conflict with rows already placed?
		*/
		if (!permutation_fits_columns(permutation, row))
			return (0);

		/*
		** Candidate is good so far.
		*/
		put_row(row, permutation);

		/*
		** Now solve the NEXT row.
		*/
		if (solve(row + 1, views, permutation, 0))
			return (1);

		/*
		** The next row eventually failed.
		** Undo this candidate and try another permutation.
		*/
		clear_row(row);

		return (0);
	}

	/*
	** Generate permutations recursively.
	*/
	i = start;
	while (i < n)
	{
		swap(&permutation[start], &permutation[i]);

		if (solve(row, views, permutation, start + 1))
			return (1);

		swap(&permutation[start], &permutation[i]);
		i++;
	}
	return (0);
}

int	*parse_input(char *str)
{
	int	*views;
	int	i;

	i = 0;
	views = malloc(sizeof(int) * n * n);
	if (views == NULL)
		return (NULL);

	while (*str)
	{
		if (*str >= '1' && *str <= '0' + n)
			views[i++] = *str - '0';
		else if (*str != ' ')
		{
			free(views);
			return (NULL);
		}
		str++;
	}

	if (i != n * n)
	{
		free(views);
		return (NULL);
	}
	return (views);
}

int	**init_grid(void)
{
	int	i;
	int	j;

	g_grid = malloc(sizeof(int *) * n);
	if (g_grid == NULL)
		return (NULL);

	i = 0;
	while (i < n)
	{
		g_grid[i] = malloc(sizeof(int) * n);
		if (g_grid[i] == NULL)
			return (NULL);

		j = 0;
		while (j < n)
		{
			g_grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (g_grid);
}

int	main(int argc, char **argv)
{
	int	*views;
	int	permutation[n];
	int	i;

	n = 4;

	if (argc != 2)
		return (1);

	views = parse_input(argv[1]);
	if (views == NULL)
		return (1);

	if (init_grid() == NULL)
		return (1);

	i = 0;
	while (i < n)
	{
		permutation[i] = i + 1;
		i++;
	}

	if (solve(0, views, permutation, 0))
		print_grid();
	else
		ft_putstr("Error\n");

	i = 0;
	while (i < n)
		free(g_grid[i++]);
	free(g_grid);
	free(views);

	return (0);
}
