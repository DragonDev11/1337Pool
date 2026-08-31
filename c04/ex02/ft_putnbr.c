/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:19:59 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/20 17:38:36 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	mypower(int b, int e)
{
	int	result;

	result = 1;
	while (e-- > 0)
		result *= b;
	return (result);
}

int	calc_digits(int nb)
{
	int	l;

	l = 0;
	while (nb / 10 >= 1)
	{
		l++;
		nb /= 10;
	}
	return (l + 1);
}

int	print_digit(int digit, int *nb, int d)
{
	char	c;

	c = (char)(digit + 48);
	write(1, &c, 1);
	*nb %= d;
	return (d / 10);
}

void	ft_putnbr(int nb)
{
	long	d;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		else
			nb *= -1;
	}
	d = mypower(10, calc_digits(nb) - 1);
	while (d >= 1)
		d = print_digit(nb / d, &nb, d);
}
