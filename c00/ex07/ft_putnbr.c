/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 11:42:09 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/13 16:28:38 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	mypow(int b, int e)
{
	int	result;

	result = 1;
	while (e > 0)
	{
		result *= b;
		e--;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_calculate_nb_length(int nb)
{
	long	d;
	int		l;

	l = 1;
	d = 10;
	while ((nb % d) < nb)
	{
		d *= 10;
		l++;
	}
	return (l);
}

void	ft_putnbr(int nb)
{
	int	l;
	int	d;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	l = ft_calculate_nb_length(nb);
	d = mypow(10, l - 1);
	while (d >= 1)
	{
		ft_putchar((char)((int)(nb / d) + 48));
		nb %= d;
		d /= 10;
	}
}
