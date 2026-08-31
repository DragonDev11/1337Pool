/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 22:15:05 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/31 09:27:21 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_array(char c, char *array);
int	dec_num_length(int nbr);
int	ft_strlen(char *str);
int	get_start_index(char *nbr, char *base, int *sign);

int	based_num_length(char *nbr, char *base, int start)
{
	int	l;

	l = 0;
	while (start < ft_strlen(nbr))
	{
		if (is_in_array(nbr[start], base) > -1)
			l++;
		else
			break ;
		start++;
	}
	return (l);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32 || base[i] == '+'
			|| base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	to_decimal(char *nbr, char *base)
{
	int	base_len;
	long	result;
	int	start;
	int	sign;

	base_len = ft_strlen(base);
	result = 0;
	sign = 1;
	start = get_start_index(nbr, base, &sign);
	while (*(nbr + start))
	{
		result = result * base_len + is_in_array(*(nbr + start), base);
		start++;
	}
	return (result * sign);
}

int	to_base(long nbr, char *base, char **n)
{
	int				base_len;
	int				i;
	unsigned long	unbr;

	i = 0;
	if (nbr == 0)
		(*n)[i++] = '0';
	base_len = ft_strlen(base);
	unbr = nbr;
	if (nbr < 0)
		unbr = -(unsigned long)nbr;
	while (i < 32 && unbr > 0)
	{
		(*n)[i] = base[unbr % base_len];
		unbr /= base_len;
		i++;
	}
	if (nbr < 0)
		(*n)[i++] = '-';
	(*n)[i] = '\0';
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	char	n[34];
	char	*p;
	int		size;
	int		i;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	p = n;
	size = to_base(to_decimal(nbr, base_from), base_to, &p);
	result = (char *)malloc(size);
	if (result == NULL)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		result[size - i - 1] = p[i];
		i--;
	}
	result[size - i - 1] = '\0';
	return (result);
}
