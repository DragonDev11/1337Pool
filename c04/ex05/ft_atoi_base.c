/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhmichi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:35:36 by mhmichi           #+#    #+#             */
/*   Updated: 2026/08/24 10:13:02 by mhmichi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_digit_base_index(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_start_index(char *str, char *base, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	if (get_digit_base_index(str[i], base) != -1)
		return (i);
	return (-1);
}

int	get_num_length(char *str, char *base)
{
	int	l;

	l = 0;
	while (*(str + get_start_index(str, base, 0)))
	{
		if (get_digit_base_index(*str, base) != -1)
			l++;
		else if (l > 0)
			return (l);
		str++;
	}
	return (l);
}

int	is_valid(char *base, int size)
{
	int	i;
	int	j;

	if (size < 2)
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

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	index;
	int	base_len;
	int	i;
	int	sign;

	nb = 0;
	base_len = 0;
	sign = 1;
	while (base[base_len])
		base_len++;
	i = get_start_index(str, base, &sign);
	if (!is_valid(base, base_len) || i == -1)
		return (0);
	while (str[i])
	{
		index = get_digit_base_index(str[i], base);
		if (index >= 0)
			nb = get_digit_base_index(str[i], base) + nb * base_len;
		else
			break ;
		i++;
	}
	return (nb * sign);
}
