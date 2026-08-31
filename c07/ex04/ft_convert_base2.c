/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:19:22 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/30 14:04:16 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_array(char c, char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	dec_num_length(int nbr)
{
	int	l;

	l = 0;
	while (nbr / 10 > 0)
	{
		l++;
		nbr /= 10;
	}
	return (l);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str)
	{
		l++;
		str++;
	}
	return (l);
}

int	get_start_index(char *nbr, char *base, int *sign)
{
	int	i;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*sign = -(*sign);
		i++;
	}
	if (is_in_array(nbr[i], base) > -1)
		return (i);
	return (-1);
}
