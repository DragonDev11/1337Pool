/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 19:10:42 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/23 20:04:08 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**g_grid;
int	n;

void	ft_putstr(char *str);

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
			if (j < n - 1)
				printf("%d ", g_grid[i][j]);
			else
				printf("%d\n", g_grid[i][j]);
			j++;
		}
		i++;
	}
}

void	get_cell_view(int view, int *row, int *col)
{

	if (view >= 0 && view <= (n * 2) - 1)
	{
		*col = view % n;
		if (view < n)
			*row = 0;
		else
			*row = n - 1;
	}
	else if (view >= (n * 2) && view <= (n * n) - 1)
	{
		*row = view % n;
		if (view < (n * 2) + n)
			*col = 0;
		else
			*col = n - 1;
	}
}

int	get_opposite_view(int current)
{
	if ((current / n) % n == 0)
		return current + n;
	else
		return current - n;
}

int	get_row_visibility(int *row, int *views, int view_index)
{
	int	i;
	int	count;
	int	max;

	max = 0;
	count = 0;

	if ((view_index / n) % n == 0)
	{
		i = 0;
		while (i < n)
		{
			if (row[i] > max)
			{
				count++;
				max = row[i];
			}
			i++;
		}
		ft_putstr("ROW_VISIBILITY: (-->)");
		ft_putchar(view_index + 48);
		ft_putchar('\n');
		ft_putchar(views[view_index] + 48);
		ft_putchar(' ');
		ft_putchar(count + 48);
		ft_putchar('\n');
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			if (row[i] > max)
			{
				count++;
				max = row[i];
			}
			i--;
		}
		ft_putstr("ROW_VISIBILITY: (<--)");
		ft_putchar(views[view_index]+ 48);
		ft_putchar(' ');
		ft_putchar(count + 48);
		ft_putchar('\n');
	}
	return (count);
}

int	is_valid_permutation(int *permutation, int *views, int i)
{
	if ((get_row_visibility(permutation, views, i) == views[i]) && (get_row_visibility(permutation, views, get_opposite_view(i)) == views[get_opposite_view(i)]))
		return (1);
	return (0);
}

void	swap(int *i, int *j)
{
	int	temp;
	
	temp = *i;
	*i = *j;
	*j = temp;
}

int	solve(int row)
{
	int	i;
	int	j;
	int	col[n];

	i = 0;
	if (row == n)
	{
		while (i < n)
		{
			j = n;
			while (j > 1)
			{
				if (g_grid[row - j][i] == g_grid[row - 1][i])
					return -1;
				j--;
			}
			i++;
		}
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				col[j] = g_grid[i][j];
				j++;
			}
			if (!is_valid_permutation(col, clues, j))
				return -1;
			i++;
		}
		return 0;
	}


}

int	*check_permutation(int *views, int i, int *permutation)
{
	int	row;
	int	col;
	int	bottom;
	int	tab[n];
	int	index;

	get_cell_view(i, &row, &col);
	bottom = col + n;
	if (g_grid[row][col] != 0)
	{
		if (row == 0 || row == n - 1)
			if ((views[col] == 1 && g_grid[row][col] != n) || (views[bottom] == n && g_grid[row][col] != 1))
				return (NULL);
		index = 0;
		while (index < n)
		{
			tab[index] = g_grid[index][col];
			index++;
		}
		if (views[col] != get_row_visibility(tab, views, col) || views[bottom] != get_row_visibility(tab, views, bottom))
			return (NULL);
	}
	return (permutation);
}

int	*generate_permutations(int *permutation, int start, int i, int *views)
{
	int	index;
	int	j;
	int	row;
	int	col;
	int	*perm;

	perm = NULL;
	if (start == n)
	{
		ft_putstr("For permutation ");
		for (int k = 0; k < n; k++)
		{
			ft_putchar(permutation[k] + 48);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		if (is_valid_permutation(permutation, views, i))
		{
			if (check_permutation(views, i, permutation) != NULL)
			{
				ft_putstr("\tFound permutation\n");
				get_cell_view(views[i], &row, &col);
				if ((views[i] / n) % n == 0)
				{
					j = 0;
					while (j < n)
					{
						g_grid[row][j] = permutation[j];
						j++;
					}
				}
				else
				{
					j = n - 1;
					while (j >= 0)
					{
						g_grid[row][j] = permutation[j];
						j--;
					}
				}
				return (permutation);
			}
			else
			{
				ft_putstr("\tNot valid for other columns\n");
			}
		}else{
			ft_putstr("\tNot valid for clues\n");
		}
	}
	index = start;
	while (index < n && perm == NULL)
	{
		swap(&permutation[start], &permutation[index]);
		perm = generate_permutations(permutation, start + 1, i, views);
		swap(&permutation[start], &permutation[index++]);
	}
	return (perm);
}

void	begin_doing_stuff(int *views)
{
	int	permutation[n];
	int	i;
	int	*candidate;
	
	i = 0;
	while (i < n)
	{
		permutation[i] = i + 1;
		ft_putchar(permutation[i] + 48);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < n * n)
	{
		ft_putstr("COL ");
		ft_putchar(i + 48);
		ft_putchar('\n');
		candidate = generate_permutations(permutation, 0, i, views);
		i++;
		if (candidate == NULL)
			ft_putstr("candidate is NULL\n");
	}
}

int	*parse_input(char *str)
{
	int	*input;
	int	i;

	i = 0;
	input = (int *)malloc(sizeof(int) * n * n);
	if (input == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str < '1' || *str > n + 48)
		{
			if (*str != ' ')
				return (NULL);
		}
		else
			input[i++] = (*str) - 48;
		str++;
	}
	if (i < n * n)
		return (NULL);
	return (input);
}

int	**init_grid(int size)
{
	int	i;
	int	j;
	//int	row;
	//int	col;

	i = 0;
	n = size;
	g_grid = (int **)malloc(sizeof(int *)*n);
	if (g_grid == NULL)
		return (NULL);
	while (i < n)
	{
		g_grid[i++] = (int *)malloc(sizeof(int)*n);
		if (g_grid[i - 1] == NULL)
			return (NULL);
		j = 0;
		while (j < n)
			g_grid[i - 1][j++] = 0;
	}
	/*i = 0;
	while (i < n*n)
	{
		get_cell_view(i, &row, &col);
		if (input[i] == 1)
			g_grid[row][col] = n;
		else if (input[i] == n)
			g_grid[row][col] = 1;
		i++;
	}*/
	return (g_grid);
}

int	main(int argc, char **argv)
{
	int	*input;
	n = 4;

	if (argc < 2)
	{
		ft_putstr("Missing arguments.");
		return (0);
	}
	input = parse_input(argv[1]);

	if (input == NULL)
	{
		ft_putstr("fuck it\n");
		return 0;
	}

	g_grid = init_grid(4);

	print_grid();
	begin_doing_stuff(input);
	print_grid();
	free(input);
	free(g_grid);
	return (0);
}
