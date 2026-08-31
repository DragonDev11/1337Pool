/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:11:01 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/24 10:47:45 by mhmichi          ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (str[i++])
		l++;
	return (l);
}

int	is_valid(char *base)
{
	int	size;
	int	i;
	int	j;

	size = ft_strlen(base);
	if (size <= 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	magic_stuff(unsigned int nb, char *n, char *base)
{
	unsigned int	size;
	int				i;

	size = ft_strlen(base);
	i = 0;
	while (nb / size > 0)
	{
		n[i++] = base[(nb % size)];
		nb /= size;
	}
	n[i] = base[(nb % size)];
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			n[32];
	int				i;
	unsigned int	unb;

	if (!is_valid(base))
		return ;
	if (nbr < 0)
	{
		unb = -(unsigned int)nbr;
		write(1, "-", 1);
	}
	else
		unb = (unsigned int)nbr;
	i = magic_stuff(unb, n, base);
	while (i >= 0)
		write(1, &n[i--], 1);
}
