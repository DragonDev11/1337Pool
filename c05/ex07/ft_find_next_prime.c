/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:54:33 by mhmichi           #+#    #+#             */
/*   Updated: 2026/09/01 15:50:24 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	return_if_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (return_if_prime(nb + 1));
	if (nb % 2 == 0 && nb != 2)
		return (return_if_prime(nb + 1));
	i = 2;
	while (i < nb)
		if (nb % i++ == 0)
			return (return_if_prime(nb + 1));
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= nb / 2)
		if (nb % i++ == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	return ft_find_next_prime(nb + 1);
}

int	ft_find_next_next_prime(int nb)
{
	int first_prime = ft_find_next_prime(nb);
	return (ft_find_next_prime(first_prime + 1));
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_find_next_next_prime(4));
	return (0);
}
