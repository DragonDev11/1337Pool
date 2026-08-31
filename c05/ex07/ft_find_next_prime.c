/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:54:33 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/25 14:29:02 by mhmichi          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	return (return_if_prime(nb));
}
