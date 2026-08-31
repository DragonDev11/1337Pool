/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:12:48 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/13 16:39:07 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int i, int j)
{
	char	c;

	c = (char)((int)(i / 10) + 48);
	ft_putchar(c);
	c = (char)(i % 10 + 48);
	ft_putchar(c);
	ft_putchar(' ');
	c = (char)((int)j / 10 + 48);
	ft_putchar(c);
	c = (char)(j % 10 + 48);
	ft_putchar(c);
	if (i != 98 || j != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_numbers(i, j);
			j++;
		}
		i++;
	}
}
