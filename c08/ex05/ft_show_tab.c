/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 09:43:40 by mhmichi           #+#    #+#             */
/*   Updated: 2026/09/01 12:55:41 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_putstr((*par).str);
		ft_putchar('\n');
		ft_putnbr((*par).size);
		ft_putchar('\n');
		ft_putstr((*par).copy);
		ft_putchar('\n');
		par++;
	}
}
