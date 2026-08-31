/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:04:38 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 12:57:39 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (nb * sign);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	density;
	int	i;
	int	j;

	if (argc < 4)
	{
		ft_putstr("Error: Too few arguments.\n");
		return (0);
	}
	else if (argc > 4)
	{
		ft_putstr("Error: Too many arguments.\n");
		return (0);
	}

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	density = ft_atoi(argv[3]);
	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (rand() % (y * 2) < density)
				ft_putchar('o');
			else
				ft_putchar('.');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	return (0);
}
